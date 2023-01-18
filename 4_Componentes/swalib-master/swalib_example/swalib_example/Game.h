#pragma once
#include "../../common/vector2d.h"
#include "Timer.h"

class Layer;
class LogicLayer;
class RenderLayer;

class Game
{
public:
  const unsigned int NUM_BALLS = 10;	// Max. num balls.
	float MAX_BALL_SPEED = 8.0f;	// Max vel. of ball. (pixels/?).
	GLuint texbkg, texsmallball;
	Timer m_Timer;
	Layer* m_tGameLayers[2];
	
	void InitGame();
	void UpdateGame();
	void EndGame();
private:
	const unsigned int NUM_LAYERS = 2;
};

