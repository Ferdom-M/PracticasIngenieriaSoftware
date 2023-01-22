#include "Ball.h"
#include "Game.h"
#include "C_Movement.h"
#include "C_Collision.h"
#include "C_Render.h"

Ball::Ball(vec2 _vPos, float _fRadius, vec2 _vVel, unsigned int _uNumBalls, unsigned int _uCurrentBall, World* _pWorld, unsigned int _uRenderId)
{
  C_Movement* cMovement = new C_Movement(this, _vPos, _vVel);
  C_Collision* cCollision = new C_Collision(this, _vPos, _fRadius, _uNumBalls, _uCurrentBall, _pWorld);
  C_Render* cRender = new C_Render(this, _vPos, vec2(0.f, 0.f), _fRadius, _uCurrentBall, _uRenderId);
  AddComponent(cMovement);
  AddComponent(cCollision);
  AddComponent(cRender);

}
