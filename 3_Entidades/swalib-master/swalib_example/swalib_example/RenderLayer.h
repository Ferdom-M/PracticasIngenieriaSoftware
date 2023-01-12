#pragma once
#include "Layer.h"
#include "Game.h"
#include "RenderableObject.h"

class RenderLayer : public Layer
{
public:
  unsigned int NUM_OBJECTS= 10;	// Max. num RenderableObjects.
  RenderableObject tRenderableObjects[10];	// Array of RenderableObjects.
  static RenderLayer* Get(Game* _pGame);
  virtual void Init() override;
  virtual void Update(double deltaTime) override;

private:
  static RenderLayer* m_Instance;
  RenderLayer(Game* _pGame);
};

