#include "LogicLayer.h"
#include "Sprite.h"
#include "BackgroundSprite.h"

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

	BackgroundSprite* backgroundSprite = new BackgroundSprite();
	backgroundSprite->SetGfx(&m_pGame->texbkg);
	RenderLayer::Get(nullptr)->tRenderableObjects[0] = backgroundSprite;

	for (unsigned int i = 1; i < NUM_BALLS + 1; i++) {
		tBalls[i].SetPos(vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT)));
		tBalls[i].SetVel(vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED)));
		tBalls[i].SetRadius(16.f);

		Sprite* newBallSprite = new Sprite();
		newBallSprite->SetPos(tBalls[i].GetPos());
		newBallSprite->SetSize(vec2(tBalls[i].GetRadius() * 2, tBalls[i].GetRadius() * 2));
		newBallSprite->SetGfx(&m_pGame->texsmallball);
		RenderLayer::Get(nullptr)->tRenderableObjects[i] = newBallSprite;
	}
}
void LogicLayer::Update(double deltaTime) {
	// Run balls
	for (unsigned int i = 0; i < NUM_BALLS; i++) {
		tBalls[i].Slot(deltaTime, i, NUM_BALLS, tBalls);
		RenderLayer::Get(nullptr)->tRenderableObjects[i+1]->SetPos(tBalls[i].GetPos());
		RenderLayer::Get(nullptr)->tRenderableObjects[i + 1]->SetSize(vec2(tBalls[i].GetRadius() * 2, tBalls[i].GetRadius() * 2));
	}
}