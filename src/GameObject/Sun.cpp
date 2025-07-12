#include "Sun.hpp"
#include <iostream>
#include "GameWorld.hpp"

Sun::Sun(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int dropTime, bool isNatural) 
    : GameObject(imageID, x, y, layer, width, height, animID, gameWorld), dropTime(dropTime), isNatural(isNatural) {}

Sun::~Sun() {}

void Sun::Update() {
    dropTime--;
    if (dropTime >= 0) {
        if (isNatural) {
            MoveTo(GetX(), GetY() - 2);
        }
        else {
            MoveTo(GetX() - 1, GetY() + (4 * lifeTime - lifeTime * lifeTime / 2));
            lifeTime++;
        }
    }
    else {
        stayTime++;
    }
    isDeleted = (stayTime >= 300);
}

void Sun::OnClick() {
    stayTime += 300;
    gameWorld->ChangeSun(25);
}