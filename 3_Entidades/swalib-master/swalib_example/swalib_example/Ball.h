#pragma once
#include "../../common/vector2d.h"
#include "../../common/stdafx.h"

// Logic Info.
class Ball	// Info Ball
{
private:
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	float  radius;	// Radius.
public:
	Ball();
	const vec2 GetPos();
	const vec2 GetVel();
	const float GetRadius();
	void SetPos(const vec2 _vPos);
	void SetVel(const vec2 _vVel);
	void SetRadius(const float _fRadius);
	void Slot(const double _fDeltaTime, const unsigned int _uCurrentBall, const unsigned int _uNumBalls, Ball* _tBalls);
};
