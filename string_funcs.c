#include <TXLib.h>
#include <stdio.h>

#include "string_funcs.h"

void slow_print(const char string[])
{
    for (int i = 0; i < my_strlen(string); i++) {
        putchar(string[i]);
        txSleep(40);
    }
}

int my_strlen(const char* string)
{   int i = 0;
    for (i = 0; string[i] != EOF && string[i] != '\0'; i++) {
        ;
    }
    return i;
}

