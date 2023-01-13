#pragma once
#include "MapSite.h"
class Wall : public MapSite
{
  Wall(int* _tNeighbourIds, int _iX, int _iY);
  virtual int Enter() override;
};

