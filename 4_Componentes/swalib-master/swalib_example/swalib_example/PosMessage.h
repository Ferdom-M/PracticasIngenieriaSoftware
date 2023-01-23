#pragma once
#include "Message.h"
#include "../../common/vector2d.h"
struct PosMessage :
    public Message
{
  vec2 m_vNewPos;
  PosMessage() = default;
  PosMessage(vec2 _vNewPos)
    : m_vNewPos(_vNewPos)
  {}
};

