#pragma once

class Entity;
struct Message;
class Component
{
protected: 
  Entity* m_pOwner;
public:
  Component(Entity* _pOwner);
  virtual void ReceiveMessage(Message* _pMessage) = 0;
  virtual void Init() = 0;
  virtual void Slot(const double _dDeltaTime) = 0;
};

