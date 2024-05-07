#include "../include/principal.h"

Principal::Principal(/* args */):
    window(sf::VideoMode(800.0f, 600.0f), "teste sfml"), // cria uma janela em SFML
    jogador(sf::Vector2f(50.0f,150.0f), sf::Vector2f(400.0f, 300.0f))
{
    executar();
}

Principal::~Principal()
{
}
void Principal::executar(){
    //criando um obj na (retangulo)
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

        /*quando criamos um evento, todas as classes que possuem evento sao chamadas, por exemplo, a funçao jogador.move() possui 
        uma condiçao que depende de um evento (mover caso tecla esteja pressionada), e nao necessita nenhum evento passado em sua chamada*/
        window.clear(); // limpa a tela anterior
        jogador.move();
        window.draw(jogador.get_body()); //desenha um obj
        window.display(); /*atualiza a tela, mostrando todos os obj desenhados*/
    }   
    
}