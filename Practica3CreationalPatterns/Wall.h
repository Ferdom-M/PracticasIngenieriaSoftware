#pragma once
#include "MapSite.h"
class Wall : public MapSite
{
public:
  Wall(int _iX, int _iY);
  virtual int Enter() override;
};

