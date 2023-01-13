#pragma once

enum class EDirection{
  NORTH,
  SOUTH,
  EAST,
  WEST
};

class MapSite
{
protected:
  int m_tNeighbourIds[4];
  const char m_cSprite; 
  int m_iX, m_iY;
public:
  MapSite(int* _tNeighbourIds, const char _cSprite, int _iX, int _iY);
  virtual int Enter();
  void Print();
};

