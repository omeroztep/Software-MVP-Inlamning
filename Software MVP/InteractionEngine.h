#pragma once
#include <string>
#include "PlotEngine.h"

// Denna klass används av Character för att hantera frågor och svar.
class InteractionEngine {
private:
	PlotEngine* plotEngine;

public:
	InteractionEngine();
	~InteractionEngine();

	void create();
	std::string parseQuery(const std::string& query) const;
	std::string formatResponse(const std::string& response) const;
};