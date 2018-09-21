#include "header.h"

int main(int argc, char* args[])
{
	bool quit = false;

	SDL_Event e;

	labe.setTexture(lake.getTexture());
	labe.rect.x = 300 * mul;
	labe.rect.y = 200 * mul;

	int defX = labe.rect.x;
	int defY = labe.rect.y;
	labe.dontSlowDown = false;

	mainMap.setRenderer(mainWindow.getRenderer());
	//mainMap.setTileTextures("maps");
	mainMap.setTilesTexture("maps/beach/tileset");
	mainMap.setTileMap(map);
	mainMap.createMap();

	bool pressed;
	float speed = 1 * mul;
	labe.setMaxSpeed(2.5 * mul);
	//labe.setMaxSpeed(10000000000000000);

	while (!quit)
	{
		pressed = false;

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

		//keypresses
		{	
			if (keyHandler.isPressed(SDLK_f))
			{
				labe.rect.x = 300 * mul;
				labe.rect.y = 200 * mul;
			}

			if (keyHandler.isPressed(SDLK_w))
			{
				labe.setVelocityY(labe.getVelocityY() - speed);
				//mainMap.setCamXY(mainMap.camX, mainMap.camY + speed);
				if (legsAnimU.play() == NULL)
					legsObject.setTexture(legsAnimU.play());

				legsObject.setTexture(legsAnimU.play());
				pressed = true;
			}

			if (keyHandler.isPressed(SDLK_s))
			{
				labe.setVelocityY(labe.getVelocityY() + speed);
				//mainMap.setCamXY(mainMap.camX, mainMap.camY - speed);
				if (legsAnimD.play() == NULL)
					legsObject.setTexture(legsAnimD.play());

				legsObject.setTexture(legsAnimD.play());
				pressed = true;
			}

			if (keyHandler.isPressed(SDLK_a))
			{
				labe.setVelocityX(labe.getVelocityX() - speed);
				//mainMap.setCamXY(mainMap.camX + speed, mainMap.camY);
				if (legsAnimL.play() == NULL)
					legsObject.setTexture(legsAnimL.play());

				legsObject.setTexture(legsAnimL.play());
				pressed = true;
			}

			if (keyHandler.isPressed(SDLK_d))
			{
				labe.setVelocityX(labe.getVelocityX() + speed);
				//mainMap.setCamXY(mainMap.camX - speed, mainMap.camY);
				if (legsAnimR.play() == NULL)
					legsObject.setTexture(legsAnimR.play());

				legsObject.setTexture(legsAnimR.play());
				pressed = true;
			}

			if (keyHandler.isPressed(SDLK_1))
			{
				hair.setTexture(hair1.getTexture());
			}

			if (keyHandler.isPressed(SDLK_2))
			{
				hair.setTexture(hair2.getTexture());
			}

			if (keyHandler.isPressed(SDLK_3))
			{
				hair.setTexture(hair3.getTexture());
			}

			if (keyHandler.isPressed(SDLK_4))
			{
				hair.clearTexture();
			}
		}
		

		labe.updateMovement();

		labe.collision(mapSize, true);

		hair.rect.x = labe.rect.x;
		hair.rect.y = labe.rect.y;

		legsObject.rect.x = labe.rect.x;
		legsObject.rect.y = labe.rect.y + labe.rect.h - legsObject.rect.w / 10;

		camera.x = labe.rect.x - camera.w / 2 + labe.rect.w / 2;
		camera.y = labe.rect.y - camera.h / 2 + labe.rect.h / 2;

		//mainMap.setCamXY((labe.rect.x - defX) * -1, (labe.rect.y - defY) * -1);

		SDL_RenderClear(mainWindow.getRenderer());

		mainMap.drawMap(camera);

		if (pressed)
			legsObject.draw(camera);

		labe.draw(camera);

		hair.draw(camera);

		SDL_RenderPresent(mainWindow.getRenderer());

		setFPS(60);
	}

	mainMap.~GameMap();
	mainWindow.~WindowM();

	return 0;
}