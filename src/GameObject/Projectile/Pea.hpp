#ifndef PEA_HPP__
#define PEA_HPP__

#include "GameObject.hpp"

class Pea : public GameObject {
public:
    Pea(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld);
    ~Pea();

    void Update() override;

    void OnClick() override;

    void Collision() override;
};



#endif // !PEA_HPP__