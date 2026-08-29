#ifndef CONSTANTS_H
#define CONSTANTS_H

struct City {
                char first_letter;
                char city_name[100];
                char last_letter;
            };

#ifdef VERSION_DEBUG

const int SLOW_PRINT_SLEEP = 0;
const int SHORT_SLEEP = 0;
const int LONG_SLEEP = 0;

#else

const int SLOW_PRINT_SLEEP = 40;
const int SHORT_SLEEP = 300;
const int LONG_SLEEP = 600;

#endif

const int MAX_NUM_OF_CHARS = 100;

const int NUM_OF_CITIES = 599;

enum Modes {MODES_ROOLS = 1, MODES_GAME};

enum First_player {FIRST_PLAYER_USER, FIRST_PLAYER_PROGRAM};

#endif /* CONSTANTS_H */
