#pragma once
#include "Layer.h"
#include "RenderableObject.h"

class RenderLayer : public Layer
{
public:
  std::vector<RenderableObject*> m_tRenderableObjects;	// Array of RenderableObjects.
  static RenderLayer* Get(Game* _pGame);

  unsigned int AddRenderableObject(RenderableObject* _pRenderableObject);
  virtual void Init() override;
  virtual void Update(double deltaTime) override;

private:
  unsigned int m_uNumRenderableObjects = -1;
  static RenderLayer* m_Instance;
  RenderLayer(Game* _pGame);
};

