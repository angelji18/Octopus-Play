#include "Particle.h"



Particle::Particle( int x, int y )
{
    //Set offsets
    particlex = x - 5 + (rand() % 25);
    particley = y - 5 + (rand() % 25);

    //Initialize animation
    currentFrame = rand() % 5;


    bub.x=0;
    bub.y=0;
    bub.h=400;
    bub.w=100;

  //Set type
    switch( rand() % 3 )
    {
        case 0:
          bubble = TextureManager::loadTexture("assests/Bubble.png");

        break;
        case 1:
          bubble = TextureManager::loadTexture("assests/Bubblelight.png");

        break;
        case 2:
          bubble = TextureManager::loadTexture("assests/Bubbledarker.png");
        break;
    }
}

void Particle::render(SDL_Rect& camera)
{
  TextureManager::render( 888,particlex, particley,bubble,&bub );

    currentFrame++;
}

bool Particle::isDead()
{
    return currentFrame > 10;
}
