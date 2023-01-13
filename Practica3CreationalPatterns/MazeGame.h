#pragma once
#include "Maze.h"
class MazeGame
{
private: 
  Maze* m_pMaze;
public:
  void CreateMaze();
  void CreateMaze2ElectricBoogaloo();
  void PrintMaze();
  void DestroyMaze();
};

