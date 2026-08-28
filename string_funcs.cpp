#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <assert.h>

#include "string_funcs.h"
#include "constants.h"

void slow_print(const char* string)
{
    assert(string);

    for (int i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
        Sleep(SLOW_PRINT_Sleep);
    }
}

int my_strlen(const char* string)
{
    assert(string);

    int i = 0;
    for (i = 0; string[i] != '\0'; i++) {
        ;
    }
    return i;
}

bool is_strings_equal(const char* first_string, const char* second_string)
{
    assert(first_string);
    assert(second_string);

    if (my_strlen(first_string) != my_strlen(second_string)) {
        return false;
    }
    bool equal_flag = true;
    int i = 0;
    for (i = 0; first_string[i] != '\0'; i++) {
        if (first_string[i] != second_string[i]) {
            equal_flag = 0;
            break;
        }
    }
    return equal_flag;
}

int last_char_num(char* string)
{
    assert(string);

    int i = 0;
    for (i = 0; string[i] != '\0'; i++) {
        ;
    }
    if (string[i - 1] != 'ü' && string[i - 2] != 'ú' && string[i - 3] != 'û' && string[i - 4] != 'é') {
        return i - 1;
    }
    else {
        return i - 2;
    }
}

