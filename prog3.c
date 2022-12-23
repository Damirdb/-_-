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
    printf("Number -> ");
    scanf("%d", &bus->number);
    fflush(stdin);
    printf("Departure -> ");
    saveGets(bus->departure, 30, stdin);
    printf("Departure time -> ");
    saveGets(bus->departure_time, 20, stdin);
    printf("Destination -> ");
    saveGets(bus->destination, 30, stdin);
    printf("Arrival time -> ");
    saveGets(bus->arrival_time, 20, stdin);
}


void printMenu() {
    printf("1. Add record\n");
    printf("2. Delete record\n");
    printf("3. Show all records\n");
    printf("4. Show records destination\n");
    printf("0. Exit\n");
    printf("-> ");
}


int addBus(IntercityBus* buses, int n) {
    printf("\nEnter information about bus\n");
    inputBus(buses + n);
    printf("\nRecord added\n\n");
    return n + 1;
}


int deleteBus(IntercityBus* buses, int n) {
    if (n == 0) {
        printf("\nList of bused is empty!\n\n");
        return n;
    }
    int index, i;

    printf("\nEnter number to delete (1, %d) -> ", n);
    scanf("%d", &index);
    --index;
    if (index < 0 || index >= n) {
        printf("Incorect number\n\n");
        return n;
    }

    for (i = index; i + 1 < n; ++i) {
        buses[i] = buses[i + 1];
    }
    printf("Record deleted\n\n");
    return n - 1;
}


void printBuses(IntercityBus* buses, int n) {
    if (n == 0) {
        printf("\nList of bused is empty!\n\n");
        return;
    }
    int i;
    printf("\nBuses\n");
    printf("| %2s | %7s | %20s | %20s | %20s | %20s |\n",
           "#",
           "Number",
           "Departure",
           "Destination",
           "Depart time",
           "Arrival time"
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
        printf("\nList of bused is empty!\n\n");
        return;
    }
    char destination[30];
    int i, cnt = 0;

    printf("\nEnter destination -> ");
    saveGets(destination, 30, stdin);

    for (i = 0; i < n; ++i) {
        if (strcmp(destination, buses[i].destination) == 0) {
            break;
        }
    }
    if (i == n) {
        printf("No buses with destination '%s'\n\n", destination);
        return;
    }
    printf("Buses\n");
    printf("| %2s | %7s | %20s | %20s | %20s | %20s |\n",
           "#", "Number", "Departure", "Destination",
           "Depart time", "Arrival time");
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


int main() {
    IntercityBus buses[128];
    int nbuses = 0;

    int command;
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
            printf("\nBye\n");
            break;
        default:
            printf("\nWrong command!\n\n");
            break;
        }

    } while (command != 0);

    return 0;
}
