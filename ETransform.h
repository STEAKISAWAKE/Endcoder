#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

class ETransform
{

public:

	ETransform();

	ETransform* Child;
	ETransform* Parent;

	std::vector<ETransform*> childeren;

	void setParent(ETransform* newParent);
	void setChild(ETransform* newChild) { Child = newChild; }

	void addChildToParent(ETransform* newChild);
	void removeChildFromParent(ETransform* removedChild);

	void disconnectFromParent();

	void setPosition(sf::Vector2f newPosition) { position = newPosition; };
	sf::Vector2f getPosition() { return position; }


private:
	sf::Vector2f position;

};

