#include "header.h"

int main(int argc, char* args[])
{
	bool quit = false;

	SDL_Event e;

	labe.setTexture(lake.getTexture());
	labe.rect.x = 40 * 4;
	labe.rect.y = 40 * 5;

	mainMap.setRenderer(mainWindow.getRenderer());
	mainMap.setTileTextures("maps");
	mainMap.setTileMap(map);
	mainMap.createMap();

	SDL_RenderClear(mainWindow.getRenderer());

	mainMap.drawMap();

	labe.draw();

	SDL_RenderPresent(mainWindow.getRenderer());

	screen.h = 400;
	screen.w = 400;

	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = true;

			switch (e.type) //if a key has been pressed or let go the keyHandler stores the keys state
			{
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				keyHandler.handleKeyboardEvent(&e);
				break;
			default:
				break;
			}
		}

		//labe.setMaxSpeed(10000000000000000);
		{
			if (keyHandler.isPressed(SDLK_f))
			{
				labe.rect.y = 300;
			}

			if (keyHandler.isPressed(SDLK_w))
			{
				labe.setVelocityY(labe.getVelocityY() - 1);
			}

			if (keyHandler.isPressed(SDLK_s))
			{
				labe.setVelocityY(labe.getVelocityY() + 1);
			}

			if (keyHandler.isPressed(SDLK_a))
			{
				labe.setVelocityX(labe.getVelocityX() - 1);
			}

			if (keyHandler.isPressed(SDLK_d))
			{
				labe.setVelocityX(labe.getVelocityX() + 1);
			}

			if (keyHandler.isPressed(SDLK_1))
			{
				hair.setTexture(hair1.getTexture());
			}

			if (keyHandler.isPressed(SDLK_2))
			{
				hair.setTexture(hair2.getTexture());
			}

			if (keyHandler.isPressed(SDLK_1))
			{
				hair.setTexture(hair3.getTexture());
			}
		}
		

		labe.collision(screen, true);

		labe.updateMovement();

		hair.rect.x = labe.rect.x;
		hair.rect.y = labe.rect.y;

		SDL_RenderClear(mainWindow.getRenderer());

		mainMap.drawMap();

		labe.draw();

		hair.draw();

		SDL_RenderPresent(mainWindow.getRenderer());

		setFPS(60);
	}

	mainMap.~GameMap();
	mainWindow.~WindowM();

	return 0;
}