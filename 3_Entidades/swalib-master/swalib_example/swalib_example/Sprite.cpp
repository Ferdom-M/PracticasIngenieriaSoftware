#include "Sprite.h"
#include "../../common/core.h"

Sprite::Sprite()
	: RenderableObject()
	, gfx(0)
{}
const GLuint* Sprite::GetGfx() { return gfx; }
void Sprite::SetGfx(GLuint* _pGfx) { gfx = _pGfx; }
void Sprite::Draw() { 
	CORE_RenderCenteredSprite(GetPos(), vec2(GetSize().x, GetSize().x), *GetGfx());
}