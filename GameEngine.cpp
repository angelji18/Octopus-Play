#include "GameEngine.h"
SDL_Rect camera;
bool flag_space = false;

int x= 0;
int y =0;

TileMap *tile = NULL;
GameObject *octObject = NULL;
SDL_Renderer* GameEngine::renderer = nullptr;



GameEngine::GameEngine(){
}

GameEngine::~GameEngine(){
}

int GameEngine::init(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen){
  int flags = 0;

  if(isFullscreen){
    flags = SDL_WINDOW_FULLSCREEN;
  }


  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    return 0;
  }

  window = SDL_CreateWindow(title, xpos, ypos, width, height, isFullscreen);
  if(window){
    std::cout << "Windown created successfully" << std::endl;
  }

  renderer = SDL_CreateRenderer(window,-1,0);
  if(renderer){
    std::cout << "Renderer created successfully" << std::endl;
  }
  isRunning =true;

  SDL_SetRenderDrawColor(renderer, 192, 238, 254, 1);
  octObject = new GameObject();
  tile = new TileMap();
  //Tile::setTiles(tileSet);


  octObject->Init();


  return 0;
}

void GameEngine::handleEvents(){
  SDL_Event input;

  while(SDL_PollEvent(&input) != 0){
      if(input.type == SDL_QUIT)
      isRunning = false;

      if(input.type == SDL_KEYDOWN)
      {
        std::cout<<"Key Pressed"<<std::endl;


        switch(input.key.keysym.sym)
        {
          case SDLK_SPACE:
            flag_space =true;
            break;
          }
        }
  }
}

void GameEngine::update(SDL_Rect& camera){

  octObject->Update(camera);

}

void GameEngine::render(SDL_Rect& camera){

  SDL_RenderClear(renderer);
  tile->drawTileMap(camera);

  octObject->Render(camera);
  //coinObject->Render();
  SDL_RenderPresent(renderer);

}

void GameEngine::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
