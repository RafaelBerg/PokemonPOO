#ifndef Pokemon_hpp_included
#define Pokemon_hpp_included

#include <iostream>
#include <string>
using namespace std;

class Pokemon{
  private:
    int nivel = 1;
    int vida = 400;
    int dano = 40;
    string nome;
    string tipo;

  public:
    Pokemon();
    Pokemon(string nome, string tipo);

    void setNome(string nome);
    void setNivel(int nivel);
    void setVida(int vida);
    void setDano(int dano);
    void setTipo(string tipo);

    string getNome() const {return nome;};
    int getNivel() const {return nivel;};
    int getVida() const {return vida;};
    int getDano() const {return dano;};
    string getTipo() const {return tipo;};
    
    int analisar_tipo(Pokemon p2);
    void recebe_ataque_1(Pokemon p2);
    void recebe_ataque_2(Pokemon p2);
    void recebe_especial(Pokemon p2);
};

#endif