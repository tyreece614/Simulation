#pragma once
#include "Animal.h"

class Prey : public Animal
{
public:
	Prey(int Health, int Hunger, int Thrist, std::string name, int X, int Y);
	
};