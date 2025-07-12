#include "Shovel.hpp"
#include "GameWorld.hpp"

Shovel::Shovel(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld)
                : GameObject(imageID, x, y, layer, width, height, animID, gameWorld) { }

Shovel::~Shovel() { }

void Shovel::Update() { }

void Shovel::OnClick() {
    if (gameWorld->GetSelectedSeed() == nullptr) {
        if (gameWorld->IsTakingShovel()) {
            gameWorld->PutShovel();
        }
        else {
            gameWorld->TakeShovel();
        }
    }
}