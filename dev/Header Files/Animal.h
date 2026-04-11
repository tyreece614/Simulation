#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class Animal
{
private:
	int health;
	int hunger;
	int thirst;
	int size;
	std::string name;
	sf::Color color;

	int x, y;
public:
	void setHealth(int hth);
	void setHunger(int hgr);
	void setThirst(int thrst);
	void setName(std::string n);
	void setX(int x1);
	void setY(int y1);
	void setColor(sf::Color c);
	void setSize(int s);

	int getHealth();
	int getHunger();
	int getThirst();
	std::string getName();
	int getX();
	int getY();
	sf::Color getColor();
	int getSize();

	Animal(int Health, int Hunger, int Thrist, std::string name, int X, int Y);
};