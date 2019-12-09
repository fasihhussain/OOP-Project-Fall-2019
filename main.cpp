
#include "Game.h"
#include "TextureManager.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{

	const int fps = 60;
	const int frameDelay = 1000 / fps;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Aasman ki Unchaiyoun Me", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();
		while (game->gam_paused)
		{
			game->handleEvents();
		}
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}
