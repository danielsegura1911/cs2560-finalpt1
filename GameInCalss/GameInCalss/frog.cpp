#include "frog.h"



frog::frog(sf::Vector2u size)
{
	frogshape.setSize(sf::Vector2f(20, 20));
	frogshape.setPosition(sf::Vector2f(frogshape.getPosition().x, size.y - frogshape.getSize().y));
}


frog::~frog()
{
}

void frog::draw(sf::RenderWindow &window)
{
	sf::Texture text;
	text.loadFromFile("image\green.png");
	window.draw(frogshape);
}

void frog::move(sf::Event event)
{
	if (sf::Keyboard::Key::Left == event.key.code)
	{
        frogshape.move(-20, 0);
	}
	else if (sf::Keyboard::Key::Right == event.key.code)
	{
        frogshape.move(20, 0);
	}
	else if (sf::Keyboard::Key::Up == event.key.code)
	{
        frogshape.move(0, -20);
	}
	else if (sf::Keyboard::Key::Down == event.key.code)
	{
        frogshape.move(0, 20);
	}
}

sf::RectangleShape frog::getShape()
{
	return frogshape;
}