#include "element.hpp"
#include <iostream>

using namespace std;

Element::Element(int x, int y){
this -> x= x;
this -> y= y;

}
Type Element::getType()
{
	return type;
}
pair <int,int> Element:: getPos(){ //retourner les coordonnees sous forme de std::pair
return make_pair(x,y);

}

void Element::deplacer() //on fait deplacer l'element vers la gauche
{
	rect.move(-2, 0);
	x = x-2;
}

bool Element:: getVisible()
{
	return visible;

}

void Element:: setVisible(bool b) //on rend l'objet invisible
{
	 visible = b;

}

bool Element::collide(Candidat *c)
{
	//on teste si les deux elements sont en intersection
	if ( (c->sprite.getPosition().x +10) >  x - 2   && x + 28 > (c->sprite.getPosition().x-10) 
	&&  y -10 < (c->sprite.getPosition().y ) && y +78 > (c->sprite.getPosition().y))
	{	
		if (visible) //is l'element etait visible, on le rend invisible  et on dit qu'il y a eu collision (return true)
		{
			visible= false;
			return true;
		}
	}
	return false;
}
