#include "BallGame.h"
#include <iostream>
using namespace std;

bool BallGame::onRender() {
	if (SDL_FillRect(surfDisplay, NULL, SDL_MapRGB(surfDisplay->format, 100, 200, 0)) < 0) {
		return false;
	}
	// Now print the position and angle of the body.
	b2Vec2 position = physBall->GetPosition();

	filledEllipseRGBA(surfDisplay,
						position.x, position.y,
						25, 20,
						50, 50, 50, 255);
	cout << position.x;
	CSurface::OnDraw(surfDisplay, surfTest, 0, 0);

	// Draw a line between current and previous mouse locs

	lineRGBA(surfDisplay,
	               prevMousePos[0], prevMousePos[1],
	               curMousePos[0], curMousePos[1],
	               255, 0, 0, 255);

	SDL_Flip(surfDisplay);
	return true;
}
