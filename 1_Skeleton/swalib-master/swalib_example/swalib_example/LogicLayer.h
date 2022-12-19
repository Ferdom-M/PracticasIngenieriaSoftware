#pragma once
#include "Layer.h"
#include "Game.h"

class LogicLayer :
    public Layer
{
public:
  LogicLayer(Game* _pGame);
  virtual void Init() override;
  virtual void Update() override;
};

