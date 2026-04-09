#include "Animal.h"


Animal::Animal(int Health, int Hunger, int Thirst, std::string Name, int X, int Y)
{
	health = Health;
	hunger = Hunger;
	thirst = Thirst;
	name = Name;
	x = X;
	y = Y;
}

void Animal::setHealth(int hth)
{
	health = hth;
}
void Animal::setHunger(int hgr)
{
	hunger = hgr;
}
void Animal::setThirst(int thrst)
{
	thirst = thrst;
}
void Animal::setName(std::string n)
{
	name = n;
}
void Animal::setX(int x1)
{
	x = x1;
}
void Animal::setY(int y1)
{
	y = y1;
}

void Animal::setColor(sf::Color c)
{
	color = c;
}

void Animal::setSize(int s)
{
	size = s;
}

int Animal::getHealth()
{
	return health;
}
int Animal::getHunger()
{
	return hunger;
}
int Animal::getThirst()
{
	return thirst;
}
std::string Animal::getName()
{
	return name;
}
int Animal::getX()
{
	return x;
}
int Animal::getY()
{
	return y;
}

sf::Color Animal::getColor()
{
	return color;
}
int Animal::getSize()
{
	return size;
}