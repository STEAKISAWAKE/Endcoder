#include "ERenderer.h"

#include <SFML/Graphics/Drawable.hpp>

void ERenderer::Init() {
	gui.drawingGroup = drawingGroup;
	gui.blockManager = blockManager;
}

void ERenderer::Draw()
{

	gui.Draw();

	window->draw(blockManager->drawingGroup);


}
