#include <assert.h>
#include <stdio.h>
#include <ctype.h>

#include "constants.h"
#include "play_engine.h"
#include "string_funcs.h"

unsigned char found_answer(City user_city, City* cities)
{
    assert(cities);

    int i = 0;
    for (i = 0; i < NUM_OF_CITIES; i++) {
        if (user_city.last_letter == cities[i].first_letter) {
            unsigned char program_city_last_letter = cities[i].last_letter;
            printf("%s\n", cities[i].city_name);
            cities[i] = City {.first_letter = '\0', .city_name = {}, .last_letter = '\0'};
            return program_city_last_letter;
        }
    }
    return 0;
}



void delete_city_from_memory(char* user_city, City* cities)
{
    assert(user_city);
    assert(cities);
    char lower_user_city_name[MAX_NUM_OF_CHARS] = {};
    string_to_lower(user_city, lower_user_city_name);

    for (int i = 0; i < NUM_OF_CITIES; i++) {
        char lower_program_city_name[MAX_NUM_OF_CHARS] = {};
        string_to_lower(cities[i].city_name, lower_program_city_name);

        if (is_strings_equal(lower_user_city_name, lower_program_city_name)) {
            cities[i] = City {.first_letter = '\0', .city_name = {}, .last_letter = '\0'};
            return ;
        }
    }
}

void get_city(FILE* cities_base, char* city_name)
{

    assert(city_name);

    char ch = 0;
    int i = 0;
    while (i < MAX_NUM_OF_CHARS && (ch = (char) fgetc(cities_base)) != ';') {
        city_name[i] = ch;
        i++;
    }
    fgetc(cities_base);
}

bool is_city_real(char* user_city_name, City* cities)
{
    assert(user_city_name);
    assert(cities);

    //char lower_user_city_name[my_strlen(user_city_name)] = {}; //NOTE тут нужна динамическая память?

    char lower_user_city_name[MAX_NUM_OF_CHARS] = {};

    string_to_lower(user_city_name, lower_user_city_name);

    for (int i = 0; i < NUM_OF_CITIES; i++) {
        char lower_program_city_name[MAX_NUM_OF_CHARS] = {};
        string_to_lower(cities[i].city_name, lower_program_city_name);
        if (is_strings_equal(lower_user_city_name, lower_program_city_name)) {
            return 1;
        }
    }
    return 0;
}


