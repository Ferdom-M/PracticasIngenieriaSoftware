#include "RenderLayer.h"
#include "BackgroundSprite.h"
#include <iostream>
#include <string>
#include "Game.h"

RenderLayer* RenderLayer::m_Instance = nullptr;
RenderLayer::RenderLayer(Game* _pGame)
	: Layer(_pGame)
	, m_tRenderableObjects()
{}
RenderLayer* RenderLayer::Get(Game* _pGame) {
	if (m_Instance == nullptr) {
		m_Instance = new RenderLayer(_pGame);
	}
	return m_Instance;
}

unsigned int RenderLayer::AddRenderableObject(RenderableObject* _pRenderableObject) {
	m_uNumRenderableObjects++;
	m_tRenderableObjects.push_back(_pRenderableObject);

	return m_uNumRenderableObjects;
}

void RenderLayer::Init() {

	FONT_Init();	// Characters and symbols inicialization to draw on screen.

	// Init textures
	m_pGame->texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	m_pGame->texsmallball = CORE_LoadPNG("data/tyrian_ball.png", false);

	// Set up rendering.
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// Specifies clear values for the color buffers.
	glMatrixMode(GL_PROJECTION);	// Specifies projection matrix is the current matrix.
	glLoadIdentity();	// Replaces the current matrix with the identity matrix.
	glOrtho(0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);	// Multiplies the current matrix by an orthographic matrix.
	glEnable(GL_TEXTURE_2D);	// Enabling two-dimensional texturing.
	// NOTA: Mirar diferencias comentando las 2 siguientes funciones.
	glEnable(GL_BLEND);	// Blend the incoming RGBA color values with the values in the color buffers.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Blend func. for alpha color.

}
void RenderLayer::Update(double deltaTime) {
	// Render
	glClear(GL_COLOR_BUFFER_BIT);	// Clear color buffer to preset values.

	for (unsigned int i = 0; i < m_tRenderableObjects.size(); i++) {
		m_tRenderableObjects[i]->Draw();
	}

	// Text
	char buffer[50];
	sprintf(buffer, "FRAMERATE: %f FPS", 1 / deltaTime);
	FONT_DrawString(vec2(0, 16), buffer);

	sprintf(buffer, "FRAMETIME: %f SEC", deltaTime);
	FONT_DrawString(vec2(0, 32), buffer);

	sprintf(buffer, "TOTALTIME: %f SEC", m_pGame->m_Timer.GetTotalTime());
	FONT_DrawString(vec2(0, 48), buffer);

	sprintf(buffer, "LOGICTIME: %f SEC", m_pGame->m_Timer.GetLogicTime());
	FONT_DrawString(vec2(0, 64), buffer);

	// Exchanges the front and back buffers
	SYS_Show();
	SYS_Pump();	// Process Windows messages.
}