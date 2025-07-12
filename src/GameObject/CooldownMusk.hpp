#ifndef COOLDOWNMUSK_HPP__
#define COOLDOWNMUSK_HPP__

#include "GameObject.hpp"

class CooldownMusk : public GameObject {
public:
  CooldownMusk(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int lifeSpan);
  ~CooldownMusk();

  void Update() override;
  void OnClick() override;


private:
  int lifeSpan;
  int stayTime = 0;
};
 
#endif // !COOLDOWNMUSK_HPP__