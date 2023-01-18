#pragma once
#include <list>
class Component;
class Entity
{
protected: 
  std::list<Component*> m_tComponentList;
public:
  void AddComponent(Component* _pNewComponent);
  
  template<class T>
  T* FindComponent()
  {
    for (Component* componentIt : m_tComponentList)
    {
      T* component = dynamic_cast<T*>(componentIt);
      if (component)
      {
        return component;
      }
    }
    return NULL;
  }

  void Init();
  void Slot(double _dDeltaTime);
};

