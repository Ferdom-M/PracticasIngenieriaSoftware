#include "../../../common/stdafx.h"
#include "../../../common/core.h"
#include "global.h"
#include "../../swalib_example/Terrain.h"
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void InitGlobalData()
{
	NewWorld::Get()->GenerateTerrain();
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void ShutDownGlobalData()
{
    NewWorld::Get()->DestroyTerrain();
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

World* World::m_WorldInstance = nullptr;

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

World* World::Get()
{
	if (m_WorldInstance == nullptr)
	{
		m_WorldInstance = new World;
	}
	return m_WorldInstance;
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void World::GenerateTerrain()
{
	for (int i = 0; i < WORLD_WIDTH * WORLD_HEIGHT; i++)
	{
		unsigned int uTerrain = std::rand() % TILE_TYPES;
		Terrain* pTerrain = new Terrain(uTerrain, vec2(i % WORLD_WIDTH, i / WORLD_WIDTH), uTerrain);
		m_tTerrains[i] = pTerrain;
	}
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void World::DestroyTerrain()
{
	delete[]m_tTerrains;
}


//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

NewWorld* NewWorld::m_WorldInstance = nullptr;

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

NewWorld* NewWorld::Get()
{
	if (m_WorldInstance == nullptr)
	{
		m_WorldInstance = new NewWorld;
	}
	return m_WorldInstance;
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void NewWorld::GenerateTerrain()
{
	for (int i = 0; i < TILE_TYPES; i++)
	{
		unsigned int uTerrain = i;
		NewTerrain* pTerrain = new NewTerrain(uTerrain, uTerrain);
		m_tTerrains[i] = pTerrain;
	}
	for (int i = 0; i < WORLD_HEIGHT * WORLD_WIDTH; i++)
	{
		m_tTiles[i].m_vPos = vec2(i % WORLD_WIDTH, i / WORLD_WIDTH);
		m_tTiles[i].m_uTerrainType = std::rand() % TILE_TYPES;
	}
}

//////////////////////////////////////////////////////////////////////////
///
//////////////////////////////////////////////////////////////////////////

void NewWorld::DestroyTerrain()
{
	delete[]m_tTerrains;
}