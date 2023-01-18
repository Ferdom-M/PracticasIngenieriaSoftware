#include "Entity.h"


void Entity::AddComponent(Component* _pNewComponent) 
{
  m_tComponentList.push_back(_pNewComponent);
}

template<class T>
T* Entity::FindComponent() 
{
  for (auto componentIt = m_tComponentList.begin();
    componentIt != m_tComponentList.end();
    ++componentIt)
  {
    T* component = dynamic_cast<T*>(*(*componentIt));
    if (component)
    {
      return component;
    }
  }
  return NULL;
}

void Entity::Slot(double _dDeltaTime) 
{
  for (auto componentIt = m_tComponentList.begin();
    componentIt != m_tComponentList.end();
    ++componentIt)
  {
    (*componentIt)->Slot(_dDeltaTime);
  }
}