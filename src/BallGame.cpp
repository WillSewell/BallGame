#include "BallGame.h"

BallGame::BallGame() {
	surfDisplay = NULL;
	surfTest = NULL;
	running = true;
	initPhys();
}

BallGame::~BallGame() {
	// TODO Auto-generated destructor stub
}

int BallGame::OnExecute() {
	if(onInit() == false) {
	        return -1;
	    }

	    SDL_Event Event;

	    while(running) {
	        while(SDL_PollEvent(&Event)) {
	            onEvent(&Event);
	        }

	        onLoop();
	        if (onRender() == false) {
	        	return -1;
	        }
	    }

	    onCleanup();

	    return 0;
}

int main(int argc, char* argv[]) {
    BallGame bG;

    return bG.OnExecute();
}
