#pragma once
#include "Game.h"
#include "InputSanitiser.h"

// UserInterface ansvarar för all input och output.
// Detta håller användargränssnittet separerat från Game-logiken.
class UserInterface
{
private:
    Game* game;
    InputSanitiser* sanitiser;

public:
    UserInterface();
    ~UserInterface();

    void start();
    void showMessage(const std::string& text) const;
    std::string readCommand() const;
};