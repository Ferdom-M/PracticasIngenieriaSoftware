#include "Component.h"
#include "Entity.h"

Component::Component(Entity* _pOwner)
  : m_pOwner(_pOwner)
{}