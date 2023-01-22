#pragma once
#include "../../common/vector2d.h"

class Terrain
{
private:
  int m_uNavCost;
  vec2 m_vPos;
  unsigned int m_uGfxId;
public:
  Terrain(unsigned int _uNavCost, const vec2& _vPos, unsigned int _uGfxId);
  void Draw();
};
class NewTerrain
{
private:
  int m_uNavCost;
  unsigned int m_uGfxId;
public:
  NewTerrain(unsigned int _uNavCost, unsigned int _uGfxId);
  void Draw(const vec2& _vPos);
};

struct Tile
{
  vec2 m_vPos;
  unsigned int m_uTerrainType;
};