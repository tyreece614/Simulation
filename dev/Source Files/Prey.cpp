#include "Prey.h"
#include <cstdlib>
#include <ctime>
#include "Predator.h"

Prey::Prey(int Health, int Hunger, int Thirst, std::string name, int X, int Y) : Animal(Health, Hunger, Thirst, name, X, Y)
{
	setColor(sf::Color::Green);
	setSize(10);
}

void Prey::Move(Predator* m)
{
	double minDistance = Distance(getX(), m->getX(), getY(), m->getY());
	if (minDistance < 100)
	{
		double dx = getX() - m->getX();
		double dy = getY() - m->getY();
		dx = dx / minDistance;
		dy = dy / minDistance;
		setX(getX() + dx * 5);
		setY(getY() + dy * 5);
		
	}

	else
	{
		float angle = (rand() % 360) * 3.14159f / 180.f;

		double dx = cos(angle);
		double dy = sin(angle);
		setX(getX() + dx * 5);
		setY(getY() + dy * 5);
	}
	if (getX() < 0)
	{
		setX(0);
	}
	if (getY() < 0)
	{
		setY(0);
	}
	if (getX() > 790)
	{
		setX(790);

	}
	if (getY() > 590)
	{
		setY(590);
	}


}