#pragma once
#include <vector>
#include "GameObject.h"
#include <string>
#include "Character.h"

class Scene
{
private:
    std::string name;
    std::vector<GameObject*> gameObjects;
    std::vector<Character*> characters;

public:
    Scene(const std::string& name);
    ~Scene();

    std::string getName() const;

    void addGameObject(GameObject* object);
    void addCharacter(Character* character);

    std::string listAvailableElements() const;
    bool isAvailable(const std::string& searchName) const;
    bool isGameObject(const std::string& searchName) const;

    GameObject* findGameObject(const std::string& searchName) const;
    Character* findCharacter(const std::string& searchName) const;
};