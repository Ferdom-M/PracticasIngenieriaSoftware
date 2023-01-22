#include "Terrain.h"
#include <stdio.h>
#include "../Code/Game/global.h"


Terrain::Terrain(unsigned int _uNavCost, const vec2& _vPos, unsigned int _uGfxId)
  : m_uNavCost(_uNavCost)
  , m_vPos(_vPos)
  , m_uGfxId(_uGfxId)
{}

void Terrain::Draw()
{
  CORE_RenderCenteredSprite(vec2(TILE_WIDTH / 2 + m_vPos.x * TILE_WIDTH, TILE_HEIGHT / 2 + m_vPos.y * TILE_HEIGHT), vec2(TILE_WIDTH, TILE_HEIGHT), World::Get()->m_tGfxs[m_uGfxId]);
}

NewTerrain::NewTerrain(unsigned int _uNavCost, unsigned int _uGfxId)
  : m_uNavCost(_uNavCost)
  , m_uGfxId(_uGfxId)
{}

void NewTerrain::Draw(const vec2& _vPos)
{
  CORE_RenderCenteredSprite(vec2(TILE_WIDTH / 2 + _vPos.x * TILE_WIDTH, TILE_HEIGHT / 2 + _vPos.y * TILE_HEIGHT), vec2(TILE_WIDTH, TILE_HEIGHT), World::Get()->m_tGfxs[m_uGfxId]);
}