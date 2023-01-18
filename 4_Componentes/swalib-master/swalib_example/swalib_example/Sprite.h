#pragma once
#include "RenderableObject.h"
class Sprite :
    public RenderableObject
{
private: 

  GLuint* gfx;	// OpenGL for id. for visualization purposes. 
public:
  Sprite();
  const GLuint* GetGfx();
  void SetGfx(GLuint* _pGfx);
  virtual void Draw() override;
};

