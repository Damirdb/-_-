#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

void tilda()
{
    int c;
    do
    {
        c = mygetch();
    }
    while (c != '~');
}

int press_key()
{
    int start_char = mygetch();
    if (start_char == '[')
	{
		int ch = mygetch();
		if (ch == '2')
		{
            char second = mygetch();
            if (second == '~')
                return 1;
			tilda();
		}
		else if (isdigit(ch))
		{
			tilda();
		}
	}
	else
	{
		char c = mygetch();
		if (isdigit(c)) mygetch();
	}
    
    return 0;
}

int main()
{
    while (1)
    {
        char c;
        c = mygetch();
        if (iscntrl(c))
        {
            if (c == 27)
            {
                int result = press_key();
                if (result == 1) break;
            }
        }
        else
        {
            if (isalnum(c))
            {
                printf("%d\n", c);
            }
            else
                putc(c, stdout);
        }
    }
    printf("\n");
    return 0;
}

// ESC [ A
// ESC [ 0 0 ~


