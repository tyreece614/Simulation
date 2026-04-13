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
#include <cmath>


enum State {
    MENU,
    SIMULATION,
    END
};

bool Overlap(Animal* a, Animal* b)
{
    if (a->getX() + a->getSize() < b->getX())
    {
        return false;
    }
    if (b->getX() + b->getSize() < a->getX())
    {
        return false;
    }

    if (a->getY() + a->getSize() < b->getY())
    {
        return false;
    }
    if (b->getY() + b->getSize() < a->getY())
    {
        return false;
    }

    return true;
}

bool Overlap(int x, int y, int size, Animal* b)
{
    if (x + size < b->getX())
    {
        return false;
    }
    if (b->getX() + b->getSize() < x)
    {
        return false;
    }

    if (y + size < b->getY())
    {
        return false;
    }
    if (b->getY() + b->getSize() < y)
    {
        return false;
    }

    return true;
}

bool UniquePosition(std::vector<Predator*>& predators, std::vector<Prey*>preys, int x, int y, int size)
{
    for (int i = 0; i < predators.size(); i++)
    {
        if (Overlap(x, y, size, predators[i]))
        {
            return false;
        }
    }

    for (int i = 0; i < preys.size(); i++)
    {
        if (Overlap(x, y, size, preys[i]))
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
        while (!UniquePosition(predators, preys, x, y, 20))
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
        while (!UniquePosition(predators, preys, x, y, 10))
        {
            x = rand() % 800;
            y = rand() % 600;
        }
        std::string name = "prey" + i;
        Prey* p = new Prey(rand() % 10 + 10, 100, 100, name, x, y);
        preys.push_back(p);
    }
}



Prey* ClosestPrey(Predator* pred, std::vector<Prey*> prey)
{
    if (prey.size() == 0)
    {
        return nullptr;
    }


    Prey* closest = prey[0];
    double minDistance = Distance(pred->getX(), closest->getX(), pred->getY(), closest->getY());
    for (int i = 0; i < prey.size(); i++)
    {
        if (Distance(pred->getX(), prey[i]->getX(), pred->getY(), prey[i]->getY()) < minDistance){
            closest = prey[i];
            minDistance = Distance(pred->getX(), prey[i]->getX(), pred->getY(), prey[i]->getY());
        }
    }

    return closest;
}

