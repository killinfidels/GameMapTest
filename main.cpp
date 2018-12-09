#include "header.h"

int main(int argc, char* args[])
{
	bool quit = false;

	SDL_Event e;

	labe.setTexture(lake.getTexture());
	labe.rect.x = 300 * mul;
	labe.rect.y = 200 * mul;

	for (int i = 0; i < rocks.objAmount; i++)
	{
		rocks.collisObject[i].setRenderer(mainWindow.getRenderer());
		rocks.collisObject[i].setTexture(help.getTexture());
	}

	//int defX = labe.rect.x;
	//int defY = labe.rect.y;
	labe.dontSlowDown = false;

	mainMap.setRenderer(mainWindow.getRenderer());
	shrubberyandthelikes.setRenderer(mainWindow.getRenderer());
	//mainMap.setTileTextures("maps");
	mainMap.setTilesTexture("maps/beach/tileset");
	shrubberyandthelikes.setTilesTexture("maps/beach/tileset");
	//mainMap.setTileMap(map);
	mainMap.setMapFromFile("background", "maps/beach/beach.xml");
	shrubberyandthelikes.setMapFromFile("foreground", "maps/beach/beach.xml");
	mainMap.createMap();
	shrubberyandthelikes.createMap();

	bool pressed;
	bool seeColish = false;
	float speed = 1 * mul;
	labe.setMaxSpeed(2.5 * mul);
	//labe.setMaxSpeed(10000000000000000);

	for (int i = 0; i < 4; i++)
	{
		gunAnim.setFrameTime(i, 200);
	}

	//Angle of rotation
	double degrees = 0.0;

	//Flip type
	SDL_RendererFlip flipType = SDL_FLIP_NONE;

	MOVEMENTTEST.rect.x = -20;
	MOVEMENTTEST.rect.y = -29;

	int mX, mY;
	bool muse = false;

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
			case SDL_MOUSEBUTTONUP:
				muse = true;
			default:
				SDL_GetMouseState(&mX, &mY);
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

			if (keyHandler.isPressed(SDLK_c))
				seeColish = true;

			if (keyHandler.isPressed(SDLK_b))
				seeColish = false;

			if (keyHandler.isPressed(SDLK_w))
			{
				labe.setVelocityY(labe.getVelocityY() - speed);
				//mainMap.setCamXY(mainMap.camX, mainMap.camY + speed);
				if (legsAnimU.play() == NULL)
					legsObject.setTexture(legsAnimU.play());

				legsObject.setTexture(legsAnimU.play());
				pressed = true;
			}

			if (keyHandler.isPressed(SDLK_LEFT))
			{
				int dumb = degrees - 5;

				if (dumb < 0)
				{
					degrees = 360 + dumb;
				}
				else
				{
					degrees = dumb;
				}
			}

			if (keyHandler.isPressed(SDLK_RIGHT))
			{
				int dumb = degrees + 5;
				if (dumb > 360)
				{
					degrees = dumb - 360;
				}
				else
				{
					degrees = dumb;
				}
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
				Mix_PlayChannel(-1, gHigh, 0);
			}
				
			if (keyHandler.isPressed(SDLK_2))
			{
				hair.setTexture(hair2.getTexture());
				Mix_PlayChannel(-1, gMedium, 0);
			}

			if (keyHandler.isPressed(SDLK_3))
			{
				hair.setTexture(hair3.getTexture());
				Mix_PlayChannel(-1, gLow, 0);
			}
				
			if (keyHandler.isPressed(SDLK_4))
			{
				hair.clearTexture();
				Mix_PlayChannel(-1, gScratch, 0);
			}

			if (keyHandler.isPressed(SDLK_9))
			{
				if (Mix_PlayingMusic() == 0)
				{
					//Play the music
					Mix_PlayMusic(gMusic, -1);
				}
				//If music is being played
				else
				{
					//If the music is paused
					if (Mix_PausedMusic() == 1)
					{
						//Resume the music
						Mix_ResumeMusic();
					}
					//If the music is playing
					else
					{
						//Pause the music
						Mix_PauseMusic();
					}
				}

			}

			if (keyHandler.isPressed(SDLK_0))
			{
				//Stop the music
				Mix_HaltMusic();
			}
		}

		//printf("degrees: %s\n", degrees);
		//std::cout << degrees << std::endl;

		if (degrees > 90 && degrees < 270)
		{
			flipType = SDL_FLIP_VERTICAL;
		}
		else
		{
			flipType = SDL_FLIP_NONE;
		}
		

		labe.updateMovement();

		//labe.collision(mapSize, true);

		for (int i = 0; i < rocks.objAmount; i++)
			labe.collision(rocks.collisObject[i].rect, false);

		hair.rect.x = labe.rect.x;
		hair.rect.y = labe.rect.y;

		legsObject.rect.x = labe.rect.x;
		legsObject.rect.y = labe.rect.y + labe.rect.h - legsObject.rect.w / 10;

		if (gunAnim.play() == NULL)
			gunObject.setTexture(gunAnim.play());

		gunObject.setTexture(gunAnim.play());

		camera.x = labe.rect.x - camera.w / 2 + labe.rect.w / 2;
		camera.y = labe.rect.y - camera.h / 2 + labe.rect.h / 2;

		//mainMap.setCamXY((labe.rect.x - defX) * -1, (labe.rect.y - defY) * -1);

		SDL_RenderClear(mainWindow.getRenderer());

		mainMap.drawMap(camera);

		if (seeColish)
		{
			for (int i = 0; i < rocks.objAmount; i++)
				rocks.collisObject[i].draw(camera);
		}

		shrubberyandthelikes.drawMap(camera);

		if (pressed)
			legsObject.draw(camera);

		labe.draw(camera);

		hair.draw(camera);

		//MOVEMENTTEST.setVelocityX((500 - 200) / 120);
		//MOVEMENTTEST.setVelocityY((300 - 600) / 120);

		
		
		double fart = 20;
		MOVEMENTTEST.setMaxSpeed(100);

		int xd = mX - (gunObject.rect.x - camera.x) - gunObject.rect.w / 2;
		int yd = mY - (gunObject.rect.y - camera.y) - gunObject.rect.h / 2;
		int xflip = 1;
		int yflip = 1;

		if (xd < 0)
		{
			xflip = -1;
			xd = xd * xflip;
		}

		if (yd < 0)
		{
			yflip = -1;
			yd = yd * yflip;
		}


		//std::cout << xd << std::endl << yd << std::endl << std::endl;

		double workk = (xd + 0.0) / (xd + yd + 0.0);
		double workk2 = (yd + 0.0) / (xd + yd + 0.0);
		//std::cout << workk << std::endl;
		//std::cout << workk2 << std::endl;

		degrees = 90 * workk2;

		if (yflip > 0)
		{
			if (xflip > 0)
			{
				degrees = 180 + degrees;
			}
			else
			{
				degrees = 360 - degrees;
			}
		}
		else
		{
			if (xflip > 0)
			{
				degrees = 180 - degrees;
			}
		}

		gunObject.rect.x = labe.rect.x + ( 100 * workk * xflip);
		gunObject.rect.y = labe.rect.y - 20 + ( 100 * workk2 * yflip);

		gunObject.updateMovement();

		gunObject.draw(camera, degrees, NULL, flipType);

		if (muse)
		{
			//std::cout << mX << std::endl << mY << std::endl << std::endl;

			MOVEMENTTEST.rect.x = gunObject.rect.x + gunObject.rect.w / 2 - camera.x;
			MOVEMENTTEST.rect.y = gunObject.rect.y + gunObject.rect.h / 2 - camera.y;

			//std::cout << MOVEMENTTEST.rect.x << std::endl << MOVEMENTTEST.rect.y << std::endl << std::endl;

			xd = mX - MOVEMENTTEST.rect.x;
			yd = mY - MOVEMENTTEST.rect.y;
			xflip = 1;
			yflip = 1;

			if (xd < 0)
			{
				xflip = -1;
				xd = xd * xflip;
			}
				
			if (yd < 0)
			{
				yflip = -1;
				yd = yd * yflip;
			}
				

			//std::cout << xd << std::endl << yd << std::endl << std::endl;

			workk = (xd + 0.0) / (xd + yd + 0.0);
			workk2 = (yd + 0.0) / (xd + yd + 0.0);
			//std::cout << workk << std::endl;
			//std::cout << workk2 << std::endl;

			MOVEMENTTEST.setVelocityX((workk * fart) * xflip);
			MOVEMENTTEST.setVelocityY((workk2 * fart) * yflip);


			muse = !muse;
		}

		MOVEMENTTEST.updateMovement();

		SDL_Rect testobject =
		{
			testobject.x = MOVEMENTTEST.rect.x,
			testobject.y = MOVEMENTTEST.rect.y,
			testobject.w = MOVEMENTTEST.rect.w,
			testobject.h = MOVEMENTTEST.rect.h
		};
		
		SDL_RenderFillRect(mainWindow.getRenderer(), &testobject);
		//SDL_SetRenderDrawColor(mainWindow.getRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
		//SDL_RenderDrawLine(mainWindow.getRenderer(), 200, 600, 500, 600);
		//SDL_RenderDrawLine(mainWindow.getRenderer(), 200, 600, 500, 300);
		//SDL_RenderDrawLine(mainWindow.getRenderer(), 500, 600, 500, 300);
		//SDL_SetRenderDrawColor(mainWindow.getRenderer(), 255, 255, 255, SDL_ALPHA_OPAQUE);

		SDL_RenderPresent(mainWindow.getRenderer());

		setFPS(60);
	}

	mainMap.~GameMap();
	mainWindow.~WindowM();

	return 0;
}