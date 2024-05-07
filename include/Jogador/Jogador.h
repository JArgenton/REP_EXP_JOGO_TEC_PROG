#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Jogador{
    class Jogador
    {
    private:
        sf::RectangleShape body;
        sf::Vector2f speed;
        void inicializa();
    public:
        Jogador(const sf::Vector2f size, const sf::Vector2f position);
        Jogador(const sf::RectangleShape body);
        Jogador();
        ~Jogador();
        void move();
        const sf::RectangleShape get_body();
    };
}