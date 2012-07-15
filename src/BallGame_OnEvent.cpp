#include "BallGame.h"

void BallGame::onEvent(SDL_Event* Event) {
	int mouseX, mouseY;
	if (Event->type == SDL_QUIT) {
		running = false;
	} else if (Event->type == SDL_MOUSEBUTTONDOWN && SDL_BUTTON(SDL_GetMouseState(&mouseX, &mouseY)) == SDL_BUTTON_LEFT) {
		isMouseDown = true;
		// The new and prev mouse pos need to be stored, so a line can be
		// drawn between them
//		prevMousePos[0] = curMousePos[0];
//		prevMousePos[1] = curMousePos[1];
//		curMousePos[0] = mouseX;
//		curMousePos[1] = mouseY;
	} else if (Event->type == SDL_MOUSEBUTTONUP && SDL_BUTTON(SDL_GetMouseState(&mouseX, &mouseY)) == SDL_BUTTON_LEFT) {
		isMouseDown = false;
	}
}
