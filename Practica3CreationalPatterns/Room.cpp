#include "Room.h"

Room::Room(int _iX, int _iY, int _iRoomNumber)
  : MapSite(' ', _iX, _iY)
  , m_iRoomNumber(_iRoomNumber)
{
  for (int i = 0; i < NUM_NEIGHBOURS; i++) {
    m_tNeighbours[i] = nullptr;
  }
}

void Room::AddNeighbour(EDirection _dir, MapSite* _pMapSite) {
  m_tNeighbours[static_cast<int>(_dir)] = _pMapSite;
}
MapSite* Room::GetNeighbour(EDirection _dir) {
  return m_tNeighbours[static_cast<int>(_dir)];
}
int Room::Enter() {
  return m_iRoomNumber;
}
int Room::GetRoomNumber() {
  return m_iRoomNumber;
}