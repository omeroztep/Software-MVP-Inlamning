#include "GameObject.h"
#include <iostream>

GameObject::GameObject(const std::string& name)
    : name(name), currentInteractionOptions(""), isOpen(false), isTaken(false)
{
}

GameObject::~GameObject()
{
}

std::string GameObject::getName() const
{
    return name;
}

void GameObject::addInteractionType(InteractionType type)
{
    interactionTypes.push_back(type);
}

std::vector<InteractionType> GameObject::listInteractionTypes() const
{
    return interactionTypes;
}

void GameObject::startInteraction(InteractionType type)
{
    switch (type)
    {
    case InteractionType::Open:
        if (name == "door")
        {
            if (!isOpen)
            {
                isOpen = true;
                std::cout << "Du öppnar dörren." << std::endl;
            }
            else
            {
                std::cout << "Dörren är redan öppen." << std::endl;
            }
        }
        else
        {
            std::cout << "Det går inte att öppna " << name << "." << std::endl;
        }
        break;

    case InteractionType::Close:
        if (name == "door")
        {
            if (isOpen)
            {
                isOpen = false;
                std::cout << "Du stänger dörren." << std::endl;
            }
            else
            {
                std::cout << "Dörren är redan stängd." << std::endl;
            }
        }
        else
        {
            std::cout << "Det går inte att stänga " << name << "." << std::endl;
        }
        break;

    case InteractionType::Inspect:
        if (name == "door")
        {
            std::cout << "Det är en gammal trädörr." << std::endl;
        }
        else if (name == "key")
        {
            std::cout << "Det är en liten metallnyckel." << std::endl;
        }
        else
        {
            std::cout << "Du undersöker " << name << "." << std::endl;
        }
        break;

    case InteractionType::Take:
        if (name == "key")
        {
            if (!isTaken)
            {
                isTaken = true;
                std::cout << "Du tar nyckeln." << std::endl;
            }
            else
            {
                std::cout << "Du har redan tagit nyckeln." << std::endl;
            }
        }
        else
        {
            std::cout << "Det går inte att ta " << name << "." << std::endl;
        }
        break;

    default:
        std::cout << "Ogiltig interaktion." << std::endl;
        break;
    }
}

std::string GameObject::listCurrentInteractionOptions() const
{
    return currentInteractionOptions;
}

void GameObject::setCurrentInteractionOptions(const std::string& options)
{
    currentInteractionOptions = options;
}

void GameObject::abortCurrentInteraction()
{
    std::cout << "Interaktionen med " << name << " avbröts." << std::endl;
}

std::string GameObject::interactionTypeToString(InteractionType type) const
{
    switch (type)
    {
    case InteractionType::Open: return "open";
    case InteractionType::Close: return "close";
    case InteractionType::Inspect: return "inspect";
    case InteractionType::Take: return "take";
    case InteractionType::Talk: return "talk";
    default: return "invalid";
    }
}

bool GameObject::getIsOpen() const
{
    return isOpen;
}

bool GameObject::getIsTaken() const
{
    return isTaken;
}