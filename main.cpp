#include <TXLib.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <assert.h>

#include "string_funcs.h"
#include "ui.h"
#include "constants.h"
#include "play_engine.h"

int main()
{
    system("chcp 1251 > nul");

    greeting();

    City cities[5] = {{.first_letter = 'м', .city_name = "Москва", .last_letter = 'а'},
                       {.first_letter = 'а', .city_name = "Астрахань", .last_letter = 'н'},
                       {.first_letter = 'н', .city_name = "Новосибирск", .last_letter = 'к'},
                       {.first_letter = 'к', .city_name = "Караганда", .last_letter = 'а'},
                       {.first_letter = 'а', .city_name = "Афины", .last_letter = 'н'}};

    int mode = 0;

    scanf("%d", &mode);

    switch (mode) {
        case MODES_ROOLS:
            tell_rools();
        case MODES_GAME: {
            begin_game();

            First_player who_is_first = FIRST_PLAYER_USER;

            char user_city_name[MAX_NUM_OF_CHARS] = {'\0'};
            scanf("%s", user_city_name);

            int num_of_used_cities = 0;

            while (!is_strings_equal(user_city_name, "end") && num_of_used_cities != NUM_OF_CITIES) {

                City user_city = {.first_letter = user_city_name[0], .city_name = user_city_name, .last_letter = user_city_name[last_char_num(user_city_name)]};

                found_answer(user_city, cities);

                num_of_used_cities++;

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



