#pragma once
#include "Layer.h"
#include "Game.h"

class RenderLayer : public Layer
{
public:
  RenderLayer(Game* _pGame);
  virtual void Init() override;
  virtual void Update(double deltaTime) override;
};

