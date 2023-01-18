#pragma once
#include "../../common/stdafx.h"
#include "../../common/vector2d.h"
class RenderableObject
{
private:
	vec2   pos;	// Position.
	vec2   size;	// Size.
public:
	RenderableObject();
	virtual const vec2 GetPos();
	virtual const vec2 GetSize();
	virtual void SetPos(const vec2 _vPos);
	virtual void SetSize(const vec2 _vSize);
	virtual void Draw();
};

