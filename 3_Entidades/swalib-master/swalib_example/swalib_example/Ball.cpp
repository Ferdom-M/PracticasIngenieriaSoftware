#include "Ball.h"
#include "Game.h"

Ball::Ball()
	: pos(0.0f)
	, vel(0.0f)
	, radius(0.0f)
{}
const vec2 Ball::GetPos() { return pos; }
const vec2 Ball::GetVel(){ return vel; }
const float Ball::GetRadius() {	return radius; }
void Ball::SetPos(const vec2 _vPos) {	pos = _vPos; }
void Ball::SetVel(const vec2 _vVel) {	vel = _vVel; }
void Ball::SetRadius(const float _fRadius) { radius = _fRadius; }

void Ball::Slot(const double _dDeltaTime, const unsigned int _uCurrentBall, const unsigned int _uNumBalls, Ball* _tBalls) {
	// New Pos.
	vec2 newpos = pos + vel * 60 * _dDeltaTime;

	// Collision detection.
	bool collision = false;
	int colliding_ball = -1;
	for (unsigned int j = 0; j < _uNumBalls; j++) {
		if (_uCurrentBall != j) {
			float limit2 = (radius + _tBalls[j].radius) * (radius + _tBalls[j].radius);
			if (vlen2(newpos - _tBalls[j].pos) <= limit2) {
				collision = true;
				colliding_ball = j;
				break;
			}
		}
	}

	if (!collision) {
		pos = newpos;
	}
	else {
		// Rebound!
		vel = vel * -1.f;
		_tBalls[colliding_ball].vel = _tBalls[colliding_ball].vel * -1.f;
	}

	// Rebound on margins.
	if ((pos.x > SCR_WIDTH) || (pos.x < 0)) {
		vel.x *= -1.0;
	}
	if ((pos.y > SCR_HEIGHT) || (pos.y < 0)) {
		vel.y *= -1.0;
	}

}