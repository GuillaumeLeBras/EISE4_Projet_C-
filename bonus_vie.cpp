#include "bonus_vie.hpp"
#include <iostream>

using namespace std;

Bonus_vie::Bonus_vie (int x, int y) : Bonus(x, y)
{

	this->PDV_gagnes = rand()%4;
	rect = sf::RectangleShape (sf::Vector2f(40, 80));
	rect.setFillColor(sf::Color (0,0,255)); //couleur bleue
	rect.setPosition(sf::Vector2f(x, y));
	type = VIE; //on donne le type VIE aux bonus qui donne une vie supplémentaire.
}

int Bonus_vie::getVie()
{
	return PDV_gagnes;
}

Bonus_vie Bonus_vie::operator+(Bonus_vie bonus)
{
	this->PDV_gagnes = this->PDV_gagnes + bonus.PDV_gagnes;
	return *this;
}
