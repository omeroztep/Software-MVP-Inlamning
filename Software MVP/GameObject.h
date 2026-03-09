#pragma once
#include <string>
#include <vector>
#include "InteractionType.h"

class GameObject
{
private:
    std::string name;
    std::vector<InteractionType> interactionTypes;
    std::string currentInteractionOptions;
    bool isOpen;
    bool isTaken;

public:
    GameObject(const std::string& name);
    virtual ~GameObject();

    std::string getName() const;

    void addInteractionType(InteractionType type);
    std::vector<InteractionType> listInteractionTypes() const;

    virtual void startInteraction(InteractionType type);
    std::string listCurrentInteractionOptions() const;
    void setCurrentInteractionOptions(const std::string& options);
    void abortCurrentInteraction();

    std::string interactionTypeToString(InteractionType type) const;

    // Getters för tester 
    bool getIsOpen() const;
	bool getIsTaken() const;
 
};