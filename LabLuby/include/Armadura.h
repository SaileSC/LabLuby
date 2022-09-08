#ifndef ARMADURA_H
#define ARMADURA_H

#include<string>
#include<iostream>

#include "Itens.h"

using namespace std;

//classe armadura extende classe item.
class Armadura : public Itens
{
private:
    //atributos especificos da armadura.
    float durabilidade;

    //sobrecarga metodos de entrada e saida para inserir e ler armadura de um arquivo txt.
    friend ostream & operator <<(ostream &out,Armadura &item);
    friend istream & operator >>(istream & get,Armadura &item);
public:
    Armadura();
    ~Armadura();
    Armadura(string nome,float durabilidade,int quantidade, float custo);

    //getters e setters.
    void setDurabilidade(float durabilidade);
    float getDurabilidade();
};

#endif // ARMADURA_H
