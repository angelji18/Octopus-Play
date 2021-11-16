#ifndef  _TILEMAP_H_
#define _TILEMAP_H_

#include "GameEngine.h"


class TileMap{
  public:
    TileMap();
    ~TileMap();

    void loadTileMap(int arr[4][25]);
    void drawTileMap(SDL_Rect& camera);


  private:

    SDL_Rect src ,dest;


    SDL_Texture* tilesheet;

    int tileMap[4][25];
    

};

#endif
