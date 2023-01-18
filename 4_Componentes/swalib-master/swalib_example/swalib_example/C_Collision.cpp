#include "C_Collision.h"
#include "../../common/vector2d.h"
#include "../../common/sys.h"
#include "C_Movement.h"
#include "Component.h"
#include "Ball.h"

C_Collision::C_Collision(Entity* _pOwner, const vec2& _vPos, float _fRadius, unsigned int _uNumBalls, unsigned int _uCurrentBall, Ball** _tBalls)
	: Component(_pOwner)
	, m_vPos(_vPos)
	, m_fRadius(_fRadius)
	, m_uNumBalls(_uNumBalls)
	, m_uCurrentBall(_uCurrentBall)
	, m_tBalls(_tBalls)
{}

void C_Collision::SetPos(const vec2& _vPos) { m_vPos = _vPos; }
void C_Collision::SetRadius(const float _fRadius) { m_fRadius = _fRadius; }
void C_Collision::SetNumBalls(const unsigned int _uNumBalls) { m_uNumBalls = _uNumBalls; }
void C_Collision::SetCurrentBall(const unsigned int _uCurrentBall) { m_uCurrentBall = _uCurrentBall; }
const vec2& C_Collision::GetPos() { return m_vPos; }
const float C_Collision::GetRadius() { return m_fRadius; }
const unsigned int C_Collision::GetNumBalls() { return m_uNumBalls; }
const unsigned int C_Collision::GetCurrentBall() { return m_uCurrentBall; }

void C_Collision::Init()
{
	for (unsigned int j = 0; j < m_uNumBalls; j++)
	{
		m_tCCollision.push_back(m_tBalls[j]->FindComponent<C_Collision>());
		m_tCMovement.push_back(m_tBalls[j]->FindComponent<C_Movement>());
	}
	m_pCMovement = m_pOwner->FindComponent<C_Movement>();
}
void C_Collision::Slot(const double _dDeltaTime)
{
	// Collision detection.
	bool collision = false;
	int colliding_ball = -1;
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
		m_pCMovement->SetPos(m_vPos);
	}
	else 
	{
		// Rebound!
		m_pCMovement->InvertVel();
		m_tCMovement[colliding_ball]->InvertVel();

		m_vPos = m_pCMovement->GetPos();
		m_tCCollision[colliding_ball]->SetPos(m_tCMovement[colliding_ball]->GetPos());
	}

	// Rebound on margins.
	if ((m_vPos.x > SCR_WIDTH) || (m_vPos.x < 0))
	{
		m_pCMovement->InvertVelX();
		m_vPos = m_pCMovement->GetPos();
	}
	if ((m_vPos.y > SCR_HEIGHT) || (m_vPos.y < 0)) 
	{
		m_pCMovement->InvertVelY();
		m_vPos = m_pCMovement->GetPos();
	}
}