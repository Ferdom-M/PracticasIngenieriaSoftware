#pragma once
#include "MapSite.h"
class Room : public MapSite
{
private:
  int m_iRoomNumber;
  int NUM_NEIGHBOURS = 4;
  MapSite* m_tNeighbours[4];
public:
  Room(int _iX, int _iY, int _iRoomNumber);
  virtual int Enter() override;
  void AddNeighbour(EDirection _dir, MapSite* _pMapSite); 
  MapSite* GetNeighbour(EDirection _dir);
  int GetRoomNumber();


};

