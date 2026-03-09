#include "CppUnitTest.h"

#include "Game.h"
#include "GameObject.h"
#include "Scene.h"
#include "InteractionType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SoftwareMVPUnitTests
{
    TEST_CLASS(GameTests)
    {
    public:

        TEST_METHOD(SelectGameObject_Positive_DoorExists)
        {
            Game* game = new Game();

            game->selectGameObject("door");

            Assert::IsNotNull(game->getSelectedGameObject());
            Assert::AreEqual(std::string("door"), game->getSelectedGameObject()->getName());

            delete game;
        }

        TEST_METHOD(SelectGameObject_Negative_ObjectDoesNotExist)
        {
            Game* game = new Game();

            game->selectGameObject("banana");

            Assert::IsNull(game->getSelectedGameObject());

            delete game;
        }

        TEST_METHOD(SelectInteraction_Positive_OpenDoor)
        {
            Game* game = new Game();
            game->selectGameObject("door");
            GameObject* door = game->getSelectedGameObject();

            game->selectInteraction(door, InteractionType::Open);

            Assert::AreEqual(
                static_cast<int>(InteractionType::Open),
                static_cast<int>(game->getSelectedInteraction())
            );

            delete game;
        }

        TEST_METHOD(SelectInteraction_Negative_NullObject)
        {
            Game* game = new Game();

            game->selectInteraction(nullptr, InteractionType::Open);

            Assert::IsNull(game->getSelectedGameObject());
            Assert::AreEqual(
                static_cast<int>(InteractionType::Invalid),
                static_cast<int>(game->getSelectedInteraction())
            );

            delete game;
        }

        TEST_METHOD(StartInteraction_Positive_OpenDoorChangesState)
        {
            Game* game = new Game();
            game->selectGameObject("door");
            GameObject* door = game->getSelectedGameObject();
            game->selectInteraction(door, InteractionType::Open);

            game->startInteraction();

            Assert::IsTrue(door->getIsOpen());

            delete game;
        }

        TEST_METHOD(StartInteraction_Negative_NoObjectSelected)
        {
            Game* game = new Game();

            game->startInteraction();

            Assert::IsNull(game->getSelectedGameObject());
            Assert::AreEqual(
                static_cast<int>(InteractionType::Invalid),
                static_cast<int>(game->getSelectedInteraction())
            );

            delete game;
        }

        TEST_METHOD(StartInteraction_Positive_TakeKeyChangesState)
        {
            Game* game = new Game();
            game->selectGameObject("key");
            GameObject* key = game->getSelectedGameObject();
            game->selectInteraction(key, InteractionType::Take);

            game->startInteraction();

            Assert::IsTrue(key->getIsTaken());

            delete game;
        }

        TEST_METHOD(StartInteraction_Negative_OpenKeyShouldNotChangeState)
        {
            Game* game = new Game();
            game->selectGameObject("key");
            GameObject* key = game->getSelectedGameObject();
            game->selectInteraction(key, InteractionType::Open);

            game->startInteraction();

            Assert::IsFalse(key->getIsOpen());
            Assert::IsFalse(key->getIsTaken());

            delete game;
        }

        TEST_METHOD(AbortInteraction_Positive_ResetSelection)
        {
            Game* game = new Game();
            game->selectGameObject("door");
            GameObject* door = game->getSelectedGameObject();
            game->selectInteraction(door, InteractionType::Open);

            game->abortInteraction();

            Assert::IsNull(game->getSelectedGameObject());
            Assert::AreEqual(
                static_cast<int>(InteractionType::Invalid),
                static_cast<int>(game->getSelectedInteraction())
            );

            delete game;
        }

        TEST_METHOD(AbortInteraction_Negative_NothingSelected)
        {
            Game* game = new Game();

            game->abortInteraction();

            Assert::IsNull(game->getSelectedGameObject());
            Assert::AreEqual(
                static_cast<int>(InteractionType::Invalid),
                static_cast<int>(game->getSelectedInteraction())
            );

            delete game;
        }
    };
}