#include "../include/Managers/Graphics.h"

using namespace Managers;

    Graphics::Graphics(){
        /*TODO*/
    }
    //inicializa o ponteiro para instancia de Grapics como nulo
    Graphics* Graphics::instance = nullptr;
    // inicializa mtx
    std::mutex Graphics::mtx;

    Graphics* Graphics::get_instance(){
        //uso de nullptr no lugar de NULL devido a maior segurança e para evitar possiveis ambiguidades (boas praticas de c++11)
        if(instance == nullptr){
            /*a seguinte linha visa deixar o codigo mais seguro utilizando multithreads, e apesar de estar fora do ambito do projeto,
            foi implementada visando o aprendizado*/

            /*em um ambiente multithread, as varias threads podem tentar acessar ou modificar recursos compartilhados ao mesmo tempo, 
            e o mecanismo a seguir tenta sincroniza-las e impedir comportamentos imprevisiveis das mesmas:: 
            O tipo std::mutex utilizado é um obj que permite que diferentes threads se excluam ao tentar acessar mutuamente recursos 
            compartilhados. Tal feito é realizado pelas operaçoes de locks e unloked, nas quais caso alguma thread tente trancar um 
            mutex ja trancado, é bloqueada até que o mesmo seja desbloqueado*/
            /*std::lock_guard é um mecanismo de bloqueio RAII(Resource Acquisition Is Inicialization), que garante que o mutex seja
            automaticamente bloqueado quando std::lock_guard é criado, e que também seja desbloquado quando std::lock_guard saia de
            escopo (normalmente ao final do bloco em que foi definido) */
            std::lock_guard<std::mutex> lock(mtx);

            /*Tais medidas logo após a primeira verificaçao da nulidade do ponteiro para a instancia de Graphics garantem a que a proxima
            verificaçao seja mais segura e unica em seu tempo para as demais threads, a segunda verificaçao é necessaria devido a fila de 
            threads que o bloqueio dos obj mutex criam. Feita dessa maneira, a segunda verificaçao do ponteiro serve para garantir que a 
            instancia nao tenha sido criada por outra thread enquando a thread atual esperava para trancar o mutex*/
            if(instance == nullptr){
                //garantida a inexistencia de um obj Graphics, cria-o para a instancia "instance da classe"
                instance = new Graphics();
            }
        }
        /*retorna um ponteiro para o metodo privado instance da classe Graphics. Esse retorno garante a unicidade e globalidade do metodo
        singletown, pois caso ja exista um obj Graphics, é retornado um ponteiro para o mesmo, e na negativa, é criada a primeira e unica 
        instancia do mesmo, e retorna-a*/

        return instance;
    }






    // a destrutora continua publica
    Graphics::~Graphics(){

    }

