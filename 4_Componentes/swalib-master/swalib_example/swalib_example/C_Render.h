#pragma once
#include "Component.h"
#include "../../common/vector2d.h"

class C_Movement;
class C_Render :
    public Component
{
private:
  vec2 m_vPos;
  vec2 m_vOffset;
  float m_fRadius;
  unsigned int m_uCurrentBall;
  C_Movement* m_pCMovement = nullptr;
public:
  C_Render(Entity* _pOwner, const vec2& _vPos, const vec2& _vOffset, float _fRadius, unsigned int _uCurrentBall);
  const vec2& GetPos();
  const float GetRadius();
  const unsigned int GetCurrentBall();
  void SetPos(const vec2& _vPos);
  void SetRadius(float _fRadius);
  void SetCurrentBall(unsigned int _uCurrentBall);

  virtual void Init() override;
  virtual void Slot(double _dDeltaTime) override;
};

