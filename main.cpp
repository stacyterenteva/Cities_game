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

    //TODO файл + разбиение в алфавитном порядке, чтобы быстрее искать город
    //TODO массив с городами которые ввёл пользователь, и проверка не повторяется ли он
    //TODO проверка того, не повторяет ли пользователь города которые говорили мы
    //TODO проверка того говорит ли пользователь

    FILE *cities_base = fopen("cities_base.csv", "r");

    assert(cities_base);

    City cities[NUM_OF_CITIES] = {};

    //char program_city_name[100] = {};

    for (int j = 0; j < NUM_OF_CITIES; j++) {
        get_city(cities_base, cities[j].city_name);

        cities[j].first_letter = tolower(cities[j].city_name[0]);

        cities[j].last_letter = cities[j].city_name[last_char_num(cities[j].city_name)];
    }

    //putchar(cities[36].city_name[0]);
    int mode = 0;

    scanf("%d", &mode);

    switch (mode) {
        case MODES_ROOLS:
            tell_rools();
            [[fallthrought]];
        case MODES_GAME: {
            begin_game();

            //First_player who_is_first = FIRST_PLAYER_USER;
            char user_city_name[100] = {};
            scanf("%100s", user_city_name);
            clean_buf();

            char flag_of_end[4] = {'e', 'n', 'd', '\0'};
            while (!is_strings_equal(user_city_name, flag_of_end)) {
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

                scanf("%s", user_city_name);
            }
        }
            break;
        default:
            printf("ОШИБКА\n");
            return 1;

    }

    return 0;
}



