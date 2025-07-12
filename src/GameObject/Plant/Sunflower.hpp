#ifndef SUNFLOWER_HPP__
#define SUNFLOWER_HPP__

#include "PlantBase.hpp"

class Sunflower : public PlantBase {
public:
  Sunflower(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP = 300);
  ~Sunflower();

  void Update() override;

private:
  int generateSunTimer = randInt(30, 600);
};
 
#endif // !SUNFLOWER_HPP__