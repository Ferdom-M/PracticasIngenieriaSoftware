#pragma once
#include <vector>

class Entity;
class World
{
private: 
  unsigned int m_uNumEntities = 0;
  std::vector<Entity*> m_tEntities;
public:
  World();
  ~World();
  unsigned int AddEntity(Entity* _pNewEntity);
  Entity* GetEntity(unsigned int _uEntityId);

  void Init();
  void Slot(double _dDeltaTime);
};

