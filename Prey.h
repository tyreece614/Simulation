#pragma once
#include "Animal.h"
#include "Predator.h"
#include "Utilities.h"

class Prey : public Animal
{
public:
	Prey(int Health, int Hunger, int Thrist, std::string name, int X, int Y);
	
	void Move(Predator* m);

};