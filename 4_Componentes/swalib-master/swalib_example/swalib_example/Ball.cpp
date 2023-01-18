#include "Ball.h"
#include "Game.h"
#include "C_Movement.h"
#include "C_Collision.h"

Ball::Ball(vec2 _vPos, float _fRadius, vec2 _vVel, unsigned int _uNumBalls, unsigned int _uCurrentBall, Ball* _tBalls)
{
  C_Movement* cMovement = new C_Movement(this, _vPos, _vVel);
  C_Collision* cCollision = new C_Collision(this, _vPos, _fRadius, _uNumBalls, _uCurrentBall, _tBalls);
  AddComponent(cMovement);
  AddComponent(cCollision);
}
