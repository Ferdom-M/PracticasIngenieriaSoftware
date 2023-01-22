#pragma once
#include <vector>
#include "../../common/vector2d.h"
#include "Component.h"

class World;
class C_Movement;
class Entity;

class C_Collision :
    public Component
{
private:
	vec2 m_vPos;
	float m_fRadius;
	unsigned int m_uNumBalls, m_uCurrentBall;
	World* m_pWorld;
	std::vector<C_Collision*> m_tCCollision;
	std::vector<C_Movement*> m_tCMovement;
	C_Movement* m_pCMovement = nullptr;

public:
	C_Collision(Entity* _pOwner, const vec2& _vPos, float _fRadius, unsigned int _uNumBalls, unsigned int _uCurrentBall, World* _pWorld);
	void SetPos(const vec2& _vPos);
	void SetRadius(const float _fRadius);
	void SetNumBalls(const unsigned int _uNumBalls);
	void SetCurrentBall(const unsigned int _uCurrentBall);
	const vec2& GetPos();
	const float GetRadius();
	const unsigned int GetNumBalls();
	const unsigned int GetCurrentBall();

	virtual void Init() override;
  virtual void Slot(const double _dDeltaTime) override;
};

