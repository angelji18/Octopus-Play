#ifndef  _SPRITEMANGER_H_
#define _SPRITEMANGER_H_
#include "GameEngine.h"
#include "Particle.h"
extern float octpos;

class SpriteManager{

public:
  SpriteManager(const char* texture, int x, int y);
  ~SpriteManager();


  void UpdateSprite();
  void RenderSprite(SDL_Rect& camera );

  //Position accessors
  int getPosX();
  int getPosY();
  static SDL_Rect getcBox();

  private:

  SDL_Texture* objTexture;
  SDL_Rect sourceRect, destRect;
  int xpos, ypos;

  

  void renderParticles();




};


#endif
