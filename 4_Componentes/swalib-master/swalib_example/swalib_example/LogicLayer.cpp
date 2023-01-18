#include "LogicLayer.h"
#include "RenderLayer.h"
#include "Sprite.h"
#include "BackgroundSprite.h"
#include "Ball.h"

LogicLayer* LogicLayer::m_Instance = nullptr;

LogicLayer::LogicLayer(Game* _pGame) 
	: Layer(_pGame)
	, tBalls()
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
	float fRadius = 16.f;
	for (unsigned int i = 1; i < NUM_BALLS + 1; i++) {
		vec2 vPos = vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT));
		vec2 vVel = vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED));
		
		Ball* ball = new Ball(vPos, fRadius, vVel, NUM_BALLS, i - 1, tBalls);
		tBalls[i - 1] = ball;

		Sprite* newBallSprite = new Sprite();
		newBallSprite->SetPos(vPos);
		newBallSprite->SetSize(vec2(fRadius * 2, fRadius * 2));
		newBallSprite->SetGfx(&m_pGame->texsmallball);
		RenderLayer::Get(nullptr)->tRenderableObjects[i] = newBallSprite;
	}

	// Run balls
	for (unsigned int i = 0; i < NUM_BALLS; i++) {
		tBalls[i]->Init();
	}
}
void LogicLayer::Update(double deltaTime) {
	// Run balls
	for (unsigned int i = 0; i < NUM_BALLS; i++) {
		tBalls[i]->Slot(deltaTime);
	}
}