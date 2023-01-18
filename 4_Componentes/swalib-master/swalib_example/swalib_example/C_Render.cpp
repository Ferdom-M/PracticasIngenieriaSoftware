#include "C_Render.h"
#include "RenderLayer.h"
#include "C_Movement.h"
#include "Entity.h"


C_Render::C_Render(Entity* _pOwner, const vec2& _vPos, const vec2& _vOffset, float _fRadius, unsigned int _uCurrentBall)
	: Component(_pOwner)
	, m_vPos(_vPos)
	, m_vOffset(_vOffset)
	, m_fRadius(_fRadius)
	, m_uCurrentBall(_uCurrentBall)
{}

const vec2& C_Render::GetPos() { return m_vPos; }
const float C_Render::GetRadius() { return m_fRadius; }
const unsigned int C_Render::GetCurrentBall() { return m_uCurrentBall; }
void C_Render::SetPos(const vec2& _vPos) { m_vPos = _vPos; }
void C_Render::SetRadius(const float _fRadius) { m_fRadius = _fRadius; }
void C_Render::SetCurrentBall(const unsigned int _uCurrentBall) { m_uCurrentBall = _uCurrentBall; }

void C_Render::Init()
{
	m_pCMovement = m_pOwner->FindComponent<C_Movement>();
}
void C_Render::Slot(double _dDeltaTime)
{
	SetPos(m_pCMovement->GetPos() + m_vOffset);
	RenderLayer::Get(nullptr)->tRenderableObjects[m_uCurrentBall + 1]->SetPos(m_vPos);
	RenderLayer::Get(nullptr)->tRenderableObjects[m_uCurrentBall + 1]->SetSize(vec2(m_fRadius * 2, m_fRadius * 2));
}