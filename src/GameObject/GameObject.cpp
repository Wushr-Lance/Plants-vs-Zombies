#include "GameObject.hpp"

// Your everything begins from here.
GameObject::GameObject(int imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld)
    :ObjectBase(imageID, x, y, layer, width, height, animID), gameWorld(gameWorld) {}

GameObject::~GameObject() {}

void GameObject::Collision() {}

bool GameObject::IsDeleted() const { return isDeleted; }
bool GameObject::IsZombie() const { return isZombie; }
bool GameObject::IsPlant() const { return isPlant; }



