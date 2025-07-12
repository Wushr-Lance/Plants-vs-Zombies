#ifndef EXPLOSION_HPP__
#define EXPLOSION_HPP__

#include "GameObject.hpp"

class Explosion : public GameObject {
public:
    Explosion(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld);
    ~Explosion();

    void Update() override;

    void OnClick() override;

    void Collision() override;

private:
    int explosionDoneTimer = 0;
};



#endif // !EXPLOSION_HPP__