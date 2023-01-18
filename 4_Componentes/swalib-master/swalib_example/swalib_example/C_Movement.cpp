#include "C_Movement.h"
#include "C_Collision.h"
#include "Entity.h"

C_Movement::C_Movement(Entity* _pOwner, vec2 _vPos, vec2 _vVel)
	: Component(_pOwner)
	, m_vPos(_vPos)
	, m_vVel(_vVel)
	, m_pCCollision(nullptr)
{}

const vec2 C_Movement::GetPos() { return m_vPos; }
const vec2 C_Movement::GetVel() { return m_vVel; }
void C_Movement::SetPos(const vec2 _vPos) { m_vPos = _vPos; }
void C_Movement::SetVel(const vec2 _vVel) { m_vVel = _vVel; }
void C_Movement::InvertVel() { m_vVel *= -1.f; }
void C_Movement::InvertVelX() { m_vVel.x *= -1.f; }
void C_Movement::InvertVelY() { m_vVel.y *= -1.f; }

void C_Movement::Init()
{
	m_pCCollision = m_pOwner->FindComponent<C_Collision>();
}
void C_Movement::Slot(double _dDeltaTime)
{
	// New Pos.
	vec2 newpos = m_vPos + m_vVel * 60 * _dDeltaTime;

	m_pCCollision->SetPos(newpos);
}