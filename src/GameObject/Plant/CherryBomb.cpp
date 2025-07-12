#include "CherryBomb.hpp"
#include "GameWorld.hpp"

CherryBomb::CherryBomb(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int HP)
    :PlantBase(imageID, x, y, layer, width, height, animID, gameWorld, HP) {}

CherryBomb::~CherryBomb() {}

void CherryBomb::Update() {
    if (explosionTimer == 0) {
        gameWorld->AddAGameObject(std::make_shared<Explosion>(IMGID_EXPLOSION, GetX(), GetY(), LAYER_PROJECTILES, 3 * LAWN_GRID_WIDTH, 3 * LAWN_GRID_HEIGHT, ANIMID_NO_ANIMATION, gameWorld));
        isDeleted = true;
    }
    explosionTimer--;
}