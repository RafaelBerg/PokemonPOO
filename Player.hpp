#ifndef Player_hpp_included
#define Player_hpp_included

#include "Item.hpp"
#include "Pokemon.hpp"

class Player{
  private:
    string nome;
    int moeda = 0;
    
  public:
    Pokemon Pokedex[6] = {Pokemon("Pikachu","eletrico"),
Pokemon("Charmander","fogo"),
Pokemon("Bubassauro","grama"),
Pokemon("Squirtle", "aquatico"),
Pokemon("Pidgey", "voador")};

    Item Inventario[2] = {Item("Buff de dano", "ataque", 0), Item("Pocao", "cura", 0)};

    Player();
    Player(string nome);
    void setNome(string nome);
    void setMoeda(int val);

    string getNome() const {return nome;};
    int getMoeda() const {return moeda;};

    Pokemon escolher_pokemon(int val);

    Pokemon usarItem(Item item, Pokemon p2);
};


#endif
