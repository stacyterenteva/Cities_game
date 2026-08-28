#include <TXLib.h>
#include <stdio.h>

#include "string_funcs.h"
#include "ui.h"
#include "constants.h"

int main()
{
    greeting();

    int mode = 0;

    scanf("%d", &mode);

    switch (mode) {
        case MODES_ROOLS:
            tell_rools();
        case MODES_GAME:
            begin_game();
            break;
        default:
            printf("ОШИБКА\n");
            return 1;

    }
    City cities[5] = {{.first_letter = 'М', .city_name = "Москва", .last_letter = 'а'},
                       {.first_letter = 'А', .city_name = "Астрахань", .last_letter = 'н'},
                       {.first_letter = 'Н', .city_name = "Новосибирск", .last_letter = 'к'},
                       {.first_letter = 'К', .city_name = "Караганда", .last_letter = 'а'},
                       {.first_letter = 'А', .city_name = "Афины", .last_letter = 'н'}};

    return 0;
}



