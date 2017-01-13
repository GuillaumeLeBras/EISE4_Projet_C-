#include "raciste.hpp"

using namespace std;

Raciste::Raciste (int x, int y, int vie) 
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
	if (!text.loadFromFile("trump sprite.png"))
	{
    	// erreur...
    	cerr << "erreur chargement image" << endl;
	}
	sprite.setTexture (text);
	sprite.setScale(sf::Vector2f(0.6f, 0.6f)); 
	sprite.setPosition(sf::Vector2f(x, y));
}

int Raciste ::subir_degats(Element *e) //Le raciste subit plus de degats que le fasciste mais moins que le sauveur
{
	switch (e->getType())
	{
		case OBSTACLE :
			if (!inv)
			{
				cout << "vie avant : "<< vie << ";";
				vie += 2*e->getVie();
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
			vie += e->getVie();
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
