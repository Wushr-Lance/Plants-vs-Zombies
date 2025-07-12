#include "Peashooter.hpp"
#include "GameWorld.hpp"
#include <iostream>

Peashooter::Peashooter(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP)
    :PlantBase(imageID, x, y, layer, width, height, animID, gameWorld, HP) {}

Peashooter::~Peashooter() {}

void Peashooter::Update() {
    if (HP <= 0) {
        isDeleted = true;
    }
    if (generatePeaTimer == 0) {
        for (auto &obj : gameWorld->GetGameObjects()) {
            if (obj->IsZombie()) {
                if (GetY() == obj->GetY()) {
                    gameWorld->AddAGameObject(std::make_shared<Pea>(IMGID_PEA, GetX() + 30, GetY() + 20, LAYER_PROJECTILES, 28, 28, ANIMID_NO_ANIMATION, gameWorld));
                }
            }
        }
        generatePeaTimer = 30;
    }
    generatePeaTimer--;
}
