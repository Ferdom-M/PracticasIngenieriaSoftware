#pragma once
#include "MapSite.h"
class Room : public MapSite
{
private:
  int m_iRoomNumber;
public:
  virtual int Enter() override;
  void GetSide();
  void SetSide();


};

