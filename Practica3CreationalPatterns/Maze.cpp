#include "Maze.h"
#include <cassert>

Maze::~Maze() {
  for (MapSite* mapSite : m_tMapSites) {
    delete mapSite;
  }
}
void Maze::AddRoom(Room* _newRoom) {
  if (m_tRooms[_newRoom->GetRoomNumber()]) {
    assert(false);
  }
  m_tRooms[_newRoom->GetRoomNumber()] = _newRoom;
}

void Maze::AddMapSite(MapSite* _newMapSite) {
  m_tMapSites.push_back(_newMapSite);
}
Room* Maze::GetRoom(int _iRoomId) {
  return m_tRooms[_iRoomId];
}
void Maze::PrintMaze() {
  for (MapSite* mapSite: m_tMapSites) {
    mapSite->Print();
  }
}