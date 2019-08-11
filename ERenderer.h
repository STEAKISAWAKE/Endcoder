#ifndef ERENDERER_H_
#define ERENDERER_H_

class EBlockManager;

#include <vector>

#include <SFML/Graphics.hpp>
#include "imgui.h"

#include "EBlockManager.h"
#include "EGroup.h"

class EGui
{
public:
	void Draw();

	sf::Clock* clock;

	EGroup* drawingGroup;
	EBlockManager* blockManager;

	bool isAnyWindowHovered();

private:
	void Properties();
	bool PropertiesHovered = false;
	void Debug();
	bool DebugHovered = false;
	//EApplication* app;
};


class ERenderer
{
public:
	EGui gui;

	sf::RenderWindow* window;

	void Draw();
	void Init();

	EGroup* drawingGroup;
	EBlockManager* blockManager;

	sf::Font font;
};

#endif


