
#include "GameEngine.h"

//The dimensions of the level
const int LEVEL_WIDTH = 1280;
const int LEVEL_HEIGHT = 960;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;



GameEngine *gameEngine = NULL;

int main(){
  const int FPS = 60;
  //closests to refresh rate of monitiors
  const float frameDelay = 1000/FPS;
  //maxtime between frames

  Uint32 frameStart;
  //gives gametime and how long to run it this is a massive number
  //get current time when gamestarts
  int frameTime;
  SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

  gameEngine = new GameEngine();

  gameEngine->init("MY GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,false);
  //below loop runs per frame
  while(gameEngine->running()){
    frameStart = SDL_GetTicks(); // time since we first initialized SDL

    gameEngine->handleEvents();
    gameEngine->update(camera);
    gameEngine->render(camera);

    frameTime = SDL_GetTicks()-frameStart;
    //time needed to do all the above i.e how long the frame's taken
    //now we'll know if there's a need to cap the time i.e delay so that
    //execution constant across different systems

    if(frameDelay > frameTime){//if max time that the frame can take is more than how much our execution is taking we delay
      SDL_Delay(frameDelay - frameTime);
    }//if you remove this if you'll see how fast your pc can run the frames
  }

  gameEngine->clean();
  return 0;
}
