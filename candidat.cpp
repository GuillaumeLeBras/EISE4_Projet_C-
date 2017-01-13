#include "candidat.hpp"
#include <iostream>

using namespace std;

Candidat::Candidat()
{

	
}

pair <int,int> Candidat:: getPos(){
return make_pair(x,y);
}
void Candidat:: sauter()
{
	y -= 70;
	sprite.setPosition(x, y);
	//jumping = true;
	etat = jump;
}

void Candidat::tomber ()
{
	y += 70;
	sprite.setPosition(x, y);
	falling = true;
	jumping = false;
	etat = normal;	
}

void Candidat::setEtat(Etat e)
{
	etat = e;
}

Etat Candidat::getEtat()
{
	return etat;
}
bool Candidat::isDead()
{
	if (vie <= 0)
		return true;
	else return false;
}

void Candidat::baisser() //on fait baisser le personnage
{
	y += 40;
	sprite.setScale(1,0.5f);
	sprite.setPosition(x, y);
	etat = down;
}

void Candidat::relever() //on fait se relever le personnage
{
	y -= 40;
	sprite.setScale(1,1);
	sprite.setPosition(x, y);
	etat = normal;
}
bool Candidat::isDown()
{
	return etat==down;
}
bool Candidat::isJumping()
{
	return etat==jump;
}
bool Candidat::isFalling()
{
	return etat==fall;
}
void Candidat::recupVie() //on gagne une vie et on augmente la taille du coeur
{
	vie++;
	sprite_life.setScale(0.01f*vie,0.01f*vie);
}

void Candidat::setInvBack() //on remet a taille normale apres l'invincibilite
{
	inv = false;
	sprite.setScale(1, 1);
}
