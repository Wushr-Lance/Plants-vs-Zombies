#include "Wallnut.hpp"
#include "GameWorld.hpp"
#include <iostream>

Wallnut::Wallnut(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP)
    :PlantBase(imageID, x, y, layer, width, height, animID, gameWorld, HP) {}

Wallnut::~Wallnut() {}

void Wallnut::Update() {
    if (HP <= 0) {
        isDeleted = true;
    }
    if (HP > 0 && HP < (4000 / 3)) {
        ChangeImage(IMGID_WALLNUT_CRACKED);
    }
}
