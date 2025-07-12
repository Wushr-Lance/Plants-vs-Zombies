#ifndef SUN_HPP__
#define SUN_HPP__

#include "GameObject.hpp"

class Sun : public GameObject {
public:
    Sun(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld, int dropTime, bool isNatural);
    ~Sun();

    void Update() override;
    void OnClick() override;

private:
    int dropTime;
    int lifeTime = 0;
    int stayTime = 0;
    bool isNatural;
};

#endif // !SUN_HPP__