#ifndef EAPPLICATION_H_
#define EAPPLICATION_H_

#include <string>

#include <SFML/Graphics.hpp>

#include "ERenderer.h"
#include "EBlockManager.h"
#include "EKeyboard.h"

class EApplication
{



public:
	EApplication();

	void Init();
	void Update();
	void Shutdown();

	ERenderer render;
	sf::Clock deltaClock;
	sf::RenderWindow window;
	EBlockManager blockManager;
	EKeyboard keyboard;
	
};

#endif
