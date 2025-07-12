#include "Explosion.hpp"
#include "GameWorld.hpp"

Explosion::Explosion(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld)
    : GameObject(imageID, x, y, layer, width, height, animID, gameWorld) {}

Explosion::~Explosion() {}

void Explosion::Update() {
    if (explosionDoneTimer == 3) {
        isDeleted = true;
    }
    explosionDoneTimer++;
}

void Explosion::OnClick() {}

void Explosion::Collision() {
        for (auto &obj : gameWorld->GetGameObjects()) {
                if (obj->IsZombie() && abs(GetX() - obj->GetX()) < (GetWidth() / 2 + obj->GetWidth() / 2)) {
                    auto zombie = std::dynamic_pointer_cast<ZombieBase>(obj);
                    zombie->SetHP(0);
                }
        }
}