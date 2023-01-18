#pragma once
#include "Entity.h"
class Component
{
protected: 
  Entity* m_pOwner;
public:
  Component(Entity* _pOwner);
  virtual void Init() = 0;
  virtual void Slot(const double _dDeltaTime) = 0;
};

