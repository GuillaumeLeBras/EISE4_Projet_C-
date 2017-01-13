#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include "element.hpp"
#include "candidat.hpp"
#include "bonus.hpp"
#include "obstacle.hpp"
#include "fasciste.hpp"
#include "bonus_vie.hpp"
#include "bonus_inv.hpp"
#include "raciste.hpp"
#include "sauveur.hpp"
const int NB_OBS = 10;
using namespace std;

class Monde {

	private: 
		bool finished = false;
		list <Element*> E;
		int timer_count;
		sf::RenderWindow *win;
		sf::Clock clk_world;
		sf::Clock clk_move;
		sf::Clock clk_inv;
		Candidat *f;
		sf::Sprite lost;
		sf::Texture text_lost;
		sf::Sprite victoire;
		sf::Texture text_win;
		sf::Sprite image_fond;
		sf::Texture texture;
		sf::Texture text_obs;

	public:
		Monde(sf::RenderWindow *app, char c);
		~Monde();
		void deplacer_fond_and_collide();
		void dessiner();
		void jouer ();
		void manage_clock();
		void manage_event();
		void generate (int nb_obs, int nb_bonus);
		void launch_clk_inv();
};
