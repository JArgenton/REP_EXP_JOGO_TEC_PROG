#include "../include/Managers/Graphics.h"

#define FRAME_RATE_LIMIT 60
namespace Managers{

//inicializa o ponteiro para instancia de Grapics como nulo
Graphics* Graphics::instance = nullptr;
// inicializa mtx
std::mutex Graphics::mtx;

Graphics::Graphics():
    //faz com que o jogo sempre seja inicializado em tela cheia, o metodo getDesktopMode retorna as informaçoes da tela do usuario.
    window(new sf::RenderWindow(sf::VideoMode::getDesktopMode(),"game", sf::Style::Fullscreen)),
    // a funçao getDefaultView faz com que a visao cubra toda a janela
    view(window->getDefaultView()),
    frameRateLimit(FRAME_RATE_LIMIT),
    displayFPS(false),
    texturesMap(),
    fontsMap(),
    clock()
{
    /*TODO fps e detalhes*/
    window->setFramerateLimit(frameRateLimit);

}
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
Graphics::~Graphics(){
    //esse é o for mais sinistro que eu ja vi*****
    //essa implementaçao foi encontrada na aba learn/microsoft C++, C e assembler/ (tipo auto&) (& é usado pois estamos passando a var por referencia)
    /* 
    ***FUNCIONAMENTO*** 
    for(auto& _nome_var_ : vetor, lista, etc...){coisas} --> essa estrutura é padrao de C++11, e basicamente declara uma variavel dentro do for que 
    percorre todo elemento pertencente a std lib.
    simplesmente funciona, a exp auto automatiza o tipo, nao se fazendo necessario declarar o tipo da variavel auxiliar pois este sera retirado do proprio
    elemento da std lib. 
    auto também funciona para funçoes, podendo variar os tipos de retorno de uma funçao utilizando variaveis auto.
    */
   for(auto& MapElement : texturesMap){
        delete MapElement.second;
   }
    for(auto& MapElement : fontsMap){
       delete MapElement.second;
   }
}

sf::Font* Graphics::loadFont(const std::string& filepath){

    /*a primeira passagem verifiaca se a textura ja foi carregada, o metodo find() é implementado na biblioteca standart de c++,
    e retorna um ponteiro para a posiçao em que a textura foi encontrada. Caso a textura nao esteja localizada no mapa, a funçao
    retorna um ponteiro para uma posiçao especial no final dele, que pode ser acessada pelo metodo end().*/
    auto iterator = fontsMap.find(filepath);
    if(iterator != fontsMap.end()){
        //textura foi encontrada, retornamos iterator->second, que corresponde ao conteudo apontado por aquele filepath (a fonte em questao)
        return (iterator->second);
    }

    //caso nao encontremos, cria-sede um novo obj tipo fonte
    sf::Font* font = new sf::Font;
    //verifica se o filepath corresponde a uma fonte, caso nao encontre-a, delete o obj e sai do programa (erro)
    if(!font->loadFromFile(filepath)){
        delete font;
        std::cout<<"ERROR LOADING FILE" << filepath<< std::endl;
        exit(1);
    }     
    //add o obj criado no mapa, makepair deduz o tipo dos obj sendo inseridos.  
    fontsMap.insert(std::make_pair(filepath, font));

    return font;
}
sf::Texture* Graphics::loadTexture(const std::string& filepath){

    auto iterator = texturesMap.find(filepath);
    if(iterator != texturesMap.end()){
        return (iterator->second);
    }

    sf::Texture* texture = new sf::Texture;
    //verifica se o filepath corresponde a uma fonte, caso nao encontre-a, delete o obj e sai do programa (erro)
    if(!texture->loadFromFile(filepath)){
        delete texture;
        std::cout<<"ERROR LOADING FILE" << filepath<< std::endl;
        exit(1);
    }     

    texturesMap.insert(std::make_pair(filepath, texture));
    return texture;
}

//funçoes destinadas a carregar e centralizar a tela.
void setView(const sf::View& View);
const sf::View& getView();
void centerViewOn(const sf::Vector2f& position);

//funçoes para obter proporçoes da janela
sf::Vector2u getWindowSize() const;

/*a funçao retorna um timpo "FloatRect", tal estrutura é um retangulo com coordenadas com ponto flutuante que representam os limites 
da view atual com relaçao a janela. Essa funçao tera uso para o gerenciador de colisoes. */
sf::FloatRect getViewBounds();

//funçoes para manipulaçao da janela

void Graphics::clear(const sf::Color& color){
    window->clear(color);
}
void Graphics::render(sf::RectangleShape *body){
    window->draw(*body);
}
void Graphics::display(){
    window->display();
}
void Graphics::closeWindow(){
    window->close();
}

void setFrameRate(unsigned int rateLimit);
void showFPS(bool show);


}