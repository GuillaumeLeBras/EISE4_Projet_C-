#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "element.hpp"
#include "monde.hpp"
#include "candidat.hpp"
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	srand(time(NULL)); //initialisation de la seed pour le random
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode (900, 500), "POTUS ATTACK"); //creation de la fenetre graphique
	window->setFramerateLimit(90);
	if (argc == 1)
	{
		cout <<"lancez le programme avec 0 pour porter la parole Fasciste au sommet, \n1 pour faire régner le racisme \net 2 pour tous nous sauver" <<endl;
		return 0;
	}
	else if (!strcmp(argv[1], "-h"))
	{
		cout <<"lancez le programme avec 0 pour porter la parole Fasciste au sommet, \n1 pour faire régner le racisme \net 2 pour tous nous sauver" <<endl;
		return 0;
	}
	Monde *m = new Monde (window, argv[1][0]); //initialisation du monde dans lequel le jeu se déroule

	//window->setFramerateLimit(50);
	 while (window->isOpen()) //tant que la fenetre est ouverte on joue
    	{

		m->jouer();
		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window->display();
   	}

	return 0;
}
