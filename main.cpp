#define TX_COMPILED
#include <TXLib.h>
#include <stdio.h>
#include <math.h>

#include "string_funcs.h"
#include "ui.h"
#include "constants.h"
#include "play_engine.h"

int main()
{
    greeting();

    City cities[5] = {{.first_letter = 'М', .city_name = "Москва", .last_letter = 'а'},
                       {.first_letter = 'А', .city_name = "Астрахань", .last_letter = 'н'},
                       {.first_letter = 'Н', .city_name = "Новосибирск", .last_letter = 'к'},
                       {.first_letter = 'К', .city_name = "Караганда", .last_letter = 'а'},
                       {.first_letter = 'А', .city_name = "Афины", .last_letter = 'н'}};

    int mode = 0;

    scanf("%d", &mode);

    switch (mode) {
        case MODES_ROOLS:
            tell_rools();
        case MODES_GAME: {
            begin_game();

            First_player who_is_first = FIRST_PLAYER_USER;

            if (who_is_first == FIRST_PLAYER_PROGRAM) {
                slow_print("Итак, карты говорят, что начинаю я\n");
                txSleep(LONG_SLEEP);
                slow_print("И мой первый город: ");
                txSleep(LONG_SLEEP);
                int first_city = rand() % NUM_OF_CITIES;
                printf("%s\n", cities[first_city].city_name);
            }
            else {
                slow_print("Начинаете вы\n");
                txSleep(LONG_SLEEP);
                slow_print("Назовите город, с которого хотите начать игру\n");
            }

            char* user_city = {};
            scanf("%s", user_city);

            delete_city_from_memory(user_city, cities);


        }
            break;
        default:
            printf("ОШИБКА\n");
            return 1;

    }

    return 0;
}



