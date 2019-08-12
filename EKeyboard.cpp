#include "EKeyboard.h"
#include <fstream>

void EKeyboard::Init()
{
	std::ifstream i("keybindsConfig.json");
	i >> keybindsJson;

	std::vector<std::string> newActionKeybinds;
	newActionKeybinds.empty();

	for (int a = 0; a < ActionNames.size(); a++) {
		newActionKeybinds[a-1] = keybindsJson[ActionNames[a-1]];
	}
}

void EKeyboard::Update()
{

}

void EKeyboard::Shutdown()
{

}

void EKeyboard::RebindAction(std::string action)
{
	bool keyPressed = false;
	sf::Keyboard::Key newKey = sf::Keyboard::Key::Unknown;

	while (!keyPressed) {
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed) {
				newKey = event.key.code;
			}
		}
	}


	const char* newKeyChar = getTextForEnum(newKey);

}
