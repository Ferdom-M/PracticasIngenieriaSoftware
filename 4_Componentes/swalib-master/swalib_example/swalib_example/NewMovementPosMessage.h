#pragma once
#include "PosMessage.h"
struct NewMovementPosMessage :
  public PosMessage
{
  NewMovementPosMessage(vec2 _vNewPos)
    : PosMessage(_vNewPos)
  {}
};

