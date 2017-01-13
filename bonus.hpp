#ifndef BONUS
#define BONUS
#include "element.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

class Element;
class Bonus : public Element{ //classe qui va etre derivee en 2 types de bonus
    public :
    	Bonus(int x, int y);
    	virtual ~Bonus(){};
    	int getVie();
    
    protected :   
    	
    	                
                      
};

#endif
