#ifndef GAMEOBJECT_HPP__
#define GAMEOBJECT_HPP__

#include <memory>
#include "ObjectBase.hpp"

// Declares the class name GameWorld so that its pointers can be used.
class GameWorld;
using pGameWorld = std::shared_ptr<GameWorld>;

class GameObject : public ObjectBase, public std::enable_shared_from_this<GameObject> {
public:
  using std::enable_shared_from_this<GameObject>::shared_from_this;

  GameObject(ImageID imageID, int x, int y, LayerID layer, int width, int height, AnimID animID, pGameWorld gameWorld);
  virtual ~GameObject();

  virtual void Update() = 0;
  virtual void OnClick() = 0;
  virtual void Collision();

  bool IsDeleted() const;
  bool IsZombie() const;
  bool IsPlant() const;

protected:
  bool isDeleted = false;
  bool isZombie = false;
  bool isPlant = false;
  pGameWorld gameWorld;
};



#endif // !GAMEOBJECT_HPP__
