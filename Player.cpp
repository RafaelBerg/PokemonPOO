#include "Player.hpp"

Player::Player(){
  this->nome = "Default";
}

Player::Player(string nome){
  this->nome = nome;
}

void Player::setNome(string nome){
  this->nome = nome;
}

void Player::setMoeda(int val){
  this->moeda = val;
}

Pokemon Player::escolher_pokemon(int val){
  return Pokedex[val];
}


Pokemon Player::usarItem(Item item, Pokemon p2){
  if (item.getQntd() != 0){
    if (item.getTipo_item() == "ataque"){
      p2.setDano(p2.getDano() + 20);
      Inventario[0].setQntd(Inventario[0].getQntd() - 1);
    }
      
    else if(item.getTipo_item() == "cura"){
      Inventario[1].setQntd(Inventario[1].getQntd() - 1);
      if (p2.getVida() + 150 > 400){
        p2.setVida(400);
      }else{
        p2.setVida(p2.getVida() + 150);
      }     
    }
  }else{
    cout << "Sem itens" << endl;
  }
  return p2;
}