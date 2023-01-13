#include "MapSite.h"
#include "consola.h"
#include <stdio.h>

MapSite::MapSite(const char _cSprite, int _iX, int _iY)
  : m_cSprite(_cSprite)
  , m_iX(_iX)
  , m_iY(_iY)
{}
int MapSite::Enter() { return -1; }
void MapSite::Print() {
	gotoxy(m_iX, m_iY);
	printf("%c", m_cSprite);
}