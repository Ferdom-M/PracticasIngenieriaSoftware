#pragma once
#include "Room.h"
#include <map>
#include <vector>
class Maze
{
private:
  std::map<int, Room*> m_tRooms;
  std::vector<MapSite*> m_tMapSites;

public:
  template<typename T, typename... Args>
  T* CreateMapSite(Args&&... args)
  {
    T* mapSite = new T(args...);
    m_tMapSites.push_back(mapSite);
    return mapSite;
  }

  ~Maze();
  void AddRoom(Room* _newRoom);
  void AddMapSite(MapSite* _newMapSite);
  Room* GetRoom(int _iRoomId);
  void PrintMaze();
};

