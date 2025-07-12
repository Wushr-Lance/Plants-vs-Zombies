#include "Seed.hpp"
#include "GameWorld.hpp"

SunflowerSeed::SunflowerSeed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price)
    : SeedBase(imageID, x, y, layer, width, height, animID, gameWorld, CD, price) {}

SunflowerSeed::~SunflowerSeed() {}



void SunflowerSeed::Plant(int x, int y) {
    gameWorld->AddAGameObject(std::make_shared<Sunflower>(IMGID_SUNFLOWER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, gameWorld));
}

PeashooterSeed::PeashooterSeed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price)
    : SeedBase(imageID, x, y, layer, width, height, animID, gameWorld, CD, price) {}

PeashooterSeed::~PeashooterSeed() {}



void PeashooterSeed::Plant(int x, int y) {
    gameWorld->AddAGameObject(std::make_shared<Peashooter>(IMGID_PEASHOOTER, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, gameWorld));
}

WallnutSeed::WallnutSeed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price)
    : SeedBase(imageID, x, y, layer, width, height, animID, gameWorld, CD, price) {}

WallnutSeed::~WallnutSeed() {}



void WallnutSeed::Plant(int x, int y) {
    gameWorld->AddAGameObject(std::make_shared<Wallnut>(IMGID_WALLNUT, x, y, LAYER_PLANTS, 50, 70, ANIMID_IDLE_ANIM, gameWorld));
}

CherryBombSeed::CherryBombSeed(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price)
    : SeedBase(imageID, x, y, layer, width, height, animID, gameWorld, CD, price) {}

CherryBombSeed::~CherryBombSeed() {}



void CherryBombSeed::Plant(int x, int y) {
    gameWorld->AddAGameObject(std::make_shared<CherryBomb>(IMGID_CHERRY_BOMB, x, y, LAYER_PLANTS, 60, 80, ANIMID_IDLE_ANIM, gameWorld));
}

