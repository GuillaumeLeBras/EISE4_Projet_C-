#ifndef ELEM
#define ELEM

#include <SFML/Graphics.hpp>
#include "candidat.hpp"
using namespace std;
enum Type {INV, NONE, OBSTACLE, VIE};
class Candidat;
class Element
{
public :
	Element();
	Element (int x, int y);
	~Element(){};
	pair <int, int> getPos();
	sf::Sprite sprite;
	void deplacer();
	bool collide(Candidat *c);
	bool getVisible();
	void setVisible(bool b);
	sf::RectangleShape rect;
	Type getType();
	virtual int getVie()=0;
protected: 
	int x, y; 
	sf::Texture text; 
	bool visible = true;
	Type type;
};

#endif
