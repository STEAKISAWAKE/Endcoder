#ifndef EBLOCKMANAGER_H_
#define EBLOCKMANAGER_H_


//class EGui;

#include <vector>

#include <SFML/Window.hpp>

#include "EBlock.h"
#include "EGroup.h"

class EBlockManager
{
public:
	void createBlock();
	void deleteBlock(EBlock* block);
	void deleteSelectedBlocks();

	void Update(sf::Event event);
	void UpdateBlocks();
	void Shutdown();

	void unselectAllBlocks();
	void selectBlock(EBlock* block);
	void unselectBlock(EBlock* block);

	sf::RenderWindow* window;

	std::vector<EBlock*> blocks;

	EGroup drawingGroup;

	std::vector<EBlock*> selectedBlocks;

	sf::Font* blockFont;

	bool holdingMouse;
};

#endif