#ifndef PLANTINGSPOT_HPP__
#define PLANTINGSPOT_HPP__

#include "GameObject.hpp"

class PlantingSpot : public GameObject {
public:
  PlantingSpot(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld);
  ~PlantingSpot();

  void Update() override;
  void OnClick() override;

};
 
#endif // !PLANTINGSPOT_HPP__