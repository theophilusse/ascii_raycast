#include "graphics.h"

//static char			*colorBuffer = NULL;

char *initializeWindow(void)
{
	int x;
    int y;

    y = -1;
    while (++y < LINES)
    {
        x = -1;
        while (++x < COLS && x < NUM_RAYS)
            mvaddch(y, x, EMPTY);
    }
    size_t size = sizeof(char) * LINES * (COLS > NUM_RAYS ? NUM_RAYS : COLS);
    //printf("SIZE = [%zu]\n", size);
    //exit(1);
    return ((char *)MALLOC(size));
    //return ((char *)MALLOC(sizeof(char) * LINES * (COLS > NUM_RAYS ? NUM_RAYS : COLS)));
}

void	destroyWindow(void)
{
	/*
    free(colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
    */
    endwin();
    exit(0);
}

void	clearColorBuffer(char *colorBuffer)
{
    for (int i = 0; i < COLS * LINES; i++)
		colorBuffer[i] = 0;
    clear();
    
}

void	renderColorBuffer(char *colorBuffer)
{
    /*
	SDL_UpdateTexture
	(
		colorBufferTexture,
		NULL,
		colorBuffer,
		(int)((uint32_t)COLS * sizeof(color_t))
	);
	SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
    */
    int x;
    int y;

    y = -1;
    while (++y < LINES)
    {
        x = -1;
        while (++x < COLS)
            mvaddch(y, x, colorBuffer[(COLS * y) + x]);
    }
}

static char colorToGreyscale(color_t color)
{
    char *ptr;

    ptr = (char *)(&color);
    return ((char)((ptr[0] + ptr[1] + ptr[2]) / 3));
}

static int strlen(char *s)
{
    int len;

    if (!s)
        return (0);
    while (*(s++))
        len++;
    return (len);
}

void	drawPixel(char *colorBuffer, int x, int y, color_t color)
{
	//printf("%d\n", strlen((char *)grayscale));
	//printf("%s\n", grayscale);
	//printf("%d\n", colorToGreyscale(color));
	if (x >= COLS || x < 0 || y >= LINES || y < 0)
		return ;
	colorBuffer[(COLS * y) + x] = grayscale[colorToGreyscale(color)];
}

char	getPixel(char *colorBuffer, int x, int y)
{
	return (colorBuffer[(COLS * y) + x]);
}

void	drawRect(char *colorBuffer, int x, int y, int width, int height, color_t color)
{
	for (int i = x; i <= (x + width); i++)
		for (int j = y; j < (y + height); j++)
			drawPixel(colorBuffer, i, j, color);
}

void	drawLine(char *colorBuffer, int x0, int y0, int x1, int y1, color_t color)
{
	int		deltaX;
	int		deltaY;
	int		longestSideLength;
	float	xIncrement;
	float	yIncrement;
	float	currentX;
	float	currentY;

	// diferences between start and end of the line
	deltaX = (x1 - x0);
	deltaY = (y1 - y0);

	// longest side of the line
	longestSideLength = (abs(deltaX) >= abs(deltaY)) ? abs(deltaX) : abs(deltaY);

	// find the increment values
	xIncrement = deltaX / (float)longestSideLength;
	yIncrement = deltaY / (float)longestSideLength;

	// start point
	currentX = x0;
	currentY = y0;

	// loop all the longest side until the end
	for (int i = 0; i < longestSideLength; i++)
	{
		// draw pixel, rounding the values to integer to get nearest pixel
		drawPixel(colorBuffer, round(currentX), round(currentY), color);

		// increment the slope to get the next pixel
		currentX += xIncrement;
		currentY += yIncrement;
	}
}
