#include "ERenderer.h"

#include <SFML/Graphics/Drawable.hpp>

#include "ELog.h"



void ERenderer::Init() {
	
	gui.drawingGroup = &drawingGroup;
	gui.blockManager = blockManager;

	blockManager->blockFont = &font;

}

ERenderer::ERenderer()
{
	

	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		ELog::ErrorLog("Could not load font.", "ERenderer::Init");
	}


}

ERenderer::~ERenderer()
{
	
}

void ERenderer::Draw()
{

	gui.Draw();

	window->draw(blockManager->drawingGroup);


}
