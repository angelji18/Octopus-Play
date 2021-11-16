#include "Collision.h"
bool Collision::collided = false;
bool Collision::checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        Collision::collided = false;
        return Collision::collided;
    }

    if( topA >= bottomB )
    {
      Collision::collided = false;
      return Collision::collided;
    }

    if( rightA <= leftB )
    {
      Collision::collided = false;
      return Collision::collided;
    }

    if( leftA >= rightB )
    {
      Collision::collided = false;
      return Collision::collided;
    }

    //If none of the sides from A are outside B
    Collision::collided = true;
    return Collision::collided;
}
