#ifndef REGULARZOMBIE_HPP__
#define REGULARZOMBIE_HPP__

#include "ZombieBase.hpp"

class RegularZombie : public ZombieBase {
public:
  RegularZombie(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP);
  ~RegularZombie();

  void Update() override;

};
 
#endif // !REGULARZOMBIE_HPP__