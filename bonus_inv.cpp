#include "bonus_inv.hpp"
#include <iostream>

using namespace std;

Bonus_inv::Bonus_inv (int x, int y) : Bonus(x, y)
{ //bonus d'invincibilite, de couleur rose
	rect = sf::RectangleShape (sf::Vector2f(40, 80));
	rect.setFillColor(sf::Color (255,0,255));
	rect.setPosition(sf::Vector2f(x, y));
	type = INV; //on dit que l'element est de type Bonus Invincible
}

int Bonus_inv::getVie()
{
	return 0;
}
