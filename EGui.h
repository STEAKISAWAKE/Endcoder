#ifndef EGUI_H_
#define EGUI_H_

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
	void ToolBar();
	bool ToolBarHovered = false;
	void Settings();
	bool SettingsHovered = false;
	//EApplication* app;
};

#endif