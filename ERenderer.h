#ifndef ERENDERER_H_
#define ERENDERER_H_


class EBlockManager;

#include <vector>

#include <SFML/Graphics.hpp>
#include "imgui.h"

#include "EGui.h"
#include "EBlockManager.h"
#include "EGroup.h"


class ERenderer
{
public:
	ERenderer();
	~ERenderer();

	EGui gui;

	sf::RenderWindow* window = nullptr;

	void Draw();
	void Init();

	EGroup drawingGroup;
	EBlockManager* blockManager = nullptr;

	sf::Font font;

	sf::Text testText;
};

#endif


