#pragma once
#include "Game.h"
#include "Layer.h"

class Ball;
class World;
class LogicLayer : public Layer
{
public:
  static LogicLayer* Get(Game* _pGame);

  virtual void Init() override;
  virtual void Update(double deltaTime) override;

  const unsigned int NUM_BALLS = 10;	// Max. num balls.
  Ball* tBalls[10];	// Array of balls.
  World* m_pWorld;
  float MAX_BALL_SPEED = 8.0f;	// Max vel. of ball. (pixels/?).
private:
	static LogicLayer* m_Instance;
  LogicLayer(Game* _pGame);

};

