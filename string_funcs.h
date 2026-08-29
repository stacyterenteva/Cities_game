#ifndef STRING_FUNCS_H
#define STRING_FUNCS_H

#include "constants.h"

int my_strlen(const char* string);
int last_char_num(const char* string);
void my_getline(char* string, unsigned int max_len);

void slow_print(const char string[]);
void clean_buf();
bool is_strings_equal(const char* first_string, const char* second_string);
void copy_char_array(const char* old_string, char* new_string);


#endif
