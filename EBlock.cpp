#include "EBlock.h"

EBlock::EBlock()
{
	drawingGroup.push_back(backgroundShape);

	backgroundShape.setSize(sf::Vector2f(50.0f, 25.0f));
	backgroundShape.setFillColor(sf::Color::Yellow);



}

EBlock::~EBlock()
{
	
}

void EBlock::Init()
{
}

void EBlock::Update()
{
	backgroundShape.setPosition(getPosition());

}

void EBlock::TranslateBlock()
{
}

void EBlock::TranslateBlock(std::string& getString)
{
}

bool EBlock::isMouseHovering(sf::Vector2f mousePosition)
{
	return backgroundShape.getGlobalBounds().contains(mousePosition);
}

void EBlock::readyForSelect()
{
	backgroundShape.setOutlineThickness(5);
	backgroundShape.setOutlineColor(sf::Color::Green);
	selected_b = true;
}

void EBlock::readyForDeselect()
{
	backgroundShape.setOutlineThickness(0);
	backgroundShape.setOutlineColor(sf::Color::Green);
	selected_b = false;
}
