#include "../include/principal.h"

Principal::Principal(/* args */):
    window(sf::VideoMode(800.0f, 600.0f), "teste sfml") // cria uma janela em SFML
{
    executar();
}

Principal::~Principal()
{
}