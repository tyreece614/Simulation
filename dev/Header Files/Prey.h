#pragma once
#include "Animal.h"
#include "Utilities.h"
class Predator;
class Prey : public Animal
{
public:
	Prey(int Health, int Hunger, int Thrist, std::string name, int X, int Y);
	
	void Move(Predator* m);

};