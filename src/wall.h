#ifndef WALL_H
#define WALL_H

#include <math.h>
#include "defs.h"
#include "player.h"
#include "ray.h"
#include "graphics.h"
#include "textures.h"

void	renderWallProjection(char *colorBuffer, upng_t **textures);
void	changeColorIntensity(color_t *color, float factor);

#endif
