#pragma once
#include "Component.h"
#include "../../common/vector2d.h"

class C_Collision;
class Entity;
class C_Movement :
    public Component
{
private:
  vec2   m_vPos;	// Position.
  vec2   m_vVel;	// Velocity.
	C_Collision* m_pCCollision;
public:
	C_Movement(Entity* _pOwner, vec2 _vPos, vec2 _vVel);
	const vec2 GetPos();
	const vec2 GetVel();
	void SetPos(const vec2 _vPos);
	void SetVel(const vec2 _vVel);

	void InvertVel();
	void InvertVelX();
	void InvertVelY();

	virtual void Init() override;
	virtual void Slot(double _dDeltaTime) override;
};

