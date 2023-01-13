#include "MazeGame.h"
#include "Wall.h"
#include "Room.h"
#include "Door.h"


void MazeGame::CreateMaze() {
  m_pMaze = new Maze();

  Door* door1 = m_pMaze->CreateMapSite<Door>(2, 1, true, 1, 2);
  Room* room1 = m_pMaze->CreateMapSite<Room>(1, 1, 1);
  Room* room2 = m_pMaze->CreateMapSite<Room>(3, 1, 2);

  room1->AddNeighbour(EDirection::NORTH, m_pMaze->CreateMapSite<Wall>(1, 0));
  room1->AddNeighbour(EDirection::WEST, m_pMaze->CreateMapSite<Wall>(0, 1));
  room1->AddNeighbour(EDirection::SOUTH, m_pMaze->CreateMapSite<Wall>(1, 2));
  room1->AddNeighbour(EDirection::EAST, door1);

  room2->AddNeighbour(EDirection::NORTH, m_pMaze->CreateMapSite<Wall>(3, 0));
  room2->AddNeighbour(EDirection::WEST, door1);
  room2->AddNeighbour(EDirection::SOUTH, m_pMaze->CreateMapSite<Wall>(3, 2));
  room2->AddNeighbour(EDirection::EAST, m_pMaze->CreateMapSite<Wall>(4, 1));

  m_pMaze->AddRoom(room1);
  m_pMaze->AddRoom(room2);
}

void MazeGame::CreateMaze2ElectricBoogaloo() {
  m_pMaze = new Maze();

  Door* door1 = m_pMaze->CreateMapSite<Door>(1, 2, true, 1, 5);
  Door* door2 = m_pMaze->CreateMapSite<Door>(4, 2, true, 4, 6);
  Room* room1 = m_pMaze->CreateMapSite<Room>(1, 1, 1);
  Room* room2 = m_pMaze->CreateMapSite<Room>(2, 1, 2);
  Room* room3 = m_pMaze->CreateMapSite<Room>(3, 1, 3);
  Room* room4 = m_pMaze->CreateMapSite<Room>(4, 1, 4);
  Room* room5 = m_pMaze->CreateMapSite<Room>(1, 3, 5);
  Room* room6 = m_pMaze->CreateMapSite<Room>(4, 3, 6);

  room1->AddNeighbour(EDirection::NORTH, m_pMaze->CreateMapSite<Wall>(1, 0));
  room1->AddNeighbour(EDirection::WEST, room2);
  room1->AddNeighbour(EDirection::SOUTH, door1);
  room1->AddNeighbour(EDirection::EAST, m_pMaze->CreateMapSite<Wall>(0, 1));

  room2->AddNeighbour(EDirection::NORTH, m_pMaze->CreateMapSite<Wall>(2, 0));
  room2->AddNeighbour(EDirection::WEST, room1);
  room2->AddNeighbour(EDirection::SOUTH, m_pMaze->CreateMapSite<Wall>(2, 2));
  room2->AddNeighbour(EDirection::EAST, room3);

  room3->AddNeighbour(EDirection::NORTH, m_pMaze->CreateMapSite<Wall>(3, 0));
  room3->AddNeighbour(EDirection::WEST, room2);
  room3->AddNeighbour(EDirection::SOUTH, m_pMaze->CreateMapSite<Wall>(3, 2));
  room3->AddNeighbour(EDirection::EAST, room4);

  room4->AddNeighbour(EDirection::NORTH, m_pMaze->CreateMapSite<Wall>(4, 0));
  room4->AddNeighbour(EDirection::WEST, room3);
  room4->AddNeighbour(EDirection::SOUTH, door2);
  room4->AddNeighbour(EDirection::EAST, m_pMaze->CreateMapSite<Wall>(5, 1));

  room5->AddNeighbour(EDirection::NORTH, door1);
  room5->AddNeighbour(EDirection::WEST, m_pMaze->CreateMapSite<Wall>(0, 3));
  room5->AddNeighbour(EDirection::SOUTH, m_pMaze->CreateMapSite<Wall>(1, 4));
  room5->AddNeighbour(EDirection::EAST, m_pMaze->CreateMapSite<Wall>(2, 3));

  room6->AddNeighbour(EDirection::NORTH, door2);
  room6->AddNeighbour(EDirection::WEST, m_pMaze->CreateMapSite<Wall>(3, 3));
  room6->AddNeighbour(EDirection::SOUTH, m_pMaze->CreateMapSite<Wall>(4, 4));
  room6->AddNeighbour(EDirection::EAST, m_pMaze->CreateMapSite<Wall>(5, 3));

  m_pMaze->AddRoom(room1);
  m_pMaze->AddRoom(room2);
}

void MazeGame::PrintMaze() {
  m_pMaze->PrintMaze();
}

void MazeGame::DestroyMaze() {
  delete m_pMaze;
}