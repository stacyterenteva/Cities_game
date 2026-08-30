#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "string_funcs.h"
#include "constants.h"

void slow_print(const char* string)
{
    assert(string);

    for (int i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
        Sleep(SLOW_PRINT_SLEEP);
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

int last_char_num(const char* string)
{
    assert(string);

    int i = 0;
    for (i = 0; string[i] != '\0'; i++) {
        ;
    }
    if (string[i - 1] != 'ü' && string[i - 1] != 'ú' && string[i - 1] != 'û' && string[i - 1] != 'é') {
        return i - 1;
    }
    else {
        return i - 2;
    }
}

void clean_buf()
{
    while (getchar() != '\n') {
        ;
    }
}

void copy_char_array(const char* old_string, char* new_string)
{
    for (int i = 0; i < my_strlen(old_string) + 1; i++) {
        new_string[i] = old_string[i];
    }
}


void my_getline(char* string, unsigned int max_len)
{
    assert(string);

    unsigned int i = 0;
    int c = getchar();
    while (i < max_len && c != '\n') {
        string[i] = (char)c;
        i++;
        c = getchar();
    }
    string[i] = '\0';
}

void string_to_lower(char* old_string, char* new_string)
{
    assert(old_string);
    assert(new_string);

    for (int i = 0; old_string[i] != '\0'; i++) {
        new_string[i] = (char) tolower(old_string[i]);
    }
}


