#ifndef ARMA_H
#define ARMA_H

#include<iostream>
#include<string>

#include "Itens.h"

using namespace std;

//classe arma extende classe item.
class Arma : public Itens
{
private:
    //atributos especificos da arma.
    float dano;

    //sobrecarga metodos de entrada e saida para inserir e ler arma de um arquivo txt.
    friend ostream & operator <<(ostream &out,Arma &item);
    friend istream & operator >>(istream & get,Arma &item);
public:
    Arma();
    ~Arma();
    Arma(string nome, float dano, int quantidade, float custo);

    //getters e setters.
    void setDano(float dano);
    float getDano();
};

#endif // ARMA_H
