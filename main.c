#include <stdio.h>
#include <conio.h>

#define _WIN32_WINNT 0x0500
#include <windows.h>

#define FILENAME "log.txt"

void logToFile(char *key)
{
    FILE *f = fopen(FILENAME, "a");

    switch(*key)
    {
        case 13: fprintf(f, "\n"); break;
        case 27: exit(0);
        default: fprintf(f, "%c", *key);
    }
}
int main()
{
    char key;

    while(1)
    {
        if(kbhit())
        {
            key = getch();
            logToFile(&key);
        }
    }
    return 0;
}
