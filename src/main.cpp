#include "snake.h"

int main()
{
  Snake game;
  game.init();
  
  while(!game.gameOver) {
    game.input();
    game.logic();
    game.draw();
  }
  
  return game.end();
}
