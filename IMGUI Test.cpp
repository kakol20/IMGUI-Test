// IMGUI Test.cpp : Defines the entry point for the application.
//

#include "IMGUI Test.h"

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("IMGUI Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, - 1, 0);

	bool running = true;
	while (running) {
		// handle events
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		}

		// clear
		SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
		SDL_RenderClear(renderer);

		// draw
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderDrawPoint(renderer, 100, 100);

		// flip buffers
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}