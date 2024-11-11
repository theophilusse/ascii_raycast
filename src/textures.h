#ifndef TEXTURES_H
#define TEXTURES_H

#include <stdint.h>
#include "defs.h"
#include "upng.h"

//static upng_t	*textures[NUM_TEXTURES];
//upng_t	*textures[NUM_TEXTURES];

upng_t **loadTextures(void);
void	freeTextures(upng_t **textures);

#endif
