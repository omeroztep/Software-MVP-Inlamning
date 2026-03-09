#pragma once
#include <string>

// Denna klass ansvarar för att kontrollera och normalisera användarens input
// innan den skickas vidare till Game.

class InputSanitiser {
public:
	InputSanitiser();
	~InputSanitiser();

	std::string sanitiseInput(const std::string& query) const;
	bool isValid(const std::string& query) const;
};


