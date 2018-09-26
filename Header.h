#pragma once
#include <header-files/gameEngine.h>

float mul = 2;

bool dddddd = init();

SDL_Rect camera = 
{
	camera.x = 0,
	camera.y = 0,
	camera.w = 400 * mul,
	camera.h = 400 * mul
};

WindowM mainWindow("gamemap tests", camera.w, camera.h);

GameMap mainMap(10, 10, 32 * mul, 32 * mul);
GameMap shrubberyandthelikes(10, 10, 32 * mul, 32 * mul);

SDL_Rect mapSize =
{
	mapSize.x = 0,
	mapSize.y = 0,
	mapSize.w = 32 * 32 * mul,
	mapSize.h = 32 * 32 * mul
};

CollisionObjects rocks("collision", "maps/beach/beach.xml", 2 * mul);

Texture lake("player/lake.jpeg", &mainWindow);

Texture help("maps/old/0old.png", &mainWindow);

Texture hair1("player/hair1.png", &mainWindow);
Texture hair2("player/hair2.png", &mainWindow);
Texture hair3("player/hair3.png", &mainWindow);

Object labe(80 * mul, 50 * mul, &mainWindow);

Object hair(80 * mul, 50 * mul, &mainWindow);

Object legsObject(80 * mul, 50 * mul, &mainWindow);

Animation legsAnimL("LEGS", "legs/L", &mainWindow);
Animation legsAnimR("LEGS", "legs/R", &mainWindow);
Animation legsAnimU("LEGS", "legs/U", &mainWindow);
Animation legsAnimD("LEGS", "legs/D", &mainWindow);

KeyboardHandler keyHandler;

std::vector< std::vector <int> > map 
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 2, 2, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 2, 2, 2, 2, 2, 1, 0 },
	{ 0, 1, 1, 2, 2, 2, 2, 2, 1, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 1, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 1, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 2, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};