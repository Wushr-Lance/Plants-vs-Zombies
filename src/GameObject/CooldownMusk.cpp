#include "CooldownMusk.hpp"

CooldownMusk::CooldownMusk(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, 
    int lifeSpan) : GameObject(imageID, x, y, layer, width, height, animID, gameWorld), lifeSpan(lifeSpan) {}

CooldownMusk::~CooldownMusk() {}

void CooldownMusk::Update() {
    isDeleted = (stayTime >= lifeSpan);
    stayTime++;
}

void CooldownMusk::OnClick() {}

