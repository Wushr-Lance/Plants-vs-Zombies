#include "ZombieBase.hpp"
#include "GameWorld.hpp"
#include <iostream>

ZombieBase::ZombieBase(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP)
    : GameObject(imageID, x, y, layer, width, height, animID, gameWorld), HP(HP) { isZombie = true; }

ZombieBase::~ZombieBase() { }

void ZombieBase::OnClick() { }

void ZombieBase::Collision() {
    isCollidedWithPlant = false;
    for (auto &obj : gameWorld->GetGameObjects()) {
        if (obj->IsPlant() && abs(GetX() - obj->GetX()) < (GetWidth() / 2 + obj->GetWidth() / 2) && GetY() == obj->GetY()) {
            isCollidedWithPlant = true;
        }
        if (obj == gameWorld->GetGameObjects().back()) {
            if (isCollidedWithPlant && isWalking) {
                PlayAnimation(ANIMID_EAT_ANIM);
                isWalking = false;
            }
            if (!isCollidedWithPlant && !isWalking) {
                PlayAnimation(ANIMID_WALK_ANIM);
                isWalking = true;
            }
        }   
    }
}

void ZombieBase::SetHP(int newHP) {
    HP = newHP;
}

int ZombieBase::GetHP() const {
    return HP;
}