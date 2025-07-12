#include "SeedBase.hpp"
#include "GameWorld.hpp"

SeedBase::SeedBase(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int CD, int price)
    : GameObject(imageID, x, y, layer, width, height, animID, gameWorld), CD(CD), price(price) {}

SeedBase::~SeedBase() {}

void SeedBase::Update() {}

void SeedBase::OnClick() {
    if (gameWorld->GetSunNumber() >= price) {
        gameWorld->ChangeSun(-price);
        gameWorld->AddAGameObject(std::make_shared<CooldownMusk>(IMGID_COOLDOWN_MASK, GetX(), GetY(), LAYER_COOLDOWN_MASK, 50, 70,
                                                             ANIMID_NO_ANIMATION, gameWorld, CD));
        gameWorld->SetSelectedSeed(this);
    }
}

