#include "Entity.h"
#include "Component.h"


Entity::Entity(unsigned int _uEntityId)
  : m_uEntityId(_uEntityId)
{}
Entity::~Entity()
{
  for (Component* pComponent : m_tComponentList)
  {
    delete pComponent;
  }
}
bool Entity::operator==(const Entity& _pOther)
{
  return m_uEntityId == _pOther.m_uEntityId;
}
bool Entity::operator!=(const Entity& _pOther)
{
  return m_uEntityId != _pOther.m_uEntityId;
}

unsigned int Entity::GetEntityId() { return m_uEntityId; }
void Entity::SetEntityId(unsigned int _uEntityId) { m_uEntityId = _uEntityId; }

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