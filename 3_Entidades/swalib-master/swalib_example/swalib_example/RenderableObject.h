#pragma once
#include "../../common/stdafx.h"
#include "../../common/vector2d.h"
class RenderableObject
{
private:
	vec2   pos;	// Position.
	vec2   size;	// Size.
	GLuint* gfx;	// OpenGL for id. for visualization purposes. 
public:
	RenderableObject();
	const vec2 GetPos();
	const vec2 GetSize();
	const GLuint* GetGfx();
	void SetPos(const vec2 _vPos);
	void SetSize(const vec2 _vSize);
	void SetGfx(GLuint* _pGfx);
};

