#include "monde.hpp"
#include <iostream>
using namespace std;
Monde::Monde(sf::RenderWindow *app, char c)
{
	win = app;
	if (!texture.loadFromFile("white house.png")) //charge en mémoire l'image de fond du jeu
	{
	    	// erreur...
	    	cerr << "erreur chargement image" << endl;
	}
	if (!text_lost.loadFromFile("gameover.png")) //charge en mémoire l'image de game over
	{
	    	// erreur...
	    	cerr << "erreur chargement image" << endl;
	}
	if (!text_win.loadFromFile("fin.png")) //charge en mémoire l'image de game over
	{
	    	// erreur...
	    	cerr << "erreur chargement image" << endl;
	}
	lost.setTexture(text_lost); //on affecte l'image de game over a la sprite qu'on affichera
	image_fond.setTexture (texture); 
	lost.setScale (0.4,0.4);
	image_fond.setScale(0.8,0.6);
	victoire.setTexture(text_win); //on affecte l'image de game over a la sprite qu'on affichera
	victoire.setScale (0.75,0.8);
	if (c == '0') //utilisation des commandes
		f = new Fasciste (90, 350, 10);
	if (c == '1')
		f = new Raciste ( 90, 350, 10);
	if (c == '2')
		f = new Sauveur (90, 350, 10);
	generate (NB_OBS, 10);
}
void Monde::generate(int nb_obs, int nb_bonus) //generation des obstacles et des bonus
{
	int prev_val_x = 400;
	int prev_val_y = 300;
	for (int i = 0; i < nb_obs; i++) //
	{
		//nouvel obstacle : position en x comprise entre position en x de l'obstacle précédent et position en x precedente +200
		prev_val_x = prev_val_x+(rand()%12+4)*10 ; 
		prev_val_y = 350 - 50*(rand()%3); //position aléatoire en y compris entre 350 et 250
		E.push_back(new Obstacle(prev_val_x, prev_val_y)); //on ajoute à la fin de la liste le nouvel obstacle
		//cout << "obstacle : " << prev_val_x << " ; " << prev_val_y << endl;
		
	}
	//cout <<"fin obs " << endl;
	prev_val_x = 400;
	for (int i = 0; i < nb_bonus; i++)
	{
		//nouveau bonus : position en x comprise entre position en x de le bonus précédent et position en x precedente +200
		prev_val_x = prev_val_x+(rand()%120+4)*10 ; 
		prev_val_y = 350 - 50*(rand()%3); //position aléatoire en y compris entre 350 et 250
		//cout <<"fin obs " << endl;
		E.push_back(new Bonus_vie(prev_val_x, prev_val_y)); //on ajoute à la fin de la liste le nouveau bonus
		//cout << "Bonus vie : " << prev_val_x << " ; " << prev_val_y << endl;
	}
	E.push_back(new Bonus_inv(rand()%1000+2000, 350 - 50*(rand()%3))); //on ajoute, quelque pat le bonus d'invicibilite
}
void Monde::manage_clock() //gestion des timers
{
	
	if (clk_world.getElapsedTime().asMilliseconds() > 3)//horologe déplacement éléments
	{
		deplacer_fond_and_collide (); //toutes les 3ms on deplace le fond
		clk_world.restart();
	}
	if (clk_move.getElapsedTime().asMilliseconds() > 500 ) //horologe sauter et baisser
	{
		if (f->isJumping())
			f->tomber();
		else if (f->isDown())
			f->relever();
	}
	
	if (clk_inv.getElapsedTime().asSeconds() > 10) //fin du bonus d'invincibilite
	{
		f->setInvBack();
	}

}


void Monde::jouer()
{
	if (!f->isDead())
	{
		manage_clock(); //on gere les timers

		
	}
	manage_event(); //on gere les evenements
	dessiner(); //on affiche tout a l'ecran
	
}

void Monde::manage_event() //gestion des evenements
{
	sf::Event event;
		 // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        while (win->pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            if (event.type == sf::Event::Closed)
                win->close();
            if (event.type == sf::Event::KeyPressed)//si on presse espace : saut
            	if (event.key.code == sf::Keyboard::Space)
            	{
            		if (f->getEtat() == Etat::normal)
            		{
            			f->sauter();
            			clk_move.restart();
            		}
            	}	
            	if (event.key.code == sf::Keyboard::B) //si c'est B : on se baisse
            	{
            		if (f->getEtat() == Etat::normal)
            		{
            			f->baisser();
            			clk_move.restart();
            		}
            	}	
        } 
}

void Monde::dessiner() //affichage des elements
{
	int cpt = 0;//compteur pour savoir si tous les obstacles sont devenus invisible (collision ou sortie de l'ecran)
	win->clear(sf::Color::Black);
	if (!f->isDead())
	{		
		if (!finished)
		{ 
			win->draw(image_fond);
			list<Element *>::const_iterator it;
			for (it = E.begin(); it != E.end(); it++)//on parcourt la liste des elements
			{
				if ((*it)->getVisible()) //si l'element est visible on le dessine
					win->draw((*it)->rect);
				else if ((*it)->getType() == OBSTACLE) //sinon si c'est un obstacle et qu'il est invisible : on compte
					cpt++;
			}
			win->draw(f->sprite_life);
			win->draw(f->sprite);
			if (cpt == NB_OBS) //si tous les obstacles ont été rendus invisibles : victoire
				finished = true;
		}
		else 
			win->draw(victoire);		
	}
	else //si les candidat est mort : on affiche l'ecran de defaite
		win->draw(lost);	
}

void Monde::deplacer_fond_and_collide () //la collision et le deplacement du fond ont été mélangés pour des raisons d'optimisation des calculs
{	
	list<Element *>::const_iterator it;
	for (it = E.begin(); it != E.end(); it++) //on parcourt la liste 
	{
		if ((*it)->collide(f)  ) //et on collisionne chaque élément.
		{
			if(f->subir_degats((*it)) == 2) //si on est devenu invincible : on relance le timer d'invincibilite
			{
				clk_inv.restart();
			}			
		}	
		if ((*it)->getVisible()) //puis on déplace
		{
			
			(*it) -> deplacer();
		}
		if ( get<0>((*it)->getPos()) < -41) //enfin si ça sort de l'écran, on arrete de le dessiner
		{
			(*it)->setVisible(false);
		}
	}
}


