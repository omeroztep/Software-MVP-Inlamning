#include "GameObjectRepository.h"

GameObjectRepository::GameObjectRepository()
{
}

GameObjectRepository::~GameObjectRepository()
{
    // Repository äger inte objekten och ska därför inte delete:a dem.
}

void GameObjectRepository::addGameObject(GameObject* obj)
{
    myGameObjects.push_back(obj);
}

GameObject* GameObjectRepository::getGameObject(const std::string& name) const
{
    for (size_t i = 0; i < myGameObjects.size(); i++)
    {
        if (myGameObjects[i]->getName() == name)
            return myGameObjects[i];
    }
    return nullptr;
}