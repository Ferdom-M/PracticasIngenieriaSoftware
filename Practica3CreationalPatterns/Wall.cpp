#include "Wall.h"
Wall::Wall(int* _tNeighbourIds, int _iX, int _iY)
  : MapSite(_tNeighbourIds, 'X', _iX, _iY)
{}
int Wall::Enter() {
  return -1;
}