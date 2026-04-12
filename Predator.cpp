#include "Predator.h"
#include "Prey.h"

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

void Predator::Move(Prey* m)
{
	if (m == nullptr)
	{
		return;
	}
	double minDistance = Distance(getX(), m->getX(), getY(), m->getY());
	
	
	double dx = m->getX() - getX();
	double dy = m->getY() - getY();

	dx = dx / minDistance;
	dy = dy / minDistance;
	setX(getX() + dx * 1);
	setY(getY() + dy * 1);

	if (getX() < 0)
	{
		setX(0);
	}
	if (getY() < 0)
	{
		setY(0);
	}
	if (getX() > 780)
	{
		setX(780);

	}
	if (getY() > 580)
	{
		setY(580);
	}

}