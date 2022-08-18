#include "Item.hpp"

Item::Item(){}

Item::Item(string nome, string tipo_item, int qntd){
  this->nome = nome;
  this->tipo_item = tipo_item;
  this->qntd = qntd;
}

void Item::setNome(string nome){
  this->nome = nome;
}

void Item::setQntd(int val){
  this->qntd = val;
}

void Item::setTipo_item(string tipo_item){
  this->tipo_item = tipo_item;
}
