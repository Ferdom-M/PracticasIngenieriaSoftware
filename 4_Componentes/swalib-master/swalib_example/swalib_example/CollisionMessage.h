#pragma once
#include "Message.h"
struct CollisionMessage :
    public Message
{
  virtual ~CollisionMessage() override = default;
};

