#include "Math/Coord.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

namespace Managers{

    /*A Criaçao dessa classe foi baseada nos tutoriais do antigo monitor de tecprog Burda e em diversos materias encontrados 
    tanto online quanto gerados por IAs*/

    class Graphics
    {
    private:
    // linha de codigo baseado sob o Singletown design pattern, também foram usadas referencias de codigo gerado por IAs e pelo Monitor Burda

    /* O padrao singletown assegura que apenas uma instancia de uma classe seja criada durante a execuçao do codigo, e que essa instancia póssa ser
    fornecida de maneira global a todo o codigo, sendo util quando é necessario que apenas um unico obj coordene açoes em todo o sistema, exatamente 
    o caso de um gerenciador grafico*/

    // Para garantir o acesso global do obj, este possui uma instancia de si mesmo como metodo privado, que sera retornado para uso externo via get_instance
    static Managers::Graphics* instance;

    //Garante a segurança da execuçao unica da classe mesmo em MultiThread, desnecessario para o atual projeto, mas implementada a fins de aprendizado
    static std::mutex mtx;

    // A construtora privada garante que objs da classe nao possam ser criados fora dela
    Graphics();

    public:

    // as proximas duas passagem talvez sejam desnecessarias para o projeto, mas também foi implementada para fins de aprendizado
    /* Essa passagem DELETA O CONSTRUTOR DE COPIAS DA CLASSE, fazendo com que nao seja possivel copiala para outras instancias e garante o Singletown*/
    Graphics(const Graphics&) = delete;

    /* A seguinte passagem delete o OPERADOR DE ATRIBUIÇAO da classe Graphics, fazendo com que nao seja possivel atribuir um obj Graphics a outro
    O uso de Graphics& indica o retorno de uma referencia a si mesmo
    Igualar a funçao a delete DELETA A FUNÇAO. a implementaçao dessa operaçao segue uma logica semelhante a igualar funçoes virtuais a 0 quando 
    queremos impedi-las de serem utilizadas na classe em que foram declaradas "func() = 0"*/
    Graphics& operator=(const Graphics&) = delete;

    /*Metodo que torna a instacia da classe global, na qual a funçao retorna um ponteiro para uma instancia de Graphics, a implementaçao esta mais 
    detalhada em Graphics.cpp, mas em resumo, é realizado um teste para determinar se ja existe um obj Graphics declarado, em caso afirmativo, a funçao
    apenas retorna um ponteiro para tal obj, e em caso contrario a construtora privada da classe é chama, criando um novo obj e passando-o como ponteiro
    Além disso, o metodo também possui uma passagem std::lock_guard<std::mutx> lock(ntx), que garante a seguraça da criaçao unica mesmo em multithread*/
    static Graphics* get_instance();


    /*No arquivo cpp também estao inicializados os metodos estaticos da classe, sendo instance delcarada como null e mutex  como mtx*/







    // a destrutora continua publica
    ~Graphics();


    };

}