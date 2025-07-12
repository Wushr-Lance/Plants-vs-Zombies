#include "Background.hpp"
#include <iostream>

Background::Background(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld)
    : GameObject(imageID, x, y, layer, width, height, animID, gameWorld) { }

Background::~Background() {}

void Background::Update() {}

void Background::OnClick() {}