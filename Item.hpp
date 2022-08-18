#ifndef Item_hpp_included
#define Item_hpp_included

#include <iostream>
#include <string>
using namespace std;

class Item{
  private:
    string nome;
    string tipo_item;
    int qntd;

  public:
    Item();
    Item(string nome, string tipo, int qntd);

    void setNome(string nome);
    void setTipo_item(string tipo_item);
    void setQntd(int val);
    

    string getNome() const {return nome;};
    string getTipo_item() const {return tipo_item;};
    int getQntd() const {return qntd;};

};

#endif