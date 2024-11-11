#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include "defs.h"
#include "graphics.h"

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

/*bool*/char	mapHasWallAt(float x, float y);
/*bool*/char	isInsideMap(float x, float y);
void			renderMapGrid(char *colorBuffer);
int				getMapAt(int i, int j);

#endif
