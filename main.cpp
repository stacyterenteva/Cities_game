#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <ctype.h>

#include "string_funcs.h"
#include "ui.h"
#include "constants.h"
#include "play_engine.h"

int main()
{
    system("chcp 1251 > nul");

    greeting();

    FILE *cities_base = fopen("cities_base.csv", "r");
    assert(cities_base);

    City cities[NUM_OF_CITIES] = {};
    for (int j = 0; j < NUM_OF_CITIES; j++) {
        get_city(cities_base, cities[j].city_name);

        cities[j].first_letter = (char) tolower(cities[j].city_name[0]);

        cities[j].last_letter = cities[j].city_name[last_char_num(cities[j].city_name)];
    }

    int mode = 0;
    scanf("%d", &mode);
    clean_buf();

    switch (mode) {
        case MODES_ROOLS:
            tell_rools();
            [[fallthrough]];
        case MODES_GAME: {
            begin_game();

            char user_city_name[100] = {};
            my_getline(user_city_name, MAX_NUM_OF_CHARS);
            while (!is_city_real(user_city_name, cities)) {
                printf("Кажется такого города нет, введите другой\n");
                my_getline(user_city_name, MAX_NUM_OF_CHARS);
            }

            while (!is_strings_equal(user_city_name, "end")) {
                City user_city = {};

                copy_char_array(user_city_name, user_city.city_name);
                user_city.first_letter = tolower(user_city.city_name[0]);
                user_city.last_letter = tolower(user_city.city_name[last_char_num(user_city.city_name)]);

                if (!found_answer(user_city, cities)) {
                    slow_print("Упс, городов на эту букву я больше не знаю\n");
                    Sleep(SHORT_SLEEP);

                    slow_print("Вы победили)) Поздравляю!\n");
                    break;
                }

                delete_city_from_memory(user_city.city_name, cities);

                my_getline(user_city_name, MAX_NUM_OF_CHARS);
                while (!is_city_real(user_city_name, cities)) {
                    printf("Кажется такого города нет, введите другой\n");
                    my_getline(user_city_name, MAX_NUM_OF_CHARS);
                }
            }
        }
         break;

            break;
        default:
            printf("ОШИБКА\n");
            return 1;
    }

}





