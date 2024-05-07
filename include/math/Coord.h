#pragma once

#include <iostream>
using namespace std;

namespace Math{ 

template <typename TIPO>
class Coord{ 
public:
        TIPO x;
        TIPO y;
    Coord(TIPO x, TIPO y);
    Coord();
    ~Coord();

    // sobrecargas de operadores:

    // basicos ( =, +, -, *, / )

    void operator=(Coord<TIPO> coordenada);
    void operator+=(Coord<TIPO> coordenada);
    void operator-=(Coord<TIPO> coordenada);
    void operator*=(double escalar);
    void operator/=(double escalar);

    Coord<TIPO> operator+(Coord<TIPO> coordenada);
    Coord<TIPO> operator-(Coord<TIPO> coordenada);
    Coord<TIPO> operator*(Coord<TIPO> coordenada);
    Coord<TIPO> operator*(double escalar);
    Coord<TIPO> operator/(Coord<TIPO> coordenada);
    Coord<TIPO> operator/(double escalar);

};

template <typename TIPO>
    Coord<TIPO>::Coord(TIPO x, TIPO y):
        x(x),
        y(y)
        {   }
template <typename TIPO>
Coord<TIPO>::Coord(){
    this->x = 0;
    this->y = 0;
}
template <typename TIPO>
Coord<TIPO>::~Coord(){
    this->x = NULL;
    this->y = NULL;
}
    template <typename TIPO>
    void Coord<TIPO>::operator=(Coord<TIPO> coordenada){
        this->x = coordenada.x;
        this->y = coordenada.y;
    }

    template <typename TIPO>
    void Coord<TIPO>::operator+=(Coord<TIPO> coordenada){
        this->x += coordenada.x;
        this->y += coordenada.y;
    }

    template <typename TIPO>
    void Coord<TIPO>::operator-=(Coord<TIPO> coordenada){
        this->x -= coordenada.x;
        this->y -= coordenada.y;
    }

    template <typename TIPO>
    void Coord<TIPO>::operator*=(double escalar){
        this->x = this->x * escalar;
        this->y = this->y * escalar;
    }

    template <typename TIPO>
    void Coord<TIPO>::operator/=(double escalar){
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        this->x = this->x / escalar;
        this->y = this->y / escalar;
    }

    // *** DUVIDA *** estou retornando um objeto da classe coord, e chamando  sua construtora. na funçao, é rotornado o obj inicial ou um novo que é criado 
    // com a construtora. Se for o msm obj inicial, eu posso utilizar a construtora dele para modificar os parametros da mesma em qualquer momento:::

    //resposta: sim, ele cria um novo obj, IMPORTANTE, caso a classe coord tivesse ponteiros, seria necessario criar um new coord, pois a destrutora seria
    // chamada e apagaria os ponteiros
    //uso desse operador seria em casos como c = a+b
    template <typename TIPO>
    Coord<TIPO> Coord<TIPO>::operator+(Coord<TIPO> coordenada){
        return coord<TIPO>(this->x + coordenada.x, this->y + coordenada.y);
    }

    template <typename TIPO>
    Coord<TIPO> Coord<TIPO>::operator-(Coord<TIPO> coordenada){
        return coord<TIPO>(this->x - coordenada.x, this->y - coordenada.y);
    }

    template <typename TIPO>
    Coord<TIPO> Coord<TIPO>::operator*(Coord<TIPO> coordenada){
        return coord<TIPO>(this->x * coordenada.x, this->y * coordenada.y);
    }
 
    template <typename TIPO>
    Coord<TIPO> Coord<TIPO>::operator*(double escalar){
        return coord<TIPO>(this->x * escalar, this->y * escalar);
    }

    template <typename TIPO>
    Coord<TIPO> Coord<TIPO>::operator/(Coord<TIPO> coordenada){
        return coord<TIPO>(this->x / coordenada.x, this->y / coordenada.y);
    }

    template <typename TIPO>
    Coord<TIPO> Coord<TIPO>::operator/(double escalar){
        return coord<TIPO>(this->x / escalar, this->y / escalar);
    }





}