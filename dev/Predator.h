#pragma once
#include "Animal.h"
#include "Utilities.h"

class Prey;
class Predator : public Animal
{
private:
	int damage;

public:
	void setDamage(int d);
	int getDamage();

	Predator(int Health, int Hunger, int Thirst, std::string name, int X, int Y, int d);

	void Move(Prey* m);

};

