#include "Game.h"
#include "Managers/Graphics.h"

using namespace Managers;
using namespace Entities::Characters;
Game::Game():
GraphicManager(Graphics::get_instance()),
Player1()
{
    exec();
}

Game::~Game(){
}

void Game::exec(){
    while(GraphicManager->isWindowOpen()){
        GraphicManager->updateDeltaTime();
        GraphicManager->clear();

        /*TODO*/
        /*update all and render all*/

        GraphicManager->display();
    }
}