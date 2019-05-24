#include <stdio.h>
#include <conio.h>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#define FILENAME "log.txt"

int main()
{
    char key;

    while(1)
    {
        if(kbhit())
        {
            key = getch();
        }
    }
    return 0;
}
