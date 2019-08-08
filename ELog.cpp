#include "ELog.h"

void ELog::LogWarning(std::string message, std::string classAndFunction)
{
	std::cout << std::string("Warning: ") + message  + std::string(" ") + classAndFunction << std::endl;
}
