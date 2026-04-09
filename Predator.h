#pragma once
#include "Animal.h"

class Predator : public Animal
{
private:
	int damage;

public:
	void setDamage(int d);
	int getDamage();

	Predator(int Health, int Hunger, int Thirst, std::string name, int X, int Y, int d);

};

