#ifndef SEED_HPP__
#define SEED_HPP__

#include "SeedBase.hpp"

class SunflowerSeed : public SeedBase {
public:
  SunflowerSeed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price);
  ~SunflowerSeed();

  void Plant(int x, int y) override;

};

class PeashooterSeed : public SeedBase {
public:
  PeashooterSeed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price);
  ~PeashooterSeed();

  void Plant(int x, int y) override;

};

class WallnutSeed : public SeedBase {
public:
  WallnutSeed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price);
  ~WallnutSeed();

  void Plant(int x, int y) override;

};

class CherryBombSeed : public SeedBase {
public:
  CherryBombSeed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price);
  ~CherryBombSeed();

  void Plant(int x, int y) override;

};

#endif // !SEED_HPP__
