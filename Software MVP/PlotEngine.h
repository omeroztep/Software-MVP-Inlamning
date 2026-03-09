#pragma once
#include <string>

// Med Den här klassen kan jag representera spelets tillstång.
// I detta MVP används den bara på en grundläggande nivå.

class PlotEngine {
	private:
		std::string plotState; // En enkel sträng som representerar spelets tillstånd.

public:
	PlotEngine();
	~PlotEngine();

	std::string getPlotstate() const;
};