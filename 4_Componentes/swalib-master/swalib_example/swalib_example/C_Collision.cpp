#include "C_Collision.h"
#include "../../common/vector2d.h"
#include "../../common/sys.h"
#include "World.h"
#include "Entity.h"
#include "EntityCollisionMessage.h"
#include "LimitWorldCollMessage.h"
#include "NewMovementPosMessage.h"
#include "NewCollisionPosMessage.h"
#include "GetMovementPosMessage.h"

C_Collision::C_Collision(Entity* _pOwner, const vec2& _vPos, float _fRadius, unsigned int _uNumBalls, unsigned int _uCurrentBall, World* _pWorld)
	: Component(_pOwner)
	, m_vPos(_vPos)
	, m_fRadius(_fRadius)
	, m_uNumBalls(_uNumBalls)
	, m_uCurrentBall(_uCurrentBall)
	, m_pWorld(_pWorld)
{}

void C_Collision::SetPos(const vec2& _vPos) { m_vPos = _vPos; }
void C_Collision::SetRadius(const float _fRadius) { m_fRadius = _fRadius; }
void C_Collision::SetNumBalls(const unsigned int _uNumBalls) { m_uNumBalls = _uNumBalls; }
void C_Collision::SetCurrentBall(const unsigned int _uCurrentBall) { m_uCurrentBall = _uCurrentBall; }
const vec2& C_Collision::GetPos() { return m_vPos; }
const float C_Collision::GetRadius() { return m_fRadius; }
const unsigned int C_Collision::GetNumBalls() { return m_uNumBalls; }
const unsigned int C_Collision::GetCurrentBall() { return m_uCurrentBall; }

void C_Collision::SetPreviousPos() 
{
	GetMovementPosMessage pMessage = GetMovementPosMessage();
	m_pOwner->SendMessageComponent(&pMessage);
	m_vPos = pMessage.m_vNewPos;

}
void C_Collision::Collide()
{
	// Rebound!
	EntityCollisionMessage pMessage = EntityCollisionMessage();
	m_pOwner->SendMessageComponent(&pMessage);
}

void C_Collision::CollideMarginX()
{
	m_pOwner->SendMessageComponent(&LimitWorldCollMessage(true));
}
void C_Collision::CollideMarginY() 
{
	m_pOwner->SendMessageComponent(&LimitWorldCollMessage(false));
}
void C_Collision::ReceiveMessage(Message* _pMessage)
{
	NewCollisionPosMessage* pNewCollisionPosMessage = dynamic_cast<NewCollisionPosMessage*>(_pMessage);
	if (pNewCollisionPosMessage)
	{
		m_vPos = pNewCollisionPosMessage->m_vNewPos;
		return;
	}
}
void C_Collision::Init()
{
	for (unsigned int j = 0; j < m_uNumBalls; j++)
	{
		m_tCCollision.push_back(m_pWorld->GetEntity(j)->FindComponent<C_Collision>());
	}
}
void C_Collision::Slot(const double _dDeltaTime)
{
	// Collision detection.
	bool collision = false;
	int colliding_ball = -1;
	m_vLastPos = m_vPos;
	for (unsigned int j = 0; j < m_uNumBalls; j++) 
	{
		if (m_uCurrentBall != j) 
		{
			float fRadiusJ = m_tCCollision[j]->GetRadius();
			vec2 vPosJ = m_tCCollision[j]->GetPos();
			float limit2 = (m_fRadius + fRadiusJ) * (m_fRadius + fRadiusJ);
			if (vlen2(m_vPos - vPosJ) <= limit2) 
			{
				collision = true;
				colliding_ball = j;
				break;
			}
		}
	}

	if (!collision)
	{
		m_pOwner->SendMessageComponent(&NewMovementPosMessage(m_vPos));

	}
	else 
	{
		Collide(); 
		m_tCCollision[colliding_ball]->Collide();

		SetPreviousPos();
		m_tCCollision[colliding_ball]->SetPreviousPos();
	}

	// Rebound on margins.
	if ((m_vPos.x > SCR_WIDTH) || (m_vPos.x < 0))
	{
		CollideMarginX();
		SetPreviousPos();
	}
	if ((m_vPos.y > SCR_HEIGHT) || (m_vPos.y < 0)) 
	{
		CollideMarginY();
		SetPreviousPos();
	}
}