#include "PlantBase.hpp"
#include "GameWorld.hpp"

PlantBase::PlantBase(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP)
    : GameObject(imageID, x, y, layer, width, height, animID, gameWorld), HP(HP) { isPlant = true; }

PlantBase::~PlantBase() {}

void PlantBase::OnClick() {
    if (gameWorld->IsTakingShovel()) {
        isDeleted = true;
        gameWorld->PutShovel();
    }
}

void PlantBase::Collision() {
    for (auto &obj : gameWorld->GetGameObjects()) {
        if (obj->IsZombie()) {
            if (abs(GetX() - obj->GetX()) < (GetWidth() / 2 + obj->GetWidth() / 2)) {
                HP -= 3;
            }
        }
    }
}
