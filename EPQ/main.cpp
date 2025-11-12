#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../ECS/ECS.hpp"

class Neutron : public Behaviour
{
private:
	sf::CircleShape circle;

public:
	Neutron(sf::Vector2f pos)
	{
		circle = sf::CircleShape(5.f);
		circle.setFillColor(sf::Color(255, 0, 0));
		circle.setOrigin({ circle.getRadius(), circle.getRadius() });
		circle.setPosition(pos);
	}

	void Update(sf::RenderWindow& window) override
	{

	}

	void Render(sf::RenderWindow& window) override
	{
		window.draw(circle);
	}
};

sf::Vector2f mousePos(sf::RenderWindow& window)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	return sf::Vector2f(static_cast<float>(pixelPos.x), static_cast<float>(pixelPos.y));
}

class NeutronSpawner : public Behaviour
{
private:

public:

	void Render(sf::RenderWindow& window) override
	{

	}
	void Update(sf::RenderWindow& window) override
	{
		std::unique_ptr<Neutron> neutron = std::make_unique<Neutron>(mousePos(window));
		objects.push_back(std::move(neutron));
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window", sf::State::Windowed);

	std::unique_ptr<NeutronSpawner> spawner = std::make_unique<NeutronSpawner>();
	Behaviour::objects.push_back(std::move(spawner));

	while (window.isOpen())
	{
		RenderAll(window);
		UpdateAll(window);
	}
}
