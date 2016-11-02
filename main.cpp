#include <iostream>
#include <SFML/Graphics.hpp>

#include "Log.h"

int main() {
	std::string defaultFontPath = "/home/solyd/.fonts/SourceCodePro-Medium.ttf";

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	sf::CircleShape  shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window.setFramerateLimit(60);

	sf::Font defaultFont;
	if (!defaultFont.loadFromFile(defaultFontPath)) {

		return -1;
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}