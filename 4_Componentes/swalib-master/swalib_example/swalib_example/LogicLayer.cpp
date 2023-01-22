#include "LogicLayer.h"
#include "RenderLayer.h"
#include "Sprite.h"
#include "BackgroundSprite.h"
#include "Ball.h"
#include "World.h"

LogicLayer* LogicLayer::m_Instance = nullptr;

LogicLayer::LogicLayer(Game* _pGame)
	: Layer(_pGame)
	, tBalls()
	, m_pWorld(nullptr)
{}
LogicLayer* LogicLayer::Get(Game* _pGame) {
	if (m_Instance == nullptr) {
		m_Instance = new LogicLayer(_pGame);
	}
	return m_Instance;
}
void LogicLayer::Init() {
	m_pWorld = new World();

	BackgroundSprite* backgroundSprite = new BackgroundSprite();
	backgroundSprite->SetGfx(&m_pGame->texbkg);
	RenderLayer::Get(nullptr)->AddRenderableObject(backgroundSprite);
	float fRadius = 16.f;
	for (unsigned int i = 0; i < NUM_BALLS; i++) {
		vec2 vPos = vec2(CORE_FRand(0.0, SCR_WIDTH), CORE_FRand(0.0, SCR_HEIGHT));
		vec2 vVel = vec2(CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED), CORE_FRand(-MAX_BALL_SPEED, +MAX_BALL_SPEED));

		Sprite* newBallSprite = new Sprite();
		newBallSprite->SetPos(vPos);
		newBallSprite->SetSize(vec2(fRadius * 2, fRadius * 2));
		newBallSprite->SetGfx(&m_pGame->texsmallball);
		unsigned int uRenderId = RenderLayer::Get(nullptr)->AddRenderableObject(newBallSprite);

		Ball* ball = new Ball(vPos, fRadius, vVel, NUM_BALLS, i, m_pWorld, uRenderId);
		m_pWorld->AddEntity(ball);
	}

	m_pWorld->Init();
}
void LogicLayer::Update(double deltaTime) {
	m_pWorld->Slot(deltaTime);
}