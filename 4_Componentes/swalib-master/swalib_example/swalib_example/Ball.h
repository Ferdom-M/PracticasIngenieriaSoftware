#pragma once
#include "../../common/vector2d.h"
#include "../../common/stdafx.h"
#include "Entity.h"

// Logic Info.
class Ball : public Entity	// Info Ball
{
private:
public:
	Ball(vec2 _vPos, float _fRadius, vec2 _vVel, unsigned int _uNumBalls, unsigned int _uCurrentBall, Ball** _tBalls, unsigned int _uRenderId);
};
