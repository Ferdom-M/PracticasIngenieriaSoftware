#include "Entity.h"
#include "Component.h"


void Entity::AddComponent(Component* _pNewComponent) 
{
  m_tComponentList.push_back(_pNewComponent);
}
void Entity::Init()
{
  for (Component* component : m_tComponentList)
  {
    component->Init();
  }
}
void Entity::Slot(double _dDeltaTime) 
{
  for (Component* component : m_tComponentList)
  {
    component->Slot(_dDeltaTime);
  }
}