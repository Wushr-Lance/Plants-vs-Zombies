#ifndef PEASHOOTER_HPP__
#define PEASHOOTER_HPP__

#include "PlantBase.hpp"

class Peashooter : public PlantBase {
public:
  Peashooter(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP = 300);
  ~Peashooter();

  void Update() override;

private:
  int generatePeaTimer = 30;
};
 
#endif // !PEASHOOTER_HPP__