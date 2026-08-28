#include "constants.h"
#include "play_engine.h"

City found_answer(City user_city, City* cities)
{
    int i = 0;
    for (; i < NUM_OF_CITIES; i++) {
        if (user_city.last_letter == cities[i].first_letter) {
            cities[i] = City {.first_letter = '\0', .city_name = "\0", .last_letter = '\0'};
            break;
        }
    }
    return cities[i];
}

void delete_city_from_memory(char* user_city, City* cities)
{
    for (int i = 0; i < NUM_OF_CITIES; i++) {
        if () {
            cities[i] = C{.first_letter = '\0', .city_name = '\0', .last_letter = '\0'};
            return ;
        }
    }
}
