#pragma once
#include "CollisionMessage.h"
struct LimitWorldCollMessage :
    public CollisionMessage
{
  bool m_bCollX;
  LimitWorldCollMessage(bool _bCollX)
    : m_bCollX(_bCollX)
  {}
};

