#pragma once
#include "Component.h"
#include "../../common/vector2d.h"
class C_Movement :
    public Component
{
private:
  vec2   m_vPos;	// Position.
  vec2   m_vVel;	// Velocity.
public:
	C_Movement(Entity* _pOwner, vec2 _vPos, vec2 _vVel);
	const vec2 GetPos();
	const vec2 GetVel();
	void SetPos(const vec2 _vPos);
	void SetVel(const vec2 _vVel);

	void InvertVel();
	void InvertVelX();
	void InvertVelY();

	virtual void Slot(double _dDeltaTime) override;
};

