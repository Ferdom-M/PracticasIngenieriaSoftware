#include "LogicLayer.h"

LogicLayer* LogicLayer::m_Instance = nullptr;

LogicLayer::LogicLayer(Game* _pGame) 
	: Layer(_pGame)
{}
LogicLayer* LogicLayer::Get(Game* _pGame) {
	if (m_Instance == nullptr) {
		m_Instance = new LogicLayer(_pGame);
	}
	return m_Instance;
}
void LogicLayer::Init() {
	for (unsigned int i = 0; i < NUM_BALLS; i++) {
		tBalls[i].SetPos(vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT)));
		tBalls[i].SetVel(vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED)));
		tBalls[i].SetRadius(16.f);

		RenderLayer::Get(nullptr)->tRenderableObjects[i].SetPos(tBalls[i].GetPos());
		RenderLayer::Get(nullptr)->tRenderableObjects[i].SetSize(vec2(tBalls[i].GetRadius() * 2, tBalls[i].GetRadius() * 2));
		RenderLayer::Get(nullptr)->tRenderableObjects[i].SetGfx(&m_pGame->texsmallball);
	}
}
void LogicLayer::Update(double deltaTime) {
	m_pGame->m_Timer.InitLogicTime();
	//SYS_Sleep(13);	

	// Run balls
	for (unsigned int i = 0; i < NUM_BALLS; i++) {
		tBalls[i].Slot(deltaTime, i, NUM_BALLS, tBalls);
		RenderLayer::Get(nullptr)->tRenderableObjects[i].SetPos(tBalls[i].GetPos());
		RenderLayer::Get(nullptr)->tRenderableObjects[i].SetSize(vec2(tBalls[i].GetRadius() * 2, tBalls[i].GetRadius() * 2));
	}

	m_pGame->m_Timer.ProcessLogicTime();
}