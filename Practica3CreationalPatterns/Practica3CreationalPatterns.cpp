#include <iostream>
#include "MazeGame.h"

int main()
{
  MazeGame mazeGame = MazeGame();
  mazeGame.CreateMaze2ElectricBoogaloo();

  mazeGame.PrintMaze();
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");

  mazeGame.DestroyMaze();
}