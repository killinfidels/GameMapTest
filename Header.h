#pragma once
#include <header-files/gameEngine.h>

int mul = 2;

bool dddddd = init();

WindowM mainWindow("gamemap tests", 400 * mul, 400 * mul);

GameMap mainMap(10, 10, 40 * mul, 40 * mul);

Texture lake("maps/lake.jpeg", &mainWindow);

Texture hair1("maps/hair1.png", &mainWindow);
Texture hair2("maps/hair2.png", &mainWindow);
Texture hair3("maps/hair3.png", &mainWindow);

Object labe(80 * mul, 50 * mul, &mainWindow);

Object hair(80 * mul, 50 * mul, &mainWindow);

SDL_Rect screen;

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