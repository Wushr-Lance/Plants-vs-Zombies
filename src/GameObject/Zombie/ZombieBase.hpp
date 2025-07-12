#ifndef ZOMBIEBASE_HPP__
#define ZOMBIEBASE_HPP__

#include "GameObject.hpp"

class ZombieBase : public GameObject {
public:
  ZombieBase(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP);
  ~ZombieBase();

  void OnClick() override;

  void Collision() override;

  void SetHP(int);

  int GetHP() const;

protected:
  bool isWalking = true;
  int HP;

  private:
      bool isCollidedWithPlant = false;
};

#endif // !ZOMBIEBASE_HPP__
