#include "Game.h"


void Game::InitGame() {

  m_tGameLayers[0] = LogicLayer::Get(this);
  m_tGameLayers[1] = RenderLayer::Get(this);

  for (Layer* layer : m_tGameLayers) {
    layer->Init();
  }
}


void Game::UpdateGame() {

  while (!SYS_GottaQuit()) {
    m_Timer.InitSlotsToProcess();
    while (m_Timer.ProcessSlots()) {
      for (Layer* layer : m_tGameLayers) {
        layer->Update(m_Timer.GetDeltaTime());
      }
      m_Timer.ProcessFixedTime();
    }
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