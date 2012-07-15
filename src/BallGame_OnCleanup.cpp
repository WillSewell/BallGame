#include "BallGame.h"

void BallGame::onCleanup() {
    SDL_FreeSurface(surfTest);
    SDL_FreeSurface(surfDisplay);
	SDL_Quit();
}
