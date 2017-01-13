#include "fasciste.hpp"

using namespace std;
#include <iostream>
Fasciste::Fasciste (int x, int y, int vie) 
{
	this->x = x;
	this->y = y;
	this->vie = vie;
	if (!text_life.loadFromFile("heart.png"))
	{
    	// erreur...
    	cerr << "erreur chargement image" << endl;
	}
	sprite_life.setTexture (text_life); //on affecte les images correspondantes pour la vie et le personnage
	sprite_life.setScale(sf::Vector2f(0.01f*vie,0.01f*vie)); 
	sprite_life.setPosition(sf::Vector2f(40, 20));
	if (!text.loadFromFile("test.png"))
	{
    	// erreur...
    	cerr << "erreur chargement image" << endl;
	}
	sprite.setTexture (text);
	//sprite.setScale(sf::Vector2f(0.02f, 0.02f)); 
	sprite.setPosition(sf::Vector2f(x, y));
}

int Fasciste ::subir_degats(Element *e)
{
	switch (e->getType())
	{
		case OBSTACLE :
			if (!inv)
			{
				vie += e->getVie(); //on recupere le nombre de degats infliges par l'obstacle
				if (vie > 0) //si vie > 0 on diminue la taille de l'image
					sprite_life.setScale(0.01f*vie,0.01f*vie);
			}
			return 1;
			break;
			
		case INV : //cas ou on rencontre un bonus qui rend invincible
			inv = true;
			sprite.setScale(3, 3); //on grandit le personnage
			return 2; //on retourne 2 pour dire qu'on est devenu invincible
			break;
		case VIE :
			vie += e->getVie(); //on recupere le nombre de vies donnees par le bonus
			if (vie > 0) //si vie > 0 on augmente la taille de l'image
				sprite_life.setScale(0.01f*vie,0.01f*vie);
			return 3;
			break;
		case NONE :
		return 0;
			break;
	}
	return 0;
}
