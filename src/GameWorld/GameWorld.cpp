#include "GameWorld.hpp"
#include <algorithm>
#include <iostream>

GameWorld::GameWorld() {}

GameWorld::~GameWorld() {}

void GameWorld::Init() {
  // YOUR CODE HERE
  sunNumber = 50;
  initialSunDropTimer = 0;
  sunDropTimer = 0;
  initialZombieGenerateTimer = 0;
  zombieGenerateTimer = 0;
  wave = 0;
  isTakingShovel = false;

  // initialize texts
  textSunNumber = std::make_shared<TextBase>(60, WINDOW_HEIGHT - 80, std::to_string(sunNumber));
  textWaveOnGoing = std::make_shared<TextBase>(WINDOW_WIDTH - 180, 10, "Wave: " + std::to_string(wave));
  textWaveLosing = std::make_shared<TextBase>(335, 50, "");
  textWaveLosing->SetColor(1, 1, 1);

  // create Background
  auto background = std::make_shared<Background>(IMGID_BACKGROUND, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, LAYER_BACKGROUND, WINDOW_WIDTH, WINDOW_HEIGHT, ANIMID_NO_ANIMATION, shared_from_this());
  gameObjects.push_back(background);



  // create 45 Planting Spots
  for (int row = 0; row < GAME_ROWS; row++) {
    for (int col = 0; col < GAME_COLS; col++) {
      auto plantingSpot = std::make_shared<PlantingSpot>(IMGID_NONE, FIRST_COL_CENTER + col * LAWN_GRID_WIDTH, FIRST_ROW_CENTER + row * LAWN_GRID_HEIGHT, 
                                                        LAYER_UI, 60, 80, ANIMID_NO_ANIMATION, shared_from_this());
      gameObjects.push_back(plantingSpot);
    }
  }

  // create Seeds
  auto sunflowerSeed = std::make_shared<SunflowerSeed>(IMGID_SEED_SUNFLOWER, 130, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, shared_from_this(),
                                              240, 50);
  gameObjects.push_back(sunflowerSeed);
  auto peashooterSeed = std::make_shared<PeashooterSeed>(IMGID_SEED_PEASHOOTER, 130 + 60, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, shared_from_this(),
                                              240, 50);
  gameObjects.push_back(peashooterSeed);
  auto wallnutSeed = std::make_shared<WallnutSeed>(IMGID_SEED_WALLNUT, 130 + 60 * 2, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, shared_from_this(),
                                              900, 50);
  gameObjects.push_back(wallnutSeed);
  auto cherryBombSeed = std::make_shared<CherryBombSeed>(IMGID_SEED_CHERRY_BOMB, 130 + 60 * 3, WINDOW_HEIGHT - 44, LAYER_UI, 50, 70, ANIMID_NO_ANIMATION, shared_from_this(),
                                              1200, 150);
  gameObjects.push_back(cherryBombSeed);

  // create Shovel
  auto shovel = std::make_shared<Shovel>(IMGID_SHOVEL, 600, WINDOW_HEIGHT - 40, LAYER_UI, 50, 50, ANIMID_NO_ANIMATION, shared_from_this());
  gameObjects.push_back(shovel);
}

LevelStatus GameWorld::Update() {
  // YOUR CODE HERE

  // drop sun
  if (initialSunDropTimer <= 180) {
    if (initialSunDropTimer == 180) {
      DropSun();
    }
    initialSunDropTimer++;
  } else {
    if (sunDropTimer == 300) {
      DropSun();
      sunDropTimer = 0;
    }
    sunDropTimer++;
  }

  // generate zombies
  if (initialZombieGenerateTimer <=1200) {
    if (initialZombieGenerateTimer == 1200) {
      wave++;
      for (int i = 0; i != ((15 + wave) / 10); i++) {
        auto zombie = std::make_shared<RegularZombie>(IMGID_REGULAR_ZOMBIE, randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), randInt(0, 4) * LAWN_GRID_HEIGHT + FIRST_ROW_CENTER,
                                                      LAYER_ZOMBIES, 20, 80, ANIMID_WALK_ANIM, shared_from_this(), 200);
        gameObjects.push_back(zombie);
      }
    }
    initialZombieGenerateTimer++;
  } else {
    if (zombieGenerateTimer == std::max(150, 600 - 20 * wave)) {
      wave++;
      for (int i = 0; i != ((15 + wave) / 10); i++) {
        auto zombie = std::make_shared<RegularZombie>(IMGID_REGULAR_ZOMBIE, randInt(WINDOW_WIDTH - 40, WINDOW_WIDTH - 1), randInt(0, 4) * LAWN_GRID_HEIGHT + FIRST_ROW_CENTER,
                                                      LAYER_ZOMBIES, 20, 80, ANIMID_WALK_ANIM, shared_from_this(), 200);
        gameObjects.push_back(zombie);
      }
      zombieGenerateTimer = 0;
    }
    zombieGenerateTimer++;
  }

  // update wave
  textWaveOnGoing->SetText("Wave: " + std::to_string(wave));

  // check Collisions and judge losing
  for (auto &obj : gameObjects) {
    obj->Collision();
    if (obj->IsZombie() && obj->GetX() < 0) {
      textWaveLosing->SetText(std::to_string(wave));
      return LevelStatus::LOSING;
    }
  }

  // update gameObjects
  for (auto obj = gameObjects.begin(); obj != gameObjects.end(); obj++) {
      (*obj)->Update();
  }


  // delete some gameObjects
  for (auto obj = gameObjects.begin(); obj != gameObjects.end();) {
    if ((*obj)->IsDeleted()) {
      obj = gameObjects.erase(obj);
    } else {
      obj++;
    }
    
  }


  return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
  // YOUR CODE HERE
  gameObjects.clear();
}

void GameWorld::AddAGameObject(std::shared_ptr<GameObject> gameObject) {
  gameObjects.push_back(gameObject);
}

void GameWorld::DropSun() {
  auto sun = std::make_shared<Sun>(IMGID_SUN, randInt(75, WINDOW_WIDTH - 75), WINDOW_HEIGHT - 1, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, shared_from_this(),
                                   randInt(63, 263), true);
  gameObjects.push_back(sun);
}

void GameWorld::ChangeSun(int n) {
  sunNumber += n;
  textSunNumber->SetText(std::to_string(sunNumber));
}

int GameWorld::GetSunNumber() const {
  return sunNumber;
}

void GameWorld::SetSelectedSeed(SeedBase *seed) {
  selectedSeed = seed;
}

SeedBase *GameWorld::GetSelectedSeed() const {
  return selectedSeed;
}

void GameWorld::SunflowerGenerateSun(int x, int y) {
  auto sun = std::make_shared<Sun>(IMGID_SUN, x, y, LAYER_SUN, 80, 80, ANIMID_IDLE_ANIM, shared_from_this(),
                                   12, false);
  gameObjects.push_back(sun);
}

bool GameWorld::IsTakingShovel() const {
  return isTakingShovel;
}

void GameWorld::TakeShovel() {
  isTakingShovel = true;
}

void GameWorld::PutShovel() {
  isTakingShovel = false;
}

std::list<std::shared_ptr<GameObject>> GameWorld::GetGameObjects() const {
  return gameObjects;
}