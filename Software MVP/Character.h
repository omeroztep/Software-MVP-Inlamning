#pragma once
#pragma once
#include <string>
#include "InteractionEngine.h"

// Character representerar en karaktär som spelaren kan interagera med.
class Character
{
private:
    std::string name;
    std::string initialGreeting;
    InteractionEngine* interactionEngine;

public:
    Character(const std::string& name, const std::string& greeting);
    ~Character();

    std::string getName() const;
    std::string getInitialGreeting() const;
    std::string query(const std::string& queryText) const;
};