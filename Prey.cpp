#include "Prey.h"

Prey::Prey(int Health, int Hunger, int Thirst, std::string name, int X, int Y) : Animal(Health, Hunger, Thirst, name, X, Y)
{
	setColor(sf::Color::Green);
	setSize(10);
}