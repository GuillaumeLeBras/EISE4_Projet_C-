#ifndef SAU
#define SAU

#include <SFML/Graphics.hpp>
#include "candidat.hpp"

class Candidat;

class Sauveur : public Candidat {

public :
	Sauveur (int x, int y, int vie);
	virtual ~Sauveur(){};
	int subir_degats(Element *e);
protected :

};

#endif
