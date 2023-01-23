#pragma once
#include "CollisionMessage.h"
#include "../../common/vector2d.h"
struct EntityCollisionMessage :
    public CollisionMessage
{
  virtual ~EntityCollisionMessage() override = default;
};

