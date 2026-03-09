#pragma once
#include <string>
#include "Scene.h"
#include "GameObjectRepository.h"
#include "InteractionType.h"

// Game ansvarar för spelets huvudlogik.
// Klassen håller reda på aktuell scen, inventory och valda interaktioner.
class Game
{
private:
    GameObjectRepository* myGameObjects;
    Scene* currentScene;
    Scene* playerInventory;
    GameObject* selectedGameObject;
    Character* selectedCharacter;
    InteractionType selectedInteraction;

public:
    Game();
    ~Game();

    void setup();

    void selectGameObject(const std::string& name);
    void selectInteraction(GameObject* theGameObject, InteractionType theInteraction);
    void setInteractionOptions(const std::string& theOptions);
    void startInteraction();
    void abortInteraction();

    void talkToCharacter(const std::string& name, const std::string& query);
    std::string getCurrentSceneElements() const;

    InteractionType stringToInteractionType(const std::string& text) const;
    void interactWithObject(const std::string& objectName, const std::string& interactionText);

    // Getters för tester
    GameObject* getSelectedGameObject() const;
    InteractionType getSelectedInteraction() const;
    Scene* getCurrentScene() const;
};