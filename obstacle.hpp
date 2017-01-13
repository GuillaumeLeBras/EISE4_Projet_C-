#ifndef OBS
#define OBS
#include "element.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

class Element;
class Obstacle : public Element{
    public :
    	Obstacle(int x, int y);
    	~Obstacle();
    	int getVie();
        int operator+(Obstacle obstacle);
    protected :
    	int PDV_gagnes;
    	//sf::RectangleShape rect;




};
#endif
