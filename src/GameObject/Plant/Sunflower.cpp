#include "Sunflower.hpp"
#include "GameWorld.hpp"
#include <iostream>

Sunflower::Sunflower(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP)
    :PlantBase(imageID, x, y, layer, width, height, animID, gameWorld, HP) {}

Sunflower::~Sunflower() {}

void Sunflower::Update() {
    if (HP <= 0) {
        isDeleted = true;
    }
    if (generateSunTimer == 0) {
        gameWorld->SunflowerGenerateSun(GetX(), GetY());
        generateSunTimer = 600;
    }
    generateSunTimer--;
}
