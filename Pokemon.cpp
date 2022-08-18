#include "Pokemon.hpp"

// aleatoriedade
#include <cstdlib>
#include <ctime>

// sleep
#include <chrono>
#include <thread>

Pokemon::Pokemon(){};

Pokemon::Pokemon(string nome, string tipo){
  this->nome = nome;
  this->tipo = tipo;
}

void Pokemon::setNome(string nome){
  this->nome = nome;
}

void Pokemon::setNivel(int nivel){
  this->nivel = nivel;
}

void Pokemon::setVida(int vida){
  this->vida = vida;
}

void Pokemon::setDano(int dano){
  this->dano = dano;
}

void Pokemon::setTipo(string tipo){
  this->tipo = tipo;
}


// COMBATE //

int Pokemon::analisar_tipo(Pokemon p2){
  // ex: tipo[0] é fraco contra fraqueza[0] e fraqueza[1]
   string tipos[5] = {"fogo", "eletrico", "aquatico", "voador", "grama"};
  
  string fraqueza[10] = {"aquatico", "voador", "grama", "fogo", "eletrico", "grama", "eletrico", "aquatico", "fogo", "voador"};
  
  int x = 0;
  for (string tipo : tipos){
    if (getTipo() == tipo){
      int retorno = p2.getTipo() == fraqueza[x] || p2.getTipo() == fraqueza[x+1] ? 1 : 0;
      if (retorno){
        return 1;
      }
    }
    x += 2;
  } 
  return 0;
}


void Pokemon::recebe_ataque_1(Pokemon p2){
  // sleep - pausa
  this_thread::sleep_for(chrono::milliseconds(800));
  
  int dano = analisar_tipo(p2) ? p2.getDano() + 10 : p2.getDano();
  setVida(getVida() - dano);
  cout << endl << p2.getNome() <<" desferiu "<< dano << " de dano"  << endl;   
}


void Pokemon::recebe_ataque_2(Pokemon p2){
  // aleatoriedade
  unsigned seed = time(0);
  srand(seed);
  int aleat = 1 + rand() % 2;

  // sleep - pausa
  this_thread::sleep_for(chrono::milliseconds(800));

  // acertou ataque
  if (aleat == 1){
    int dano = analisar_tipo(p2) ? p2.getDano() + 40 : p2.getDano() + 30;
    
    setVida(getVida() - dano);
    cout << endl << p2.getNome() <<" desferiu "<< dano << " de dano"  << endl;  
  }

  // errou o ataque
  else{
    cout << "\n" << p2.getNome() << " Errou o ataque FORTE!" << endl;
  }
}


void Pokemon::recebe_especial(Pokemon p2){
  // aleatoriedade
  unsigned seed = time(0);
  srand(seed);
  int aleat = 1 + rand() % 3;

  // sleep - pausa
  this_thread::sleep_for(chrono::milliseconds(800));

  if (aleat == 1){
    int dano = analisar_tipo(p2) ? p2.getDano() + 110 : p2.getDano() + 100;

    setVida(getVida() - dano);
    cout << endl << p2.getNome() <<" desferiu "<< dano << " de dano"  << endl; 
  }
  // errou o ataque
  else{
    cout << "\n" << p2.getNome() << " Errou o ataque ESPECIAL!" << endl;
  }
}
