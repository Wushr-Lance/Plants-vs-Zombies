#include "PlantingSpot.hpp"
#include "GameWorld.hpp"
#include <iostream>

PlantingSpot::PlantingSpot(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld)
    : GameObject(imageID, x, y, layer, width, height, animID, gameWorld) { }

PlantingSpot::~PlantingSpot() {}

void PlantingSpot::Update() {}

void PlantingSpot::OnClick() {
    auto selectedSeed = gameWorld->GetSelectedSeed();
    if (selectedSeed) {
        selectedSeed->Plant(GetX(), GetY());
        gameWorld->SetSelectedSeed(nullptr);
    }
}