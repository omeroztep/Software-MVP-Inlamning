#include "PlotEngine.h"

PlotEngine::PlotEngine() : plotState("start")
{
}

PlotEngine::~PlotEngine()
{
}

std::string PlotEngine::getPlotstate() const
{
	return plotState;
}