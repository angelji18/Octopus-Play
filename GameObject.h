#ifndef  _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include "GameEngine.h"


class GameObject{
  public:
    GameObject();
    ~GameObject();

    void Init();
    void Update(SDL_Rect& camera);

    //Centers the camera over the dot
    void setCamera( SDL_Rect& camera );

    void Render(SDL_Rect& camera);


  private:



};

#endif
