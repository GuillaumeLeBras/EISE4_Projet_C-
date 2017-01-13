#ifndef BONUS_INV
#define BONUS_INV
#include "bonus.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

class Bonus;
class Bonus_inv : public Bonus{ //classe du bonus d'invicibilite
    public :
    	Bonus_inv(int x, int y);
    	~Bonus_inv(){};
    	int getVie(); //retourne 0 car ne donne pas de vie supplémentaire
    
    protected :   
    	
    	                
                      
};

#endif
