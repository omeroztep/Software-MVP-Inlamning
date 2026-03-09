#include "InteractionEngine.h"

InteractionEngine::InteractionEngine()
{
	plotEngine = new PlotEngine();
}

InteractionEngine::~InteractionEngine()
{
	delete plotEngine;
	plotEngine = nullptr;
}

void InteractionEngine::create()
{
	// Här kan vi lägga till mer komplex logik för att skapa en interaktion.
	// För nu, så gör vi inget speciellt.
}

std::string InteractionEngine::formatResponse(const std::string& response) const
{
	// Här kan vi lägga till mer komplex logik för att formatera svar.
	// För nu, så returnerar vi bara svaret som det är.
	return "[Svar]: " + response + " [PlotState: " + plotEngine->getPlotstate() + "]";
}

std::string InteractionEngine::parseQuery(const std::string& query) const
{
	return query;
}