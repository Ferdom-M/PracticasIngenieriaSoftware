#pragma once
#include "../../common/stdafx.h"
#include "../../common/core.h"
#include "../../common/vector2d.h"
#include "../../common/sys.h"
#include "../../common/font.h"

class Game;
class Layer
{
public:
  Layer(Game* _pGame);
  virtual void Init() = 0;
  virtual void Update(double deltaTime) = 0;
protected:
  Game* m_pGame;
};
