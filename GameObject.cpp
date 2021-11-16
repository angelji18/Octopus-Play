#include "GameObject.h"


SpriteManager *spriteManager = NULL;


GameObject::GameObject(){





}
GameObject::~GameObject(){

}

void GameObject::Init()
{
  spriteManager = new SpriteManager("assests/Octopus.png",0,300);

}

void GameObject::Update(SDL_Rect& camera){


  spriteManager-> UpdateSprite();
  GameObject::setCamera(camera);


}



void GameObject::setCamera( SDL_Rect& camera )
{
    //Center the camera over the dot
    // camera.x = ( spriteManager->getPosX() + 150 / 2 ) - 800 / 2;
    // camera.y = ( spriteManager->getPosX() + 150 / 2 ) - 600 / 2;
    camera.x =  spriteManager->getPosX();
    camera.y = spriteManager->getPosY();

    //Keep the camera in bounds
    if( camera.x < 0 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > 1280 - camera.w )
    {
        camera.x = 1280 - camera.w;
    }
    if( camera.y > 960 - camera.h )
    {
        camera.y = 960 - camera.h;
    }

  }

void GameObject::Render(SDL_Rect& camera){

  spriteManager -> RenderSprite(camera);
}
