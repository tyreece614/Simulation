
#include "Predator.h"


Predator::Predator(int Health, int Hunger, int Thirst, std::string name, int X, int Y, int d) : Animal(Health, Hunger, Thirst, name, X, Y)
{
	damage = d;
	setColor(sf::Color::Red);
	setSize(20);
}
void Predator::setDamage(int d)
{
	damage = d;
}
int Predator::getDamage()
{
	return damage;
}