#include "Pea.hpp"
#include "GameWorld.hpp"

Pea::Pea(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld)
    : GameObject(imageID, x, y, layer, width, height, animID, gameWorld) { }

Pea::~Pea() {}

void Pea::Update() {
        MoveTo(GetX() + 8, GetY());
        if (GetX() >= WINDOW_WIDTH) {
                isDeleted = true;
        }
}

void Pea::OnClick() {}

void Pea::Collision() {
        for (auto &obj : gameWorld->GetGameObjects()) {
                if (obj->IsZombie() && abs(GetX() - obj->GetX()) < (GetWidth() / 2 + obj->GetWidth() / 2) && GetY() == (obj->GetY() + 20)) {
                        auto zombie = std::dynamic_pointer_cast<ZombieBase>(obj);
                        zombie->SetHP(zombie->GetHP() - 20);
                        isDeleted = true;
                }
        }
}