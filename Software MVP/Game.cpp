#include "Game.h"
#include <iostream>

Game::Game()
{
    myGameObjects = new GameObjectRepository();
    currentScene = new Scene("startScene");
    playerInventory = new Scene("inventory");
    selectedGameObject = nullptr;
    selectedCharacter = nullptr;
    selectedInteraction = InteractionType::Invalid;

    setup();
}

Game::~Game()
{
    delete myGameObjects;
    myGameObjects = nullptr;

    delete currentScene;
    currentScene = nullptr;

    delete playerInventory;
    playerInventory = nullptr;
}

void Game::setup()
{
    // Hårdkodad MVP-setup enligt uppgiften.
    GameObject* door = new GameObject("door");
    door->addInteractionType(InteractionType::Open);
    door->addInteractionType(InteractionType::Close);
    door->addInteractionType(InteractionType::Inspect);

    GameObject* key = new GameObject("key");
    key->addInteractionType(InteractionType::Inspect);
    key->addInteractionType(InteractionType::Take);

    Character* teacher = new Character("teacher", "Hej! Jag är läraren.");

    currentScene->addGameObject(door);
    currentScene->addGameObject(key);
    currentScene->addCharacter(teacher);

    myGameObjects->addGameObject(door);
    myGameObjects->addGameObject(key);
}

void Game::selectGameObject(const std::string& name)
{
    selectedGameObject = currentScene->findGameObject(name);
    selectedCharacter = currentScene->findCharacter(name);

    if (selectedGameObject != nullptr)
    {
        std::cout << "Du valde objektet: " << name << std::endl;
        return;
    }

    if (selectedCharacter != nullptr)
    {
        std::cout << "Du valde karaktären: " << name << std::endl;
        return;
    }

    std::cout << "Inget objekt eller karaktär med det namnet finns." << std::endl;
}

void Game::selectInteraction(GameObject* theGameObject, InteractionType theInteraction)
{
    if (theGameObject == nullptr)
    {
        selectedGameObject = nullptr;
        selectedInteraction = InteractionType::Invalid;
        return;
    }

    selectedGameObject = theGameObject;
    selectedInteraction = theInteraction;
}

void Game::setInteractionOptions(const std::string& theOptions)
{
    if (selectedGameObject != nullptr)
    {
        selectedGameObject->setCurrentInteractionOptions(theOptions);
    }
}

void Game::startInteraction()
{
    if (selectedGameObject == nullptr)
    {
        std::cout << "Inget objekt valt för interaktion." << std::endl;
        return;
    }

    selectedGameObject->startInteraction(selectedInteraction);
}

void Game::abortInteraction()
{
    if (selectedGameObject != nullptr)
    {
        selectedGameObject->abortCurrentInteraction();
    }

    selectedGameObject = nullptr;
    selectedInteraction = InteractionType::Invalid;
}

void Game::talkToCharacter(const std::string& name, const std::string& query)
{
    Character* character = currentScene->findCharacter(name);

    if (character == nullptr)
    {
        std::cout << "Karaktären finns inte i scenen." << std::endl;
        return;
    }

    std::cout << character->getInitialGreeting() << std::endl;
    std::cout << character->query(query) << std::endl;
}

std::string Game::getCurrentSceneElements() const
{
    return currentScene->listAvailableElements();
}

InteractionType Game::stringToInteractionType(const std::string& text) const
{
    if (text == "open") return InteractionType::Open;
    if (text == "close") return InteractionType::Close;
    if (text == "inspect") return InteractionType::Inspect;
    if (text == "take") return InteractionType::Take;
    if (text == "talk") return InteractionType::Talk;
    return InteractionType::Invalid;
}

void Game::interactWithObject(const std::string& objectName, const std::string& interactionText)
{
    GameObject* obj = currentScene->findGameObject(objectName);

    if (obj == nullptr)
    {
        std::cout << "Objektet finns inte i scenen." << std::endl;
        return;
    }

    InteractionType type = stringToInteractionType(interactionText);
    if (type == InteractionType::Invalid)
    {
        std::cout << "Ogiltig interaktion." << std::endl;
        return;
    }

    selectInteraction(obj, type);
    startInteraction();
}

GameObject* Game::getSelectedGameObject() const
{
    return selectedGameObject;
}

InteractionType Game::getSelectedInteraction() const
{
    return selectedInteraction;
}

Scene* Game::getCurrentScene() const
{
    return currentScene;
}