#ifndef WALLNUT_HPP__
#define WALLNUT_HPP__

#include "PlantBase.hpp"

class Wallnut : public PlantBase {
public:
  Wallnut(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP = 4000);
  ~Wallnut();

  void Update() override;

};
 
#endif // !WALLNUT_HPP__