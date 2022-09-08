#ifndef CONSUMIVEL_H
#define CONSUMIVEL_H

#include<string>
#include<iostream>

#include "Itens.h"

using namespace std;

//classe consumivel extende classe item.
class Consumivel : public Itens
{
private:
    //atributos especificos do consumivel.
    float uso;

    //sobrecarga metodos de entrada e saida para inserir e ler arma de um arquivo txt.
    friend ostream & operator <<(ostream &out,Consumivel &item);
    friend istream & operator >>(istream & get,Consumivel &item);
public:
    Consumivel();
    ~Consumivel();
    Consumivel(string nome, float uso, int quantidade, float custo);

    //getters e setters.
    void setUso(float uso);
    float getUso();
};

#endif // CONSUMIVEL_H
