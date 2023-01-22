#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include "../../../common/sys.h"
#include <cstdint>
#include "../../../common/stdafx.h"
#include "../../../common/core.h"
#include <gl/GL.h>

#include "../../swalib_example/Terrain.h"
const unsigned int WORLD_WIDTH = 10;
const unsigned int WORLD_HEIGHT = 10;
const unsigned int TILE_TYPES = 10;
const float TILE_WIDTH = SCR_WIDTH / WORLD_WIDTH;
const float TILE_HEIGHT = SCR_HEIGHT / WORLD_HEIGHT;

/** 
*	Class to represent the game playable world
*	It's composed by a matrix of terrains
*/
class World
{
public:
	// Singleton accessor
	static World* Get();

	/** Method that generate the terrain randomly*/
	void GenerateTerrain();

	/** Delete terrain tiles and free the terrain textures*/
	void DestroyTerrain();

	Terrain* m_tTerrains[WORLD_HEIGHT * WORLD_WIDTH];
	uint32_t m_tGfxs[TILE_TYPES];
private:
	World() { }
private:

	static World* m_WorldInstance;
};

class NewWorld
{
public:
	// Singleton accessor
	static NewWorld* Get();

	/** Method that generate the terrain randomly*/
	void GenerateTerrain();

	/** Delete terrain tiles and free the terrain textures*/
	void DestroyTerrain();

	NewTerrain* m_tTerrains[TILE_TYPES];
	Tile m_tTiles[WORLD_HEIGHT * WORLD_WIDTH];
	uint32_t m_tGfxs[TILE_TYPES];
private:
	NewWorld() { }
private:

	static NewWorld* m_WorldInstance;
};

// Initialization global data.
void InitGlobalData();
// Shutdown global data.
void ShutDownGlobalData();

#endif // !_GLOBAL_H_
