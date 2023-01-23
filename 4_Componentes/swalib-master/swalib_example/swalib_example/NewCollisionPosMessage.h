#pragma once
#include "PosMessage.h"
struct NewCollisionPosMessage :
  public PosMessage
{
  NewCollisionPosMessage(vec2 _vNewPos)
    : PosMessage(_vNewPos)
  {}
};

