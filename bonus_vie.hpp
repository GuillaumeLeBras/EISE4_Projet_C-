#ifndef BONUS_VIE
#define BONUS_VIE
#include "bonus.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

class Bonus;
class Bonus_vie : public Bonus{//classe du bonus de vie
    public :
    	Bonus_vie(int x, int y);
    	~Bonus_vie(){};
    	int getVie();
        Bonus_vie operator+(Bonus_vie bonus);
    protected :
    	int PDV_gagnes;


};

#endif
