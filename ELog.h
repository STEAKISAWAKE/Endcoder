#pragma once
#include <iostream>

class ELog
{

public:
	static void LogWarning(std::string message, std::string classAndFunction);
	static void ErrorLog(std::string message, std::string classAndFunction);
};

