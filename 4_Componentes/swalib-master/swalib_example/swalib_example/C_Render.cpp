#include "C_Render.h"
#include "RenderLayer.h"
#include "C_Movement.h"
#include "Entity.h"


C_Render::C_Render(Entity* _pOwner, const vec2& _vPos, const vec2& _vOffset, float _fRadius, unsigned int _uCurrentBall, unsigned int _uRenderId)
	: Component(_pOwner)
	, m_vPos(_vPos)
	, m_vOffset(_vOffset)
	, m_fRadius(_fRadius)
	, m_uCurrentBall(_uCurrentBall)
	, m_uRenderId(_uRenderId)
{}

const vec2& C_Render::GetPos() { return m_vPos; }
const float C_Render::GetRadius() { return m_fRadius; }
const unsigned int C_Render::GetCurrentBall() { return m_uCurrentBall; }
const unsigned int C_Render::GetRenderId() { return m_uRenderId; }
void C_Render::SetPos(const vec2& _vPos) { m_vPos = _vPos; }
void C_Render::SetRadius(const float _fRadius) { m_fRadius = _fRadius; }
void C_Render::SetCurrentBall(const unsigned int _uCurrentBall) { m_uCurrentBall = _uCurrentBall; }
void C_Render::SetRenderId(const unsigned int _uRenderId) { m_uRenderId = _uRenderId; }

void C_Render::ReceiveMessage(Message* _pMessage)
{
}
void C_Render::Init()
{
	m_pCMovement = m_pOwner->FindComponent<C_Movement>();
}
void C_Render::Slot(double _dDeltaTime)
{
	SetPos(m_pCMovement->GetPos() + m_vOffset);
	RenderLayer::Get(nullptr)->m_tRenderableObjects[m_uRenderId]->SetPos(m_vPos);
	RenderLayer::Get(nullptr)->m_tRenderableObjects[m_uRenderId]->SetSize(vec2(m_fRadius * 2, m_fRadius * 2));
}