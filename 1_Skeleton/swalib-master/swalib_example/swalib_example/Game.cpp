#include "Game.h"

void Game::InitGame() {

  m_tGameLayers[0] = new LogicLayer(this);
  m_tGameLayers[1] = new RenderLayer(this);

  for (Layer* layer : m_tGameLayers) {
    layer->Init();
  }
}

void Game::UpdateGame() {
  while (!SYS_GottaQuit()) {
    for (Layer* layer : m_tGameLayers) {
      layer->Update();
    }

    SYS_Sleep(17);	// To force 60 fps
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