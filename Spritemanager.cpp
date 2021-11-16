#include "SpriteManager.h"
#include "Collision.h"
int check = 0;
SDL_Rect cBox;
Particle* particles[ 50 ];

SpriteManager::SpriteManager(const char* texture,int x, int y)
{
  objTexture = TextureManager::loadTexture(texture);
  xpos = x;
  ypos = y;

  //Set collision box dimension
  cBox.w = 100;
  cBox.h = 100;

  //Initialize particles
  for( int i = 0; i < 50; ++i )
  {
      particles[ i ] = new Particle( xpos, ypos );

  }
}


SpriteManager::~SpriteManager()
{
}

void SpriteManager::UpdateSprite(){

  xpos++;
  //ypos++;

  //animates idle state altering between sprites
  //400 is the width, and so in the else it adds 400 to depict animation
  if((check%10==0)||(check%10==1)||(check%10==2)||(check%10==3)||(check%10==4)){
    sourceRect.x = 0;
  }
  else{
    sourceRect.x = 400;
  }

    sourceRect.y = 0;
    sourceRect.w = 400;
    sourceRect.h = 400;




    destRect.x = xpos;
    destRect.y = 200;
    destRect.w = 150;
    destRect.h = 150;

    if(Collision::collided)
    {
      sourceRect.x = 800;
      destRect.y = 100;
      Collision::collided = false;
    }

    cBox.x = xpos+20;
    cBox.y = 200;

  check++;
  xpos++;


}
SDL_Rect SpriteManager::getcBox(){
  return cBox;
}

int SpriteManager::getPosX()
{
	return xpos;
}

int SpriteManager::getPosY()
{
	return ypos;
}

void SpriteManager::RenderSprite(SDL_Rect& camera )
{
  if(destRect.x>1150){
    destRect.x = 1150;
  }
   TextureManager::render(999,destRect.x-camera.x, destRect.y ,objTexture, &sourceRect);
   renderParticles();
}

void SpriteManager::renderParticles()
{
	//Go through particles
    for( int i = 0; i < 50; ++i )
    {
        //Delete and replace dead particles
        if( particles[ i]->isDead() )
        {
            delete particles[ i ];
            particles[ i ] = new Particle( xpos, ypos );
        }
    }

    //Show particles
    for( int i = 0; i < 50; ++i )
    {

        particles[ i ]->render(camera);

    }
}
