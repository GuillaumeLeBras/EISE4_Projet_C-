#ifndef RAC
#define RAC

#include <SFML/Graphics.hpp>
#include "candidat.hpp"

class Candidat;

class Raciste : public Candidat {

public :
	Raciste (int x, int y, int vie);
	virtual ~Raciste() {};
	int subir_degats(Element *e);
protected :

};

#endif
