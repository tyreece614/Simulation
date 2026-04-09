// Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Predator.h"
#include "Prey.h"
#include "Animal.h"
#include <vector>
#include <cstdlib>
#include <ctime>


bool UniquePosition(std::vector<Predator*>& predators, std::vector<Prey*>preys, int x, int y)
{
    for (int i = 0; i < predators.size(); i++)
    {
        if (predators[i]->getX() == x && predators[i]->getY() == y)
        {
            return false;
        }
    }

    for (int i = 0; i < preys.size(); i++)
    {
        if (preys[i]->getX() == x && preys[i]->getY() == y)
        {
            return false;
        }
    }

    return true;
}

void PopulatePredators(std::vector<Predator*>&predators, std::vector<Prey*>&preys, int Size)
{
    for (int i = 0; i < Size; i++)
    {
        int x = rand() % 800;
        int y = rand() % 600;
        while (!UniquePosition(predators, preys, x, y))
        {
            x = rand() % 800;
            y = rand() % 600;
        }
        std::string name = "predator" + i;
        Predator* p = new Predator(rand() % 10 + 10, 100, 100, name, x, y, rand() % 5 + 3);
        predators.push_back(p);
    }
}


void PopulatePreys(std::vector<Predator*>& predators, std::vector<Prey*>&preys, int Size)
{
    for (int i = 0; i < Size; i++)
    {
        int x = rand() % 800;
        int y = rand() % 600;
        while (!UniquePosition(predators, preys, x, y))
        {
            x = rand() % 800;
            y = rand() % 600;
        }
        std::string name = "prey" + i;
        Prey* p = new Prey(rand() % 10 + 10, 100, 100, name, x, y);
        preys.push_back(p);
    }
}

void DisplayPredators(std::vector<Predator*>animals, sf::RenderWindow* window)
{
    for (int x = 0; x < animals.size(); x++)
    {
        sf::RectangleShape square(sf::Vector2f(animals[x]->getSize(), animals[x]->getSize()));
        square.setFillColor(animals[x]->getColor());
        square.setPosition(sf::Vector2f(animals[x]->getX(), animals[x]->getY()));
        window->draw(square);

    }
}

void DisplayPreys(std::vector<Prey*>animals, sf::RenderWindow* window)
{
    for (int x = 0; x < animals.size(); x++)
    {
        sf::RectangleShape square(sf::Vector2f(animals[x]->getSize(), animals[x]->getSize()));
        square.setFillColor(animals[x]->getColor());
        square.setPosition(sf::Vector2f(animals[x]->getX(), animals[x]->getY()));
        window->draw(square);

    }
}

int main()
{
    std::srand(std::time(nullptr));
    std::vector<Predator*>predators;
    std::vector<Prey*>preys;
    PopulatePredators(predators, preys, 5);
    PopulatePreys(predators, preys, 10);

    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Game");
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();
        DisplayPredators(predators, &window);
        DisplayPreys(preys, &window);
        // Update the window
        window.display();
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
