#include "../include/Jogador/Jogador.h"
using namespace Jogador;

    Jogador::Jogador::Jogador(const sf::Vector2f size, const sf::Vector2f position):
    body(sf::RectangleShape(size))
    
    {
        body.setPosition(position);
        inicializa();

    }
    Jogador::Jogador::Jogador(const sf::RectangleShape body):
    body(body)
    {
        inicializa();
    }
    Jogador::Jogador::Jogador():
        body()
    {
        inicializa();
    }
    Jogador::Jogador::~Jogador(){

   }
   void Jogador::Jogador::inicializa(){
    speed = sf::Vector2f(0.1f,0.1f);
   }

    void Jogador::Jogador::move(){
        /* move com base nas teclas A, S , D , W*/
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){    
            body.move(-speed.x, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){    
            body.move(0.0f, +speed.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){    
            body.move(0.0f, -speed.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){    
            body.move(speed.x, 0.0f);
        }
        






    }
    const sf::RectangleShape Jogador::Jogador::get_body(){
        return body;;
    }
    