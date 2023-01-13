#include "Wall.h"
Wall::Wall(int _iX, int _iY)
  : MapSite('X', _iX, _iY)
{}
int Wall::Enter() {
  return -1;
}