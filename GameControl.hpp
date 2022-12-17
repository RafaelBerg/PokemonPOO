#ifndef GameControl_hpp_included
#define GameControl_hpp_included

#include "Arts.hpp"
#include "Player.hpp"

// aleatoriedade
#include <cstdlib>
#include <ctime>
#include <cstdio>

// sleep
#include <chrono>
#include <thread>


class GameControl{
  public:
    GameControl();
    Arts artes = Arts();
    string listaSkins[6] = {artes.pikachu, artes.Charmander, artes.Bubassauro, artes.Squirtle, artes.Pidgey,artes.Charizard};
    string listaFaces[6] = {artes.pikachuFace, artes.charmanderFace, artes.bubassauroFace, artes.squirtleFace, artes.PidgeyFace,artes.CharizardFace};

    int op, itemOpc, atacante, defensor, ataque, meuPokemon, pokemonInimigo, dificuldade;
    string pass, nome;

    Player p1 = Player("Default");
    Pokemon arena[2];

    void tutorialMain();
    void capa();
    int Combate();
    void gameMod1();
    void InterfaceModoHistoria();
    void campanha();
    void modoFacil();
    void level1();
    void level2();
    void level3();
    void level4();
    void gameMod2();
    void gameMod3();
    void ganhou_round();
    void loja();

};

#endif