#pragma once
#include "MapSite.h"
class MazeGame
{
private:
  MapSite m_tRooms[9];

public:
  void AddRoom(MapSite _newRoom);
};

