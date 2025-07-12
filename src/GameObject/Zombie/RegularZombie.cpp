#include "RegularZombie.hpp"

RegularZombie::RegularZombie(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP)
                            : ZombieBase(imageID, x, y, layer, width, height, animID, gameWorld, HP) { }

RegularZombie::~RegularZombie() { }

void RegularZombie::Update() {
    if (HP <= 0) {
        isDeleted = true;
    }
    if (isWalking) {
        MoveTo(GetX() - 1, GetY());
    }
}