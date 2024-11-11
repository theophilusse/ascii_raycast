#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>
#include <math.h>
#include <ncurses.h>

#define BEEP(x) system("../beep 100 x"); // Debug

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64

#define NUM_TEXTURES 14
#define NUM_SPRITES 6

#define MINIMAP_SCALE_FACTOR 0.5//0.2

#define FOV_ANGLE (60 * (PI / 180))

#define NUM_RAYS 100

#define DIST_PROJ_PLANE ((COLS / 2) / tan(FOV_ANGLE / 2))

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

/******** DEBUG ********/
//#include <stdio.h>
//#define DEBUG printf("(%s) - %s :: %d\n",  __FILE__, __func__, __LINE__); // Debug
/******** DEBUG ********/

#define MALLOC(size) \
	malloc(size * 4)

typedef uint32_t color_t;
#define EMPTY ' '
static char grayscale[] = "$$$$$$$$$$$$$$$$$$$$$$@@@BBB%%%%%%888&&&WWWMMM###***oooaaahhhkkkbbbdddpppqqqwwwmmmZZZOOO000QQQLLLCCCJJJUUUYYYXXXzzzcccvvvuuunnnxxxrrrjjjfffttt///\\\\\\|||((()))111{{{}}}[[[]]]\?\?\?---___+++~~~<<<>>>iii!!!lllIII;;;:::,,,\"\"\"^^^```'''...                 ";

#define LINES 45
#define COLS 160

#endif
