#include "BallGame.h"

bool BallGame::onInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }
    if ((surfDisplay = SDL_SetVideoMode(SCRN_WIDTH, SCRN_HEIGHT, 32,
    									SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }
    if ((surfTest = CSurface::OnLoad("myimage.bmp")) == NULL) {
        return false;
    }
    return true;
}

void BallGame::initPhys() {
	// Define the gravity vector.
	b2Vec2 gravity(0.0f, 5.0f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	physWorld = new b2World(gravity);

	// Define the ground body.
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(SCRN_WIDTH / 2, 440);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	groundBody = physWorld->CreateBody(&groundBodyDef);

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(SCRN_WIDTH / 2, 40);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the dynamic body. We set its position and call the body factory.
	b2BodyDef physBallDef;
	physBallDef.type = b2_dynamicBody;
	physBallDef.position.Set(200.0f, 200.0f);
	physBall = physWorld->CreateBody(&physBallDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(25.0f, 20.0f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Bounciness
	fixtureDef.restitution = 0.8f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	physBall->CreateFixture(&fixtureDef);

	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.
	timeStep = 1.0f / 60.0f;
	velocityIterations = 6;
	positionIterations = 2;
}
