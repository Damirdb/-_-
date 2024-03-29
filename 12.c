#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


char* saveGets(char* buffer, int n, FILE* fp) {
    char* res = fgets(buffer, n, fp);
    int len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        fflush(fp);
    }
    return res;
}


typedef struct IntercityBus_ {
    int number;
    char departure[30];
    char destination[30];
    char departure_time[20];
    char arrival_time[20];
} IntercityBus;


void inputBus(IntercityBus* bus) {
    printf("Номер -> ");
    scanf("%d", &bus->number);
    fflush(stdin);
    printf("Отправление  -> ");
    saveGets(bus->departure, 30, stdin);
    printf("Время отправления -> ");
    saveGets(bus->departure_time, 20, stdin);
    printf("Место назначения -> ");
    saveGets(bus->destination, 30, stdin);
    printf("Время прибытия -> ");
    saveGets(bus->arrival_time, 20, stdin);
}


int readBus(IntercityBus* bus, FILE* fp) {
    if (fscanf(fp, "%d", &bus->number) < 0) {
        return 0;
    }
    saveGets(bus->departure, 30, fp);
    saveGets(bus->departure, 30, fp);
    saveGets(bus->departure_time, 20, fp);
    saveGets(bus->destination, 30, fp);
    saveGets(bus->arrival_time, 20, fp);
    return 1;
}


void writeBus(IntercityBus* bus, FILE* fp) {
    fprintf(fp, "%d\n", bus->number);
    fprintf(fp, "%s\n", bus->departure);
    fprintf(fp, "%s\n", bus->departure_time);
    fprintf(fp, "%s\n", bus->destination);
    fprintf(fp, "%s\n", bus->arrival_time);
}


void printMenu() {
    printf("1. Добавить запись\n");
    printf("2. Удалить запись\n");
    printf("3. Показать все записи\n");
    printf("4. Показать назначение записей\n");
    printf("0. Выход\n");
    printf("-> ");
}


int addBus(IntercityBus* buses, int n) {
    printf("\nВвод информации о автобусе\n");
    inputBus(buses + n);
    printf("\nДобавлена запись\n\n");
    return n + 1;
}


int deleteBus(IntercityBus* buses, int n) {
    if (n == 0) {
        printf("\nСписок автобусов пуст!\n\n");
        return n;
    }
    int index, i;

    printf("\nВходной номер удален (1, %d) -> ", n);
    scanf("%d", &index);
    --index;
    if (index < 0 || index >= n) {
        printf("Неправильный номер\n\n");
        return n;
    }

    for (i = index; i + 1 < n; ++i) {
        buses[i] = buses[i + 1];
    }
    printf("Запись удалена\n\n");
    return n - 1;
}


void printBuses(IntercityBus* buses, int n) {
    if (n == 0) {
        printf("\nСписок автобусов пуст!\n\n");
        return;
    }
    int i;
    printf("\nАвтобусы\n");
    printf("| %2s | %7s | %20s | %20s | %20s | %20s |\n",
           "#",
           "Номер",
           "Отправление",
           "Место назначения",
           "Время отправления",
           "Время прибытия"
    );
    for (i = 0; i < n; ++i) {
        printf("| %2d | %7d | %20s | %20s | %20s | %20s |\n",
               i + 1,
               buses[i].number,
               buses[i].departure,
               buses[i].destination,
               buses[i].departure_time,
               buses[i].arrival_time
        );
    }
    printf("\n");
}


void printByDestination(IntercityBus* buses, int n) {
    if (n == 0) {
        printf("\nСписок автобусов пуст!\n\n");
        return;
    }
    char destination[30];
    int i, cnt = 0;

    printf("\nПункт назначения -> ");
    saveGets(destination, 30, stdin);

    for (i = 0; i < n; ++i) {
        if (strcmp(destination, buses[i].destination) == 0) {
            break;
        }
    }
    if (i == n) {
        printf("Нет автобусов с пунктом назначения '%s'\n\n", destination);
        return;
    }
    printf("Автобусы\n");
    printf("| %2s | %7s | %20s | %20s | %20s | %20s |\n",
           "#", "Номер", "Отправление", "Место назначения",
           "Время отправления", "Время прибытия");
    for (; i < n; ++i) {
        if (strcmp(destination, buses[i].destination) != 0) {
            continue;
        }
        ++cnt;
        printf("| %2d | %7d | %20s | %20s | %20s | %20s |\n",
               cnt,
               buses[i].number,
               buses[i].departure,
               buses[i].destination,
               buses[i].departure_time,
               buses[i].arrival_time
        );
    }
    printf("\n");

}


int restoreFromFile(IntercityBus* buses, char* filename) {
    FILE* fp = fopen(filename, "r");
    int i = 0;
    if (fp == NULL) {
        return 0;
    }
    while (readBus(buses + i, fp)) {
        ++i;
    }
    fclose(fp);
    return i;
}


void saveInFile(IntercityBus* buses, int n, char* filename) {
    FILE* fp = fopen(filename, "w");
    int i;
    for (i = 0; i < n; ++i) {
        writeBus(buses + i, fp);
    }
    fclose(fp);
}


int main() {
    IntercityBus buses[128];
    int nbuses = 0;
    int command;
    char filename[] = "data.txt";

    nbuses = restoreFromFile(buses, filename);

    do {
        printMenu();
        scanf("%d", &command);
        fflush(stdin);

        switch(command) {
        case 1:
            nbuses = addBus(buses, nbuses);
            break;
        case 2:
            nbuses = deleteBus(buses, nbuses);
            break;
        case 3:
            printBuses(buses, nbuses);
            break;
        case 4:
            printByDestination(buses, nbuses);
            break;
        case 0:
            printf("\nДосвидание\n");
            break;
        default:
            printf("\nНеверная команда!\n\n");
            break;
        }

    } while (command != 0);

    saveInFile(buses, nbuses, filename);

    return 0;
}
