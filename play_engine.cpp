#include <assert.h>
#include <stdio.h>

#include "constants.h"
#include "play_engine.h"
#include "string_funcs.h"

int found_answer(City user_city, City* cities)
{
    assert(cities);

    int i = 0;
    for (i = 0; i < NUM_OF_CITIES; i++) {
        if (user_city.last_letter == cities[i].first_letter) {
            printf("%s\n", cities[i].city_name);
            cities[i] = City {.first_letter = '\0', .city_name = "\0", .last_letter = '\0'};
            return 1;
        }
    }
    return 0;
}



void delete_city_from_memory(const char* user_city, City* cities)
{
    assert(user_city);
    assert(cities);

    for (int i = 0; i < NUM_OF_CITIES; i++) {
        if (is_strings_equal(user_city, cities[i].city_name)) {
            cities[i] = City {.first_letter = '\0', .city_name = "\0", .last_letter = '\0'};
            return ;
        }
    }
}

