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
  const char m_cSprite; 
  int m_iX, m_iY;
public:
  MapSite(const char _cSprite, int _iX, int _iY);
  virtual ~MapSite() = default;
  virtual int Enter();
  void Print();

};

