#include <ncurses.h>
#include <stdlib.h>
#include "defs.h"

#include "ray.h"
#include "defs.h"
#include "graphics.h"
#include "map.h"
#include "player.h"
#include "sprite.h"
#include "textures.h"
#include "upng.h"
#include "utils.h"
#include "wall.h"
/* initialize curses */
void ncursesInit(void)
{
    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    clear();
}

void endProgram(void)
{
    endwin();
    exit(0);
}

void initScreen(void)
{
    int x;
    int y;

    y = -1;
    while (++y < LINES)
    {
        x = -1;
        while (++x < COLS)
            mvaddch(y, x, EMPTY);
    }
}

int mainLoop(char *, upng_t **);
void render(char *);

void debugTextures(upng_t **t) // Debug
{
	int i = -1;

	printf("\n\ntextures @(%p) :: \n", t); // Debu
	if (!t)
		return ;
	while (++i < NUM_TEXTURES)
		printf("\tt(%d) : %p\n", i, t[i]);
}

int main(void)
{
	upng_t		**upngTextures;
	char		*scrBuf;
	int		size;

	#ifndef DEBUG
		ncursesInit();
		initScreen();
	#endif
	if (!(scrBuf = initializeWindow()) || !(upngTextures = loadTextures()))
		return (0);
	size = LINES * COLS;
	while (1)
	{
		if (mainLoop(scrBuf, upngTextures)) // Code goes here
			break;
		//drawPixel(scrBuf, 15, 15, 0x0000ff00); // DEBUG
		refresh();
		//drawScreen(scrBuf, size);
	}
	#ifndef DEBUG
		endProgram();
	#endif
	return (0);
}

void clearScreen(char *scrBuf)
{
	int pixIndex;
	int size;

	pixIndex = -1;
	size = COLS * LINES;
	while (++pixIndex < size)
		scrBuf[pixIndex] = 0;
	//memset(scrBuf, 0, COLS * LINES);
}

void render(char *scrBuf)
{
    int		x;
    int		y;
    //int		color;
    char	*pix;

    if (!(pix = scrBuf))
	    return ;
    x = 0;
    y = 0;
    while (y < LINES) // Scanline
    {
	    //color = getPixel(scrBuf, x, y);
	    mvaddch(y, x, *(pix++));
	    //mvaddch(y, x, *(pix++));
	    x++;
	    if (x == COLS)
	    {
			y++;
			x = 0;
	    }
    }
}

int mainLoop(char *scrBuf, upng_t **upngTextures)
{
    static int x = COLS / 2;
    static int y = LINES / 2;
    static char background;
    int tmp[2];
    int input;
    int renderFrame;

	int turn = 0;
	int walk = 0;

    tmp[0] = x;
    tmp[1] = y;
    input = getch();
    renderFrame = 1;
    switch (input)
    {
        case 'w':
        {
            walk = 1;
            break;
        }
		case 'a':
        {
            turn = -1;
            break;
        }
        case 's':
        {
            walk = -1;
            break;
        }
		case 'd':
        {
            turn = 1;
            break;
        }
		default:
			renderFrame = 0;
    }
    if (!renderFrame)
		return (0);
	else
		clearScreen(scrBuf);

	//player.x = x;
	//player.y = y;
	player.walkDirection = walk;
	player.turnDirection = turn;
	movePlayer(0.025);

	castAllRays();

    //mvaddch(tmp[1], tmp[0], background);
    //return (0); // Debug
	////background = mvinch(y, x);
	//return (0); // Debug
	renderMapGrid(scrBuf);
	renderMapPlayer(scrBuf);

	renderMapRays(scrBuf);
	
	renderMapSprites(scrBuf);
	////renderSpriteProjection(scrBuf, upngTextures);
	//renderWallProjection(scrBuf, upngTextures);
    render(scrBuf);
    //drawLine(scrBuf, LINES / 2, COLS / 2, x, y, '*');
    //mvaddch(y, x, 'X');
    return (0);
}
