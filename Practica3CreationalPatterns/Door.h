#pragma once
#include "MapSite.h"
class Door : public MapSite
{
private:
  bool m_bIsOpen;
  int m_iRoom1, m_iRoom2;
public:
  Door(int* _tNeighbourIds, int _iX, int _iY, bool _bIsOpen, int _iRoom1, int _iRoom2);
  virtual int Enter() override;
};

