#pragma once
#include <list>
class Component;
class Entity
{
protected: 
  std::list<Component*> m_tComponentList;
  unsigned int m_uEntityId = -1;
public:
  Entity() = default;
  Entity(unsigned int _uEntityId);
  ~Entity();
  bool operator==(const Entity& _pOther);
  bool operator!=(const Entity& _pOther);
  
  unsigned int GetEntityId();
  void SetEntityId(unsigned int _uEntityId);
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

