#pragma once
#include <list>
#include "Component.h"
class Entity
{
private: 
  std::list<Component*> m_tComponentList;
public:
  void AddComponent(Component* _pNewComponent);
  
  template<class T>
  T* FindComponent();

  void Slot(double _dDeltaTime);
};

