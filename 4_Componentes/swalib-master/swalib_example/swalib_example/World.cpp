#include "World.h"
#include "Entity.h"


World::World()
{}
World::~World()
{
  for (Entity* pEntity : m_tEntities)
  {
    delete pEntity;
  }
}
unsigned int World::AddEntity(Entity* _pNewEntity)
{
  m_uNumEntities++;
  _pNewEntity->SetEntityId(m_uNumEntities - 1);
  m_tEntities.push_back(_pNewEntity);
  
  return m_uNumEntities - 1;
}
Entity* World::GetEntity(unsigned int _uEntityId)
{
  return m_tEntities[_uEntityId];
}

void World::Init()
{
  for (Entity* pEntity : m_tEntities)
  {
    pEntity->Init();
  }
}
void World::Slot(double _dDeltaTime)
{
  for (Entity* pEntity : m_tEntities)
  {
    pEntity->Slot(_dDeltaTime);
  }
}