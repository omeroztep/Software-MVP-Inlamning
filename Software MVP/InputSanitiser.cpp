#include "InputSanitiser.h"
#include <cctype>

InputSanitiser::InputSanitiser() 
{
}

InputSanitiser::~InputSanitiser() 
{
}

std::string InputSanitiser::sanitiseInput(const std::string& query) const
{
		std::string result;
		for (char c : query)
		{
			result += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
		}
		return result;
}

bool InputSanitiser::isValid(const std::string& query) const
{
	return !query.empty();
}