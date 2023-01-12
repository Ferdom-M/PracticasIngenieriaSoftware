#pragma once
#include "../../common/stdafx.h"
class Timer
{
private:
  LARGE_INTEGER frequency;
  LARGE_INTEGER previousTime, currentTime;
  LARGE_INTEGER logicStartTime, logicFinishedTime;
  double ellapsedTime = 0, deltaTime = 0, fixedTime = 1.f / 60.f, totalTime = 0, logicTime = 0;
public:
  Timer();

  void InitSlotsToProcess();
  bool ProcessSlots();
  void ProcessFixedTime();
  void InitLogicTime();
  void ProcessLogicTime();
  double GetDeltaTime();
  double GetTotalTime();
  double GetLogicTime();
};

