#ifndef PLANTBASE_HPP__
#define PLANTBASE_HPP__

#include "GameObject.hpp"

class PlantBase : public GameObject {
public:
  PlantBase(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP);
  ~PlantBase();

  void OnClick() override;

  void Collision() override;

protected:
    int HP;

};
 
#endif // !PLANTBASE_HPP__