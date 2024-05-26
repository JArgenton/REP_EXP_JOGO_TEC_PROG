#include "Entities/Characters/Player.h"

using namespace Entities;
using namespace Characters;

Player::Player(Math::CoordF pos = Math::CoordF(0.f, 0.f), bool isPlayer1 = true):
//Entity(pos, ),
isPlayer1(isPlayer1)

{

}
  
Player::~Player(){

}

void Player::update(float dt){

}

void Player::initialize(){

}