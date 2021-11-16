#include "TileMap.h"

//0-coin,1-water,2-plant1,3-plant2,4-plant3,5-ground,6-ball

int lvl1[4][25]={
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,1,6,1,6,1,6,1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
  {2,1,3,1,4,1,2,4,3,1,4,1,1,2,1,1,2,1,1,3,1,4,1,1,1},
  {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5},
};
TileMap::TileMap(){
  tilesheet = TextureManager::loadTexture("assests/TileSheetSmall.png");
  loadTileMap(lvl1);
  src.w = 400;
  src.h = 400;



}
TileMap::~TileMap(){


}

void TileMap::loadTileMap(int arr[4][25]){
  for(int row = 0 ; row <4; row++){
    for(int col =0 ;col <25 ;col++){
      tileMap[row][col] = arr[row][col];
    }
  }

}
void TileMap::drawTileMap(SDL_Rect& camera){
  int type = 0;
  for(int row = 0 ; row <4; row++){
    for(int col =0 ;col <25 ;col++){
      type = tileMap[row][col];

      dest.x = col*150;
      dest.y = row*150;



      switch(type){
        case 0:
          src.x=1200;
          src.y=0;

          dest.x = col*150;
          dest.y = row*150+100;
          dest.w = 50;
          dest.h = 50;

          if(Collision::checkCollision(dest,SpriteManager::getcBox())){

            Collision::collided = false;
            dest.w = 50;
            dest.y = 100;


          }

          TextureManager::render(type,dest.x-camera.x, dest.y,tilesheet, &src);
        break;
        case 1:
          src.x=800;
          src.y=0;
          dest.w = 150;
          dest.h = 150;
          TextureManager::render(type,dest.x-camera.x, dest.y,tilesheet, &src);
        break;
        case 2:
          src.x=400;
          src.y=400;
          dest.w = 150;
          dest.h = 150;
          TextureManager::render(type,dest.x-camera.x, dest.y,tilesheet, &src);
        break;
        case 3:
          src.x=800;
          src.y=400;
          dest.w = 150;
          dest.h = 150;
          TextureManager::render(type,dest.x-camera.x, dest.y,tilesheet, &src);
        break;
        case 4:
          src.x=1200;
          src.y=400;
          dest.w = 150;
          dest.h = 150;
          TextureManager::render(type,dest.x-camera.x, dest.y,tilesheet, &src);
        break;
        case 5:
          src.x=400;
          src.y=0;
          dest.w = 150;
          dest.h = 150;
          TextureManager::render(type,dest.x-camera.x, dest.y,tilesheet, &src);
        break;

        case 6:
          src.x=0;
          src.y=400;

          dest.x = col*150;
          dest.y = row*150+100;
          dest.w = 50;
          dest.h = 50;

          if(Collision::checkCollision(dest,SpriteManager::getcBox())){
            Collision::collided = false;
            dest.w = 50;
            dest.y = 100;
          }


        TextureManager::render(type,dest.x-camera.x, dest.y,tilesheet, &src);
      break;
      }



    }
  }

}
