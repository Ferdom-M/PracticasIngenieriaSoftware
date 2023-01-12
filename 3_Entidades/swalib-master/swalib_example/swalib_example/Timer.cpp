#include "Timer.h"

Timer::Timer()
  : currentTime()
  , logicStartTime()
  , logicFinishedTime()
{
  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&previousTime);
}
void Timer::InitSlotsToProcess() {
  QueryPerformanceCounter(&currentTime);
  ellapsedTime = static_cast<float>(currentTime.QuadPart - previousTime.QuadPart) / frequency.QuadPart;
  deltaTime += ellapsedTime;
  totalTime += ellapsedTime;
  previousTime = currentTime;
}
bool Timer::ProcessSlots() {
  return deltaTime >= fixedTime;
}
void Timer::ProcessFixedTime() {
  deltaTime = deltaTime - fixedTime;
  if (deltaTime > 1.f / 15.f) {
    deltaTime = 0;
  }
}
void Timer::InitLogicTime() {
  QueryPerformanceCounter(&logicStartTime);
}
void Timer::ProcessLogicTime() {
  QueryPerformanceCounter(&logicFinishedTime);
  logicTime += static_cast<float>(logicFinishedTime.QuadPart - logicStartTime.QuadPart) / frequency.QuadPart;
}
double Timer::GetDeltaTime() { return deltaTime; }
double Timer::GetTotalTime() { return totalTime; }
double Timer::GetLogicTime() { return logicTime; }
