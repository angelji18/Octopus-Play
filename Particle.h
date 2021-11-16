#ifndef  _PARTICLE_H_
#define _PARTICLE_H_

#include "GameEngine.h"
#include "TextureManager.h"
class Particle
{
	public:
		Particle( int x, int y );

		void render(SDL_Rect& camera );

		bool isDead();

	private:
		//Offsets
		int particlex, particley;

		//Current frame of animation
		int currentFrame;

		SDL_Texture* bubble;
		SDL_Rect bub;
};


#endif
