#ifndef PERS
#define PERS

#include "element.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
enum Etat {jump, fall, down, up, normal}; //Etat de movement du personnage
class Element;
class Candidat 
{

public :
	
	Candidat();
	virtual ~Candidat(){};
	void sauter();
	bool isDead();
	sf::Sprite sprite;
	sf::Sprite sprite_life;
	std::pair <int,int> getPos();
	bool isJumping();
	bool isFalling();
	bool isDown();
	void tomber ();
	void baisser ();
	void relever();
	void setEtat(Etat e);
	Etat getEtat();
	virtual int subir_degats(Element *e) = 0;  ; //fonction a mettre en virtual pour redefinir dans classes filles
	void recupVie();
	void setInvBack();
protected : 
	int x, y; 
	sf::Texture text;
	sf::Texture text_life;
	int vie;
	bool jumping = false;
	bool falling = false;
	Etat etat = normal;
	bool inv = false;
	
	
 

};

#endif
