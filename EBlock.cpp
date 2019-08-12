#include "EBlock.h"
#include <random>

int rand_int(int low, int high)
{
	static std::default_random_engine re{};
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}

EBlock::EBlock()
{

	
	drawingGroup.push_back(backgroundShape);

	backgroundShape.setSize(sf::Vector2f(50.0f, 25.0f));
	backgroundShape.setFillColor(sf::Color::Yellow);
	backgroundShape.setOrigin(sf::Vector2f(backgroundShape.getGlobalBounds().width / 2, backgroundShape.getGlobalBounds().height / 2));

	setPosition(sf::Vector2f(rand_int(100, 500), rand_int(100, 500)));

}

EBlock::~EBlock()
{
	
}

void EBlock::Init()
{
	titleText.setFont(*textFont);
	titleText.setString("Hello World");
	titleText.setCharacterSize(24);
	titleText.setFillColor(sf::Color::Red);

	drawingGroup.push_back(titleText);
}

void EBlock::Update()
{
	backgroundShape.setPosition(getPosition());
	titleText.setPosition(getPosition());

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
