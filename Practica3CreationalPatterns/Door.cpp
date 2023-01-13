#include "Door.h"

Door::Door(int _iX, int _iY, bool _bIsOpen, int _iRoom1, int _iRoom2)
  : MapSite('O', _iX, _iY)
  , m_bIsOpen(_bIsOpen)
  , m_iRoom1(_iRoom1)
  , m_iRoom2(_iRoom2)
{}
int Door::Enter() {
  if (m_bIsOpen) {
    return m_iRoom2;
  }
  else {
    return -1;
  }
}