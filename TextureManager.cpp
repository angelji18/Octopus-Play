#include "TextureManager.h"


SDL_Texture* TextureManager::loadTexture(const char* texture){
  SDL_Surface*  imgAsSurface = IMG_Load(texture);
  SDL_Texture* imgAsTexture = SDL_CreateTextureFromSurface(GameEngine::renderer,imgAsSurface);
  SDL_FreeSurface(imgAsSurface);
  return imgAsTexture;
}

// void TextureManager::Draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect dest){
//   SDL_RenderCopy(GameEngine::renderer, texture, &source, &dest);
// }

void TextureManager::render(int type, int x, int y,SDL_Texture* texture, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, 150, 150 };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
    if((type == 999)||(type == 1)||(type == 2)||(type == 3)||(type == 4)||(type == 5)){
      renderQuad.w = 150;
      renderQuad.h = 150;
    }
    else if ((type == 0)||(type == 6)) {
      renderQuad.w = 50;
  		renderQuad.h = 50;
    }
    else if (type == 888) {
      renderQuad.y=  rand()% 100 + 10;
      renderQuad.w = 20;
  		renderQuad.h = 20;
    }


    	//Render to screen
      SDL_RenderCopy( GameEngine::renderer, texture, clip, &renderQuad);

	}
}
