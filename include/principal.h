#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador/Jogador.h"

class Principal
{
private:
    sf::RenderWindow window;
    Jogador::Jogador jogador;
public:
    Principal();
    ~Principal();
    void executar();

};


