#include "../include/principal.h"

Principal::Principal(/* args */):
    window(sf::VideoMode(800.0f, 600.0f), "teste sfml") // cria uma janela em SFML
{
    executar();
}

Principal::~Principal()
{
}
void Principal::executar(){
    //criando um obj na (retangulo)
    sf::RectangleShape jogador(sf::Vector2f(50.0f, 50.0f)); /* cria um obj retangular com as proporçoes indicadas*/
    jogador.setFillColor(sf::Color::Blue); /* define a cor do jogador*/
    jogador.setPosition(50.0f,50.0f); // altera posiçao do jogador
    while (window.isOpen()) // propriedade da classe window, que verifica se a mesma esta aberta
    {
        sf::Event evento; // cria obj classe evento
        if(window.pollEvent(evento)){ //propriedade classe window que verifica eventos
            if(evento.type == sf::Event::Closed){//evento tem uma propriedade typo, que pode ser verificada com outros metodos da classe
                window.close(); // metodo classe window
            } else if(evento.type == sf::Event::KeyPressed){ // a classe evento possui uma outra classe, que é um tipo de evento, que ppode ser uma chave press
                if(evento.key.code == sf::Keyboard::Escape){ // sendo uma chave, o obj evento/keypressed possui um mtodo code, que le a tecla desejada
                    window.close();
                }
            }
        } 
        window.clear(); // limpa a tela anterior
        window.draw(jogador); //desenha um obj
        window.display(); /*atualiza a tela, mostrando todos os obj desenhados*/
    }   
    
}