Predator* ClosestPredator(Prey* prey, std::vector<Predator*> pred)
{
    if (pred.size() == 0)
    {
        return nullptr;
    }


    Predator* closest = pred[0];
    double minDistance = Distance(prey->getX(), closest->getX(), prey->getY(), closest->getY());
    for (int i = 0; i < pred.size(); i++)
    {
        if (Distance(prey->getX(), pred[i]->getX(), prey->getY(), pred[i]->getY()) < minDistance) {
            closest = pred[i];
            minDistance = Distance(prey->getX(), pred[i]->getX(), prey->getY(), pred[i]->getY());
        }
    }

    return closest;
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
    int numIterations = 0;
    std::srand(std::time(nullptr));
    std::vector<Predator*>predators;
    std::vector<Prey*>preys;
    

    
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Game");
    State state = MENU;
    sf::Font font("ARIAL.TTF");
    sf::Text title(font, "Predator/Prey Simulation", 36);
    sf::Text endText(font, "Simulation Over", 36);
    endText.setPosition(sf::Vector2f(100, 200));
    endText.setFillColor(sf::Color::Black);
    title.setPosition(sf::Vector2f(100, 50));
    title.setFillColor(sf::Color::Black);
    sf::Text predatorTitle(font, "Number of Predators", 24);
    predatorTitle.setPosition(sf::Vector2f(100, 150));
    predatorTitle.setFillColor(sf::Color::Black);
    sf::Text preyTitle(font, "Number of Preys", 24);
    preyTitle.setPosition(sf::Vector2f(100, 250));
    preyTitle.setFillColor(sf::Color::Black);
    sf::RectangleShape inputbox1(sf::Vector2f(100, 30));
    sf::RectangleShape inputbox2(sf::Vector2f(100, 30));
    inputbox1.setPosition(sf::Vector2f(100, 200));
    inputbox2.setPosition(sf::Vector2f(100, 300));
    inputbox1.setOutlineThickness(2);
    inputbox2.setOutlineThickness(2);
    inputbox1.setOutlineColor(sf::Color::Black);
    inputbox2.setOutlineColor(sf::Color::Black);
    std::string input1, input2;
    sf::Text text1(font, "", 24);
    sf::Text text2(font, "", 24);
    text1.setFillColor(sf::Color::Black);
    text2.setFillColor(sf::Color::Black);
    text1.setPosition(sf::Vector2f(105, 203));
    text2.setPosition(sf::Vector2f(105, 303));
    int activeBox = 0;
    sf::RectangleShape button(sf::Vector2f(100, 50));
    button.setPosition(sf::Vector2f(100, 400));
    button.setFillColor(sf::Color::Green);
    sf::Text buttonText(font, "start", 24);
    buttonText.setPosition(sf::Vector2f(110, 410));
    buttonText.setFillColor(sf::Color::Black);



    
    // Start the game loop
    while (window.isOpen())
    {
        numIterations++;
        if (numIterations > 20000)
        {
            state = END;
        }
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
            {
                window.clear();
                for (int x = 0; x < preys.size(); x++)
                {
                    delete preys[x];
                }
                for (int i = 0; i < predators.size(); i++)
                {
                    delete predators[i];
                }

                window.close();
            }
               
            if (state == MENU)
            {
                if (event->is<sf::Event::MouseButtonPressed>())
                {
                    sf::Vector2f position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (inputbox1.getGlobalBounds().contains(position))
                    {
                        activeBox = 1;
                    }
                    else if (inputbox2.getGlobalBounds().contains(position))
                    {
                        activeBox = 2;
                    }
                    else
                    {
                        activeBox = 0;
                    }
                    if (button.getGlobalBounds().contains(position))
                    {
                        if (!input1.empty() && !input2.empty())
                        {
                            state = SIMULATION;
                            PopulatePredators(predators, preys, std::stoi(input1));
                            PopulatePreys(predators, preys, std::stoi(input2));
                        }
                    }
                }

                if (event->is<sf::Event::TextEntered>())
                {
                    if (activeBox != 0)
                    {
                        std::string* currentString = nullptr;
                        if (activeBox == 1)
                        {
                            currentString = &input1;
                        }
                        else if (activeBox == 2)
                        {
                            currentString = &input2;
                        }
                       

                      char code = event->getIf<sf::Event::TextEntered>()->unicode;
                      std::cout << "You entered: " << code << std::endl;
                      if (code >= '0' && code <= '9')
                      {
                          *currentString += code;
                      }
                      else if (code == 8 && !currentString->empty())
                      {
                          currentString->pop_back();
                      }
                      std::cout << "Input 1: " << input1 << std::endl;
                      std::cout << "Input 2: " << input2 << std::endl;
                      text1.setString(input1);
                      text2.setString(input2);

                    }


                    
                }
            }
        }
        if (state == MENU)
        {
            window.clear(sf::Color::White);
            window.draw(inputbox1);
            window.draw(inputbox2);
            window.draw(text1);
            window.draw(text2);
            window.draw(button);
            window.draw(buttonText);
            window.draw(title);
            window.draw(preyTitle);
            window.draw(predatorTitle);
            window.display();
          
        }
        else if (state == END)
        {
            window.clear(sf::Color::White);
            if (preys.size() == 0)
            {
                endText.setString("Simulation Over\nAll the preys were killed");
            }
            else
            {
                endText.setString("Simulation Over\nThe preys survived");
            }
            window.draw(endText);
            window.display();
            
        }
        else
        {
            // Clear screen
            window.clear(sf::Color::White);
            DisplayPredators(predators, &window);
            DisplayPreys(preys, &window);
            for (int x = 0; x < preys.size(); x++)
            {
                preys[x]->Move(ClosestPredator(preys[x], predators));
            }

            for (int i = 0; i < predators.size(); i++)
            {
                predators[i]->Move(ClosestPrey(predators[i], preys));
            }

            for (int i = preys.size() - 1; i >= 0; i--)
            {
                for (int j = 0; j < predators.size(); j++)
                {
                    if (Overlap(preys[i], predators[j]))
                    {
                        preys.erase(preys.begin() + i);
                        break;
                    }
                }

            }
            for (int i = 0; i < preys.size(); i++)
            {
                for (int j = i + 1; j < preys.size(); j++)
                {
                    if (Overlap(preys[i], preys[j]) && preys[i]->getCooldown() <= 0 && preys[j]->getCooldown() <= 0)
                    {
                        Prey* p = new Prey(rand() % 10 + 10, 100, 100, "prey", preys[i]->getX(), preys[i]->getY());
                        preys.push_back(p);
                        preys[i]->setCooldown(1000);
                        preys[j]->setCooldown(1000);
                    }
                }
            }
            // Update the window
            window.display();
        }

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
