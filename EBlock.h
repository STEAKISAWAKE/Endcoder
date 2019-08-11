#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "ETransform.h"
#include "EGroup.h"


class EBlock : public ETransform
{

	//Override functions in this class for different types of blocks. Eg. Classblock, Functionblock, Commentblock, Memberblock (Variableblock), ect.

public:

	EBlock();
	~EBlock();

	virtual void Init();
	virtual void Update();


	//Translates the block to c++ code
	virtual void TranslateBlock();
	//Translates the block to c++ and returns the string to a pointer
	virtual void TranslateBlock(std::string& getString);

	virtual std::string getTranslatedCode() { return TranslatedCode; };

	virtual bool isMouseHovering(sf::Vector2f mousePosition);

	virtual void readyForSelect();
	virtual void readyForDeselect();

	std::string TranslatedCode;

	

	sf::RectangleShape backgroundShape;
	sf::Text titleText;
	sf::Font* textFont;

	EGroup drawingGroup;

	bool selected_b = false;


};

