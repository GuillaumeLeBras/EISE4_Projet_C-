#ifndef FAS
#define FAS

#include <SFML/Graphics.hpp>
#include "candidat.hpp"

class Candidat;

class Fasciste : public Candidat {

public :
	Fasciste (int x, int y, int vie);
	virtual ~Fasciste(){};
	int subir_degats(Element *e);//redefinir icitte
protected :

};

#endif
