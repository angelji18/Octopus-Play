#ifndef  _GAMEENGINE_H_
#define _GAMEENGINE_H_

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <chrono>
#include <thread>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_timer.h"

#include "TextureManager.h"
#include "GameObject.h"
#include "TileMap.h"
#include "SpriteManager.h"
#include "Collision.h"
#include "Particle.h"

extern bool flag_space;
extern int octx;
extern int octy;
extern SDL_Rect camera;

class GameEngine
{
	   public:
			  GameEngine();
				~GameEngine();

			  int init(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen);
			 	void handleEvents();
			  void update(SDL_Rect& camera);
			  void render(SDL_Rect& camera);
				void clean();



			bool running(){ return isRunning;}

			static SDL_Renderer* renderer;
			static SDL_Event input;

			private:

				bool isRunning = false;
        SDL_Window* window;

};

#endif
