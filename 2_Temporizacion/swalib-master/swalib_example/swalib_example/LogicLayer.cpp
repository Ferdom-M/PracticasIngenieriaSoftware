#include "LogicLayer.h"


LogicLayer::LogicLayer(Game* _pGame) 
	: Layer(_pGame)
{}

void LogicLayer::Init() {
	for (unsigned int i = 0; i < m_pGame->NUM_BALLS; i++) {
		m_pGame->tBalls[i].pos = vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT));
		m_pGame->tBalls[i].vel = vec2(CORE_FRand(-m_pGame->MAX_BALL_SPEED, +m_pGame->MAX_BALL_SPEED), CORE_FRand(-m_pGame->MAX_BALL_SPEED, +m_pGame->MAX_BALL_SPEED));
		m_pGame->tBalls[i].radius = 16.f;
		m_pGame->tBalls[i].gfx = &m_pGame->texsmallball;
	}
}
void LogicLayer::Update(double deltaTime) {
	LARGE_INTEGER startTime, finishedTime;

	QueryPerformanceCounter(&startTime);

	//SYS_Sleep(17);	// To force 60 fps

	// Run balls
	for (unsigned int i = 0; i < m_pGame->NUM_BALLS; i++) {
		// New Pos.
		vec2 newpos = m_pGame->tBalls[i].pos + m_pGame->tBalls[i].vel * 60 * deltaTime;

		// Collision detection.
		bool collision = false;
		int colliding_ball = -1;
		for (unsigned int j = 0; j < m_pGame->NUM_BALLS; j++) {
			if (i != j) {
				float limit2 = (m_pGame->tBalls[i].radius + m_pGame->tBalls[j].radius) * (m_pGame->tBalls[i].radius + m_pGame->tBalls[j].radius);
				if (vlen2(newpos - m_pGame->tBalls[j].pos) <= limit2) {
					collision = true;
					colliding_ball = j;
					break;
				}
			}
		}

		if (!collision) {
			m_pGame->tBalls[i].pos = newpos;
		}
		else {
			// Rebound!
			m_pGame->tBalls[i].vel = m_pGame->tBalls[i].vel * -1.f;
			m_pGame->tBalls[colliding_ball].vel = m_pGame->tBalls[colliding_ball].vel * -1.f;
		}

		// Rebound on margins.
		if ((m_pGame->tBalls[i].pos.x > SCR_WIDTH) || (m_pGame->tBalls[i].pos.x < 0)) {
			m_pGame->tBalls[i].vel.x *= -1.0;
		}
		if ((m_pGame->tBalls[i].pos.y > SCR_HEIGHT) || (m_pGame->tBalls[i].pos.y < 0)) {
			m_pGame->tBalls[i].vel.y *= -1.0;
		}

		QueryPerformanceCounter(&finishedTime);
		m_pGame->logicTime += (float)(finishedTime.QuadPart - startTime.QuadPart) / m_pGame->frequency.QuadPart;
	}
}