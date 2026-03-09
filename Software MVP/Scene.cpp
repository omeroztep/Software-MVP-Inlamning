#include "Scene.h"

Scene::Scene(const std::string& name) : name(name)
{
}

Scene::~Scene()
{
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
		gameObjects[i] = nullptr;
	}

	for (size_t i = 0; i < characters.size(); i++)
	{
		delete characters[i];
		characters[i] = nullptr;
	}
}

std::string Scene::getName() const
{
	return name;
}

void Scene::addGameObject(GameObject* object)
{
	gameObjects.push_back(object);
}

void Scene::addCharacter(Character* character)
{
	characters.push_back(character);
}

std::string Scene::listAvailableElements() const
{
    std::string result = "Scen: " + name + "\n";

    for (size_t i = 0; i < gameObjects.size(); i++)
    {
        result += "Objekt: " + gameObjects[i]->getName() + "\n";
    }

    for (size_t i = 0; i < characters.size(); i++)
    {
        result += "Karaktär: " + characters[i]->getName() + "\n";
    }

    return result;
}

bool Scene::isAvailable(const std::string& searchName) const
{
    return findGameObject(searchName) != nullptr || findCharacter(searchName) != nullptr;
}

bool Scene::isGameObject(const std::string& searchName) const
{
    return findGameObject(searchName) != nullptr;
}

GameObject* Scene::findGameObject(const std::string& searchName) const
{
    for (size_t i = 0; i < gameObjects.size(); i++)
    {
        if (gameObjects[i]->getName() == searchName)
            return gameObjects[i];
    }
    return nullptr;
}

Character* Scene::findCharacter(const std::string& searchName) const
{
    for (size_t i = 0; i < characters.size(); i++)
    {
        if (characters[i]->getName() == searchName)
            return characters[i];
    }
    return nullptr;
}