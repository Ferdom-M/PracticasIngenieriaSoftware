#include "RenderableObject.h"

RenderableObject::RenderableObject()
	: pos(0.0f)
	, size(0.0f)
{}
const vec2 RenderableObject::GetPos() { return pos; }
const vec2 RenderableObject::GetSize() { return size; }
void RenderableObject::SetPos(const vec2 _vPos) { pos = _vPos; }
void RenderableObject::SetSize(const vec2 _vSize) { size = _vSize; }
void RenderableObject::Draw() {  }