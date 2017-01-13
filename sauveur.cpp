#include "sauveur.hpp"

using namespace std;

Sauveur::Sauveur (int x, int y, int vie) 
{
	this->x = x;
	this->y = y;
	this->vie = vie;
	if (!text_life.loadFromFile("heart.png"))
	{
    	// erreur...
    	cerr << "erreur chargement image" << endl;
	}
	sprite_life.setTexture (text_life);
	sprite_life.setScale(sf::Vector2f(0.01f*vie,0.01f*vie)); 
	sprite_life.setPosition(sf::Vector2f(40, 20));
	if (!text.loadFromFile("jesus.png"))
	{
    	// erreur...
    	cerr << "erreur chargement image" << endl;
	}
	sprite.setTexture (text);
	//sprite.setScale(sf::Vector2f(0.02f, 0.02f)); 
	sprite.setPosition(sf::Vector2f(x, y));
}

int Sauveur ::subir_degats(Element *e) //meme concept que pour le fasciste sauf que lui subit plus de degats et gagne plus de vie
{
	switch (e->getType())
	{
		case OBSTACLE :
			if (!inv)
			{
				cout << "vie avant : "<< vie << ";";
				vie += 3*e->getVie();
				if (vie > 0) //si vie > 0 on diminue la taille de l'image
					sprite_life.setScale(0.01f*vie,0.01f*vie);
				cout << " vie après : "<< vie << endl;
			}
			return 1;
			break;
			
		case INV :
	
			inv = true;
			sprite.setScale(3, 3);
			return 2;
			break;
		case VIE :
			vie += 2*e->getVie();
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
