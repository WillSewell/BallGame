#include "BallGame.h"

void BallGame::onLoop() {
	if (isMouseDown == true) {
		// Store mouse coords in vector

	}
	physWorld->Step(timeStep, velocityIterations, positionIterations);
}
