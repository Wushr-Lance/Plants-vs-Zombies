#ifndef SHOVEL_HPP__
#define SHOVEL_HPP__

#include "GameObject.hpp"

class Shovel : public GameObject {
public:
  Shovel(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld);
  ~Shovel();

  void Update() override;
  void OnClick() override;


};

#endif // !SHOVEL_HPP__
