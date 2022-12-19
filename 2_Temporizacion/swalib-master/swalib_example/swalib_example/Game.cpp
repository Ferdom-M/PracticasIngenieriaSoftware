#include "Game.h"


void Game::InitGame() {

  m_tGameLayers[0] = new LogicLayer(this);
  m_tGameLayers[1] = new RenderLayer(this);

  for (Layer* layer : m_tGameLayers) {
    layer->Init();
  }
}


void Game::UpdateGame() {

  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&previousTime);
  double ellapsedTime = 0;
  while (!SYS_GottaQuit()) {
    QueryPerformanceCounter(&currentTime);
    ellapsedTime = static_cast<float>(currentTime.QuadPart - previousTime.QuadPart) / frequency.QuadPart;
    deltaTime += ellapsedTime;
    totalTime += ellapsedTime;
    secondTime += ellapsedTime;
    previousTime = currentTime;
    if (secondTime >= 1) {
      updateCount = 0;
      secondTime = 0;
    }
    while (deltaTime >= fixedTime) {
      for (Layer* layer : m_tGameLayers) {
        layer->Update(deltaTime);
      }
      deltaTime = deltaTime - fixedTime;
      if (deltaTime > 1.f / 15.f) {
        deltaTime = 0;
      }
    }

    //SYS_Sleep(33);	// To force 60 fps
  }
}

void Game::EndGame() {
  // Unload textures.
  for (Layer* layer : m_tGameLayers) {
    delete layer;
  }
  CORE_UnloadPNG(texbkg);
  CORE_UnloadPNG(texsmallball);
  FONT_End();
}