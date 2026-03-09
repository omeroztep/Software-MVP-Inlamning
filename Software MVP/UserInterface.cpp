#include "UserInterface.h"
#include <iostream>
#include <sstream>

UserInterface::UserInterface()
{
    game = new Game();
    sanitiser = new InputSanitiser();
}

UserInterface::~UserInterface()
{
    delete game;
    game = nullptr;

    delete sanitiser;
    sanitiser = nullptr;
}

void UserInterface::showMessage(const std::string& text) const
{
    std::cout << text << std::endl;
}

std::string UserInterface::readCommand() const
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void UserInterface::start()
{
    showMessage("Välkommen till spelet.");
    showMessage("Kommandon:");
    showMessage("show");
    showMessage("open door");
    showMessage("close door");
    showMessage("inspect door");
    showMessage("inspect key");
    showMessage("take key");
    showMessage("talk teacher hej");
    showMessage("talk teacher vem är du");
    showMessage("exit");
    showMessage("");
    showMessage(game->getCurrentSceneElements());

    while (true)
    {
        showMessage("\nSkriv kommando:");
        std::string input = readCommand();
        input = sanitiser->sanitiseInput(input);

        if (!sanitiser->isValid(input))
        {
            showMessage("Ogiltig input.");
            continue;
        }

        if (input == "exit")
        {
            showMessage("Spelet avslutas.");
            break;
        }

        if (input == "show")
        {
            showMessage(game->getCurrentSceneElements());
            continue;
        }

        std::istringstream iss(input);
        std::string command;
        std::string target;

        iss >> command >> target;

        if (command == "open" || command == "close" || command == "inspect" || command == "take")
        {
            game->interactWithObject(target, command);
        }
        else if (command == "talk")
        {
            std::string rest;
            std::getline(iss, rest);

            while (!rest.empty() && rest[0] == ' ')
            {
                rest.erase(0, 1);
            }

            if (rest.empty())
            {
                rest = "hej";
            }

            game->talkToCharacter(target, rest);
        }
        else
        {
            showMessage("Okänt kommando.");
        }
    }
}