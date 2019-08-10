#include "EBlockManager.h"
#include "imgui.h"

void EBlockManager::createBlock()
{
	
	//Crete new block on the heap.
	EBlock* newBlock = new EBlock();
	newBlock->Init();

	drawingGroup.push_back(newBlock->drawingGroup);
	blocks.push_back(newBlock);

}

void EBlockManager::deleteBlock(EBlock* block)
{

	drawingGroup.removeAt(&block->drawingGroup);

	for (int b = 0; b < blocks.size(); b++) {
		if (blocks[b] == block) {
			blocks.erase(blocks.begin() + b);
		}
	}

	delete block;
	
}

void EBlockManager::deleteSelectedBlocks()
{
	for (int s = 0; s < selectedBlocks.size(); s++) {
		deleteBlock(selectedBlocks[s]);
	}

	selectedBlocks.clear();
}

void EBlockManager::Update(sf::Event event)
{
	for (int b = 0; b < blocks.size(); b++) {
		blocks[b]->Update();
	}

	if (selectedBlocks.size() > 0) {
		for (int s = 0; s < selectedBlocks.size(); s++) {

		}
	}


	//Selected blocks event stuff
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			//For all blocks
			bool hitBlock = false;

			for (int b = 0; b < blocks.size(); b++) {
				sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);

				if (blocks[b]->isMouseHovering(window->mapPixelToCoords(pixelPos))) {
					//Person clicked on block
					hitBlock = true;

					//if (selectedBlocks.size() == 0) {
				
						unselectAllBlocks();
						selectBlock(blocks[b]);
						
					//}

				}
			}

			if (!hitBlock) {
				
				unselectAllBlocks();
			}

		} if (event.mouseButton.button == sf::Mouse::Right) {
			if (selectedBlocks.size() > 0) {
				for (int s = 0; s < selectedBlocks.size(); s++) {
					sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
					selectedBlocks[s]->setPosition(window->mapPixelToCoords(pixelPos));
				}
			}
		}
	}
}

void EBlockManager::Shutdown()
{
	for (int b = 0; b < blocks.size(); b++) {
		delete blocks[b];
	}
}

void EBlockManager::unselectAllBlocks()
{
	for (int b = 0; b < selectedBlocks.size(); b++) {
		unselectBlock(selectedBlocks[b]);
	}
}

void EBlockManager::selectBlock(EBlock* block)
{
	block->readyForSelect();
	selectedBlocks.push_back(block);
}

void EBlockManager::unselectBlock(EBlock* block)
{
	bool found;

	for (int b = 0; b < selectedBlocks.size(); b++) {
		if (selectedBlocks[b] == block) {
			block->readyForDeselect();
			selectedBlocks.erase(selectedBlocks.begin() + b);
			selectedBlocks.shrink_to_fit();
		}
	}

}
