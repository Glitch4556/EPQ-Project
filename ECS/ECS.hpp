#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Behaviour
{
public:
	virtual void Update(sf::RenderWindow&) = 0;
	virtual void Render(sf::RenderWindow&) = 0;

	static void CreateObject(std::unique_ptr<Behaviour>& obj);
	
	static std::vector<std::unique_ptr<Behaviour>> objects;
};

void RenderAll(sf::RenderWindow& window);
void UpdateAll(sf::RenderWindow& window);
