#include "MapSite.h"
#include "consola.h"
#include <stdio.h>

MapSite::MapSite(int* _tNeighbourIds, const char _cSprite, int _iX, int _iY)
  : m_tNeighbourIds()
  , m_cSprite(_cSprite)
  , m_iX(_iX)
  , m_iY(_iY)
{
  for (int i = 0; i < 4; i++) {
    m_tNeighbourIds[i] = *(_tNeighbourIds + i);
  }
}
int MapSite::Enter() { return -1; }
void MapSite::Print() {
	gotoxy(m_iX, m_iY);
	printf("%c", m_cSprite);
}