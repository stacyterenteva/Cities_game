#include <TXLib.h>
#include <stdio.h>

#include "ui.h"
#include "string_funcs.h"
#include "constants.h"

void greeting()
{
    slow_print("Добро пожаловать на страницу игры \"Города\"\n");
    Sleep(SHORT_SLEEP);
    slow_print("Меню: Правила игры(1), начать игру(2)\n");
}

void tell_rools()
{
    printf("Первый игрок называет любой существующий в данный момент времени город\n");
    printf("Затем второй называет город на последнюю букву города первого игрока\n");
    printf("Если город первого игрока заканчивается на твердый или мягкий знак,\n");
    printf("Второй называет город на предпоследнюю букву\n");
    printf("Игра продолжается до тех пор, пока один из нас не сможет назвать подходящий город\n\n");
    Sleep(LONG_SLEEP);

    printf("Для того чтобы начать игру нажмите Enter\n\n");
    getchar();
    getchar();
    printf("\033[1A");
}

void begin_game()
{
    slow_print("Отлично, давайте начнем игру\n");
    Sleep(SHORT_SLEEP);

    //slow_print("Для начала, я случайным образом выберу того, кто из нас начнёт игру\n");
    //Sleep(LONG_SLEEP);
}

void goto_next_phrase() {
    getchar();
    printf("\x1b[A");
}
