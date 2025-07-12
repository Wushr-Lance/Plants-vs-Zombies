#ifndef CHERRYBOMB_HPP__
#define CHERRYBOMB_HPP__

#include "PlantBase.hpp"

class CherryBomb : public PlantBase {
public:
  CherryBomb(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP = 4000);
  ~CherryBomb();

  void Update() override;

private:
    int explosionTimer = 15;
};
 
#endif // !CHERRYBOMB_HPP__