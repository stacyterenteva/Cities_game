#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include "constants.h"

int my_strlen(char* string);
int last_char_num(char* string);

void slow_print(const char string[]);
void clean_buf();
bool is_strings_equal(char* first_string, char* second_string);
void copy_char_array(char* old_string, char* new_string);


#endif
