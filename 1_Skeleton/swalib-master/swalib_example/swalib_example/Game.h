#pragma once
#include "../../common/vector2d.h"
#include "../../common/stdafx.h"
#include "Layer.h"
#include "LogicLayer.h"
#include "RenderLayer.h"
// Logic Info.
struct Ball	// Info Ball
{
	vec2   pos;	// Position.
	vec2   vel;	// Velocity.
	GLuint* gfx;	// OpenGL for id. for visualization purposes. 
	float  radius;	// Radius.

	Ball() :
		pos(0.0f),
		vel(0.0f),
		gfx(0),
		radius(0.0f)
	{}
};


class Game
{
public:
  const unsigned int NUM_BALLS = 10;	// Max. num balls.
	Ball tBalls[10];	// Array of balls.
	float MAX_BALL_SPEED = 8.0f;	// Max vel. of ball. (pixels/?).
	GLuint texbkg, texsmallball;

	void InitGame();
	void UpdateGame();
	void EndGame();
private:
	const unsigned int NUM_LAYERS = 2;
	Layer* m_tGameLayers[2];
};

