#include "C_Movement.h"
#include "Entity.h"
#include "EntityCollisionMessage.h"
#include "LimitWorldCollMessage.h"
#include "NewMovementPosMessage.h"
#include "NewCollisionPosMessage.h"
#include "GetMovementPosMessage.h"

C_Movement::C_Movement(Entity* _pOwner, vec2 _vPos, vec2 _vVel)
	: Component(_pOwner)
	, m_vPos(_vPos)
	, m_vVel(_vVel)
{}

const vec2 C_Movement::GetPos() { return m_vPos; }
const vec2 C_Movement::GetVel() { return m_vVel; }
void C_Movement::SetPos(const vec2 _vPos) { m_vPos = _vPos; }
void C_Movement::SetVel(const vec2 _vVel) { m_vVel = _vVel; }
void C_Movement::InvertVel() { m_vVel *= -1.f; }
void C_Movement::InvertVelX() { m_vVel.x *= -1.f; }
void C_Movement::InvertVelY() { m_vVel.y *= -1.f; }

void C_Movement::ReceiveMessage(Message* _pMessage)
{
	EntityCollisionMessage* pEntityCollisionMessage = dynamic_cast<EntityCollisionMessage*>(_pMessage);
	if (pEntityCollisionMessage) {
		InvertVel();
		return;
	}
	LimitWorldCollMessage* pLimitWorldCollMessage = dynamic_cast<LimitWorldCollMessage*>(_pMessage);
	if (pLimitWorldCollMessage)
	{
		if (pLimitWorldCollMessage->m_bCollX)
			InvertVelX();
		else
			InvertVelY();
		return; 
	}
	NewMovementPosMessage* pNewMovementPosMessage = dynamic_cast<NewMovementPosMessage*>(_pMessage);
	if (pNewMovementPosMessage)
	{
		m_vPos = pNewMovementPosMessage->m_vNewPos;
		return;
	}
	GetMovementPosMessage* pGetMovementPosMessage = dynamic_cast<GetMovementPosMessage*>(_pMessage);
	if (pGetMovementPosMessage)
	{
		pGetMovementPosMessage->m_vNewPos = m_vPos;
		return;
	}
}
void C_Movement::Init()
{
}
void C_Movement::Slot(double _dDeltaTime)
{
	// New Pos.
	vec2 newpos = m_vPos + m_vVel * 60 * _dDeltaTime;

	NewCollisionPosMessage pMessage = NewCollisionPosMessage(newpos);
	m_pOwner->SendMessageComponent(&pMessage);
}