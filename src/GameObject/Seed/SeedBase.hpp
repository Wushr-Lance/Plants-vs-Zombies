#ifndef SEEDBASE_HPP__
#define SEEDBASE_HPP__

#include "GameObject.hpp"

class SeedBase : public GameObject {
public:
  SeedBase(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price);
  ~SeedBase();

  void Update() override;
  void OnClick() override;

  virtual void Plant(int x, int y) = 0;

protected:
  int CD;
  int price;
};

#endif // !SEEDBASE_HPP__
