#include "EApplication.h"

#include "imgui.h"
#include "imgui-SFML.h"

#include "ELog.h"

EApplication::EApplication() {
	render.window = &window;
	render.blockManager = &blockManager;
	blockManager.window = &window;

	
}

void EApplication::Init()
{
	//Create window and do basic things.

	window.create(sf::VideoMode(1024, 720), "Endcoder");
	window.setFramerateLimit(60);
	ImGui::SFML::Init(window);


	render.Init();
	keyboard.Init();
}

void EApplication::Update()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed)
				window.close();

			// catch the resize events
			if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}

			//Disable the blockmanager from updating if the mouse is ontop of imgui
			if (!render.gui.isAnyWindowHovered()) {
				blockManager.Update(event);
			}
			else {
				blockManager.UpdateBlocks();
			}

			
		}

		
		keyboard.Update();
		ImGui::SFML::Update(window, deltaClock.restart());

		window.clear(sf::Color::White);

		//window.draw(testText);
		

		render.Draw();

		ImGui::SFML::Render(window);
		window.display();
	}
}

void EApplication::Shutdown()
{
	ImGui::SFML::Shutdown();

	blockManager.Shutdown();
	keyboard.Shutdown();
}
