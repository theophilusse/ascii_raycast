#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include <stdbool.h>
//#include <SDL2/SDL.h>
#include <stdlib.h>
#include <ncurses.h>
#include "defs.h"

char 	*initializeWindow(void);
void	destroyWindow(void);
void	clearColorBuffer(char *colorBuffer);
void	renderColorBuffer(char *colorBuffer);
void	drawPixel(char *colorBuffer, int x, int y, color_t color);
void	drawRect(char *colorBuffer, int x, int y, int width, int height, color_t color);
void	drawLine(char *colorBuffer, int x0, int y0, int x1, int y1, color_t color);

#endif
