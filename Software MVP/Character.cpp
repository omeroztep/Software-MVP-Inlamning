#include "Character.h"

Character::Character(const std::string& name, const std::string& greeting) 
	: name(name), initialGreeting(greeting)
{
	interactionEngine = new InteractionEngine();
}

Character::~Character() 
{
	delete interactionEngine;
	interactionEngine = nullptr;
}

std::string Character::getName() const 
{
	return name;
}

std::string Character::getInitialGreeting() const
{
	return initialGreeting;
}

std::string Character::query(const std::string& queryText) const
{
    std::string parsed = interactionEngine->parseQuery(queryText);

    if (parsed == "hej")
        return interactionEngine->formatResponse("Hej själv.");
    if (parsed == "vem är du")
        return interactionEngine->formatResponse("Jag är läraren i spelet.");
    if (parsed == "hjälp")
        return interactionEngine->formatResponse("Prova att öppna dörren eller undersöka nyckeln.");

    return interactionEngine->formatResponse("Jag förstår inte frågan.");
}