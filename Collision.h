#ifndef  _COLLISION_H_
#define _COLLISION_H_
#include "GameEngine.h"


class Collision{
public:
  static bool collided;

  static bool checkCollision( SDL_Rect a, SDL_Rect b );
};

#endif
