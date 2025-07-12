#ifndef GAMEWORLD_HPP__
#define GAMEWORLD_HPP__

#include <list>
#include <memory>

#include "WorldBase.hpp"

#include "GameObject.hpp"
#include "Background.hpp"
#include "PlantingSpot.hpp"
#include "Plant/Sunflower.hpp"
#include "Plant/Peashooter.hpp"
#include "Plant/Wallnut.hpp"
#include "Plant/CherryBomb.hpp"
#include "Sun.hpp"
#include "Seed/SeedBase.hpp"
#include "Seed/Seed.hpp"
#include "CooldownMusk.hpp"
#include "Shovel.hpp"
#include "Zombie/RegularZombie.hpp"
#include "Projectile/Pea.hpp"
#include "Projectile/Explosion.hpp"

#include "TextBase.hpp"
#include "utils.hpp"


class GameWorld : public WorldBase, public std::enable_shared_from_this<GameWorld> {
public:
  // Use shared_from_this() instead of "this" to create a pointer to oneself.
  GameWorld();
  virtual ~GameWorld();

  void Init() override;

  LevelStatus Update() override;

  void CleanUp() override;

  void AddAGameObject(std::shared_ptr<GameObject> gameObject);

  void DropSun();

  void ChangeSun(int);

  int GetSunNumber() const;

  void SetSelectedSeed(SeedBase *seed);

  SeedBase *GetSelectedSeed() const;

  void SunflowerGenerateSun(int x, int y);

  bool IsTakingShovel() const;

  void TakeShovel();

  void PutShovel();

  std::list<std::shared_ptr<GameObject>> GetGameObjects() const;

private:
  std::list<std::shared_ptr<GameObject>> gameObjects;
  std::shared_ptr<TextBase> textSunNumber;
  std::shared_ptr<TextBase> textWaveOnGoing;
  std::shared_ptr<TextBase> textWaveLosing;
  SeedBase *selectedSeed;
  int sunNumber;
  int initialSunDropTimer;
  int sunDropTimer;
  int initialZombieGenerateTimer;
  int zombieGenerateTimer;
  int wave;
  bool isTakingShovel;
};

#endif // !GAMEWORLD_HPP__
