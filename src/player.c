#include "player.h"
#include "utils.h"

player_t	player =
{
	.x = (float)COLS / 2,
	//.x = (float)MAP_NUM_COLS / 2,//(float)COLS / 2,
	//.x = (float)MAP_NUM_ROWS / 2,//(float)COLS / 2,
	.y = (float)LINES / 2,
	//.y = (float)MAP_NUM_ROWS / 2,//(float)LINES / 2,
	//.y = (float)MAP_NUM_COLS / 2,//(float)LINES / 2,
	.width = 1,
	.height = 1,
	.turnDirection = 0,
	.walkDirection = 0,
	.rotationAngle = PI / 2,
	.walkSpeed = 100,
	.turnSpeed = 45 * (PI / 180)
};

void	movePlayer(float deltaTime)
{
	float	moveStep;
	float	newPlayerX;
	float	newPlayerY;

	player.rotationAngle += player.turnDirection * player.turnSpeed * deltaTime;
	normalizeAngle(&player.rotationAngle);

	moveStep = player.walkDirection * player.walkSpeed * deltaTime;

	newPlayerX = player.x + cos(player.rotationAngle) * moveStep;
	newPlayerY = player.y + sin(player.rotationAngle) * moveStep;

	if (!mapHasWallAt(newPlayerX, newPlayerY))
	{
		player.x = newPlayerX;
		player.y = newPlayerY;
	}
}

void	renderMapPlayer(char *colorBuffer)
{
	drawRect
	(
	 	colorBuffer,
		player.x * MINIMAP_SCALE_FACTOR,
		player.y * MINIMAP_SCALE_FACTOR,
		player.width * MINIMAP_SCALE_FACTOR,
		player.height * MINIMAP_SCALE_FACTOR,
		0xFFFFFFFF
	);
}
