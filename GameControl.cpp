#include "GameControl.hpp"


GameControl::GameControl(){}


void GameControl::tutorialMain(){
  cout << artes.tutorialPt2;
  cin >> pass;
  cout << artes.tutorialPt3;
  cin >> pass;
  return;
  
}
void GameControl::capa(){
  cout << artes.menu;
  cin >> pass;
};



int GameControl::Combate(){
  if (pokemonInimigo != 5){
    arena[1] = p1.Pokedex[pokemonInimigo];
  }
  cout << listaFaces[meuPokemon]; 
  cout << artes.vs << endl;
  cout << listaFaces[pokemonInimigo];
  this_thread::sleep_for(std::chrono::milliseconds(2000));
  cout << artes.combate;
  
  while(true){
    if(arena[0].getVida() <= 0){
      cout << "\nVoce Perdeu" << endl;
      return 0;    
    }
    
   for (int n = 0; n < 2; n++) {
     // printa a vida //
    cout << "\n" << arena[0].getNome() << ": " << arena[0].getVida() << " || " << arena[1].getNome() << ": " << arena[1].getVida() << endl;

     // nosso ataque:
    if (n == 0){
      this_thread::sleep_for(std::chrono::milliseconds(1000));
      cout << artes.combateOpc; 
      cin >> ataque;
      atacante = 0;
      defensor = 1;
      cout << listaFaces[meuPokemon]; 
    }
    // ataque inimigo:
    else{ 
      unsigned seed = time(0);
      srand(seed);

      if ((arena[0].getVida() == 40) || arena[1].getNome() == "Charizard"){
        ataque = 1;
      }
      else{
        ataque = arena[0].getVida() <= 80 ? (1 + rand() % 2) : (1 + rand() % 3);
      }
          
      atacante = 1;
      defensor = 0;

      this_thread::sleep_for(std::chrono::milliseconds(1000));
      cout << "\n----------------------------------- "<< endl;
      cout << listaFaces[pokemonInimigo];
    }   
     
    switch(ataque){
      case 1:
        arena[defensor].recebe_ataque_1(arena[atacante]);
        break;
      case 2:      
         arena[defensor].recebe_ataque_2(arena[atacante]);
        break;
      case 3:        
        arena[defensor].recebe_especial(arena[atacante]);
        break;
      case 4:
        cout << artes.item;
        cout << p1.Inventario[0].getQntd();
        cout << artes.item2;
        cout << p1.Inventario[1].getQntd();
        cout << artes.item3;
        cin >> itemOpc;

         switch(itemOpc){
          case 1:
            arena[0] = p1.usarItem(p1.Inventario[0], arena[0]);
            break;
          case 2:
            arena[0] = p1.usarItem(p1.Inventario[1], arena[0]);
            break;
          case 3:
            n++;
            break;
          default:
            cout << "\n Opção invalida" << endl;
        }
        break;
      default:
        cout << "\nPerdeu a vez" << endl;
     }
       
    if(arena[1].getVida() <= 0){
      cout << "\nVoce Venceu!!" << endl;
      return 1;
       }
    }
  }
}


void GameControl::gameMod1(){
  Inventario[0].setQntd(1);
  Inventario[1].setQntd(1);
  cout << "Escreva seu nome: " << endl;
  cin >> nome;
  p1.setNome(nome);
  
  cout << artes.MYpokedex << endl;
  cin >> meuPokemon;
  
  if (meuPokemon > 5 || meuPokemon < 0){
    return;
  }

  meuPokemon--;
  arena[0] = p1.escolher_pokemon(meuPokemon);
  cout << listaSkins[meuPokemon];
  this_thread::sleep_for(std::chrono::milliseconds(1000));

  cout << artes.Inimigopokedex << endl;
  cin >> pokemonInimigo;
  pokemonInimigo--;
  cout << listaSkins[pokemonInimigo];
  this_thread::sleep_for(std::chrono::milliseconds(1000));
  Combate();
}


void GameControl::InterfaceModoHistoria(){
  cout << artes.ModoHistoria;
}


void GameControl::campanha(){
  pokemonInimigo = 1;
  p1.Inventario[0].setQntd(1);
  p1.Inventario[1].setQntd(1);
  if (Combate()){
    level1();
  };
}

void GameControl::modoFacil(){
  p1.Inventario[0].setQntd(1);
  p1.Inventario[1].setQntd(1);
  
  level3();
}

void GameControl::ganhou_round(){
  p1.setMoeda(p1.getMoeda() + 10);
  int qntd = p1.Inventario[1].getQntd();
  p1.Inventario[1].setQntd(qntd + 1);
  if (arena[0].getVida() + 100 >= 400){
    arena[0].setVida(400);
  }
  else{
    arena[0].setVida(arena[0].getVida() + 100);
  }
}

void GameControl::loja(){
  int qntd;
  while(p1.getMoeda() != 0){
    cout  << "Dinheiro atual: " << p1.getMoeda();
    cout << artes.loja << endl;
    cin >> itemOpc;
    
    switch(itemOpc){
      case 1:
        qntd = p1.Inventario[0].getQntd();
        p1.Inventario[0].setQntd(qntd + 1);
        p1.setMoeda(p1.getMoeda() - 20);
        if (p1.getMoeda() == 10){
          p1.setMoeda(0);
        }
        break;
      case 2:
        qntd = p1.Inventario[1].getQntd();
        p1.Inventario[1].setQntd(qntd + 1);
        p1.setMoeda(p1.getMoeda() - 10);
        break;
      default:
        cout << "opção invalida" << endl;
    }
  }
}
     
void GameControl::level1(){
  
  loja();
  pokemonInimigo = 2;
  ganhou_round();
  if(Combate()){
    level2();
  };
}

void GameControl::level2(){
  pokemonInimigo = 3;  
  ganhou_round();
  if(Combate()){
    level3();
  };
}

void GameControl::level3(){
  pokemonInimigo = 4;
  ganhou_round();
  if(Combate()){
    level4();
  };
}


void GameControl::level4(){
  pokemonInimigo = 5;
  ganhou_round();
  loja();
  
  Pokemon chefao = Pokemon("Charizard", "Dragão");
  chefao.setVida(600);
  chefao.setDano(60);
  arena[1] = chefao;
  
  if(Combate()){
    cout << p1.getNome() << " Ganhou o torneio!!!" << endl;
    this_thread::sleep_for(std::chrono::milliseconds(2000));
    cout << artes.Parabens;
    cin >> pass;
    
  };
}


void GameControl::gameMod2(){
  Inventario[0].setQntd(1);
  Inventario[1].setQntd(1);
  InterfaceModoHistoria();
  tutorialMain();
  cout << artes.tutorialPt1;
  cin >> nome;
  
  p1.setNome(nome);
  cout << endl << "Escolha Seu Pokemon inicial:" << endl;
  cout << artes.MYpokedex;
  cin >> meuPokemon;
  
  if(meuPokemon > 5 ||meuPokemon < 0){
    cout << "Opção Invalida" << endl;
    return;
  }
    
  meuPokemon--;
  arena[0] = p1.escolher_pokemon(meuPokemon);
  cout << listaSkins[meuPokemon];
  this_thread::sleep_for(std::chrono::milliseconds(1000));
  
  cout << artes.Dificuldade << endl;
  cin >> dificuldade;
  if(dificuldade == 1){
    modoFacil();
  }
  else{
    campanha();
  }
}

void GameControl::gameMod3(){
  cout << artes.creditos;
  cin >> pass;
  return;
}
