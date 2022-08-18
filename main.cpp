#include "GameControl.hpp"


int main() {
  // Menu:
  int op;
  GameControl gc = GameControl();
  gc.capa();

  while (true) {
    cout << gc.artes.menu2;
    cin >> op;
    switch (op) {
      case 1:
        gc.gameMod1();
        break;
      case 2:
        gc.gameMod2();
        break;
      case 3:
        gc.gameMod3();
        break;
      case 4:
        gc.tutorialMain();
        break;
      case 5:
        exit(0);
      default:
        cout << "opção errada";
        exit(0);
        } 
  }
}
  
