#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"


using namespace std;
using namespace tz_SDL;

int main(int argc, char* args[]) {

	srand(time(NULL));

	Screen screen;
	if (screen.init() == false) {
		cout << "Error initializing failed" << endl;
	}

	Swarm swarm;
	int halfWidth = Screen::SCREEN_WIDTH / 2;

	while (true)
	{
		int elapsed = SDL_GetTicks();

		//screen.clear();
		swarm.update(elapsed);

		int red = (1 + sin(elapsed * 0.001)) * 128;
		int green = (1 + sin(elapsed * 0.002)) * 128;
		int blue = (1 + sin(elapsed * 0.003)) * 128;

		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES;i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * halfWidth;
			int y = particle.m_y * halfWidth + Screen::SCREEN_HEIGHT/2;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

		//Draw the screen
		screen.update();

		//End program
		if (screen.processEvent() == false) {
			break;
		}
	}

	screen.close();
	return 0;
}