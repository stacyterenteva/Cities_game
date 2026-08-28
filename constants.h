
struct City {
                char first_letter;
                const char* city_name;
                char last_letter;
            };

#ifdef VERSION_DEBUG

const int SLOW_PRINT_Sleep = 0;
const int SHORT_SLEEP = 0;
const int LONG_SLEEP = 0;

#else

const int SLOW_PRINT_Sleep = 40;
const int SHORT_SLEEP = 300;
const int LONG_SLEEP = 600;

#endif

const int MAX_NUM_OF_CHARS = 1000;

const int NUM_OF_CITIES = 14;

enum Modes {MODES_ROOLS = 1, MODES_GAME};

enum First_player {FIRST_PLAYER_USER, FIRST_PLAYER_PROGRAM};
