#include "obstacle.hpp"
#include <iostream>

using namespace std;

Obstacle::Obstacle (int x, int y) : Element(x, y)
{

	PDV_gagnes = -1;
	rect = sf::RectangleShape (sf::Vector2f(40, 80));
	rect.setFillColor(sf::Color (255,0,0));
	rect.setPosition(sf::Vector2f(x, y));
	type = OBSTACLE;
	/*if (!text.loadFromFile("element.png"))
	{
    	// erreur...
    	cerr << "erreur chargement image" << endl;
	}*/
	/*sprite.setTexture (text);
	sprite.setScale(sf::Vector2f(0.01f, 0.04f));
	sprite.setPosition(sf::Vector2f(x, y));*/


}

int Obstacle::getVie()
{
	return PDV_gagnes;
}

int Obstacle::operator+(Obstacle obstacle)
{
	this->PDV_gagnes = this->PDV_gagnes - obstacle.PDV_gagnes;
	return this->PDV_gagnes;
}
