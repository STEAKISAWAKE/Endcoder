#include "ERenderer.h"

#include <SFML/Graphics/Drawable.hpp>

#include "ELog.h"

void ERenderer::Init() {
	gui.drawingGroup = drawingGroup;
	gui.blockManager = blockManager;

	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		ELog::ErrorLog("Could not load font.", "ERenderer::Init");
	}

	blockManager->blockFont = &font;

}

void ERenderer::Draw()
{

	gui.Draw();

	window->draw(blockManager->drawingGroup);


}
