#pragma once
#include <vector>
#include <string>
#include "GameObject.h"

// Repository används för att kunna lagra och hitta spelobjekt centralt.
// I denna lösning äger repository inte objekten, utan håller bara referenser.
class GameObjectRepository
{
private:
    std::vector<GameObject*> myGameObjects;

public:
    GameObjectRepository();
    ~GameObjectRepository();

    void addGameObject(GameObject* obj);
    GameObject* getGameObject(const std::string& name) const;
};