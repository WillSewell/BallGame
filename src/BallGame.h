#ifndef BALLGAME_H_
#define BALLGAME_H_
#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <CSurface.h>
#include <Box2D/Box2D.h>
#include <vector>
using namespace std;

class BallGame {
private:
	bool running;
	SDL_Surface* surfDisplay;
	SDL_Surface* surfTest;
	b2World* physWorld;
	b2Body* groundBody;
	b2Body* physBall;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
	static const int SCRN_WIDTH = 800;
	static const int SCRN_HEIGHT  = 600;
	int prevMousePos [2];
	int curMousePos [2];
	// Vector to store variable number of vectors which store line coords
	vector<int> lines;

	// Holds whether the mouse is being held down
	bool isMouseDown

	void initPhys();
public:
	BallGame();
	int OnExecute();
	virtual ~BallGame();
public:
	bool onInit();
	void onEvent(SDL_Event* Event);
	void onLoop();
	bool onRender();
	void onCleanup();
};

#endif /* BALLGAME_H_ */
