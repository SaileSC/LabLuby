#include "Consumivel.h"
#include <algorithm>


Consumivel::Consumivel()
{
    this->tipo = "Consumivel";
};


Consumivel::~Consumivel()
{

};


Consumivel::Consumivel(string nome, float uso, int quantidade, float custo)
{
    this->nome = nome;
    this->custo = custo;
    this->quantidade = quantidade;
    this->uso = uso;
    this->tipo = "Consumivel";
};


void Consumivel::setUso(float uso)
{
    this->uso = uso;
};


float Consumivel::getUso()
{
    return uso;
};


ostream & operator <<(ostream & out,Consumivel &item)
{
    string nome = item.getNome();
    replace(nome.begin(), nome.end(), ' ', '_');

    out<<item.getId()<<endl;
    out<<nome<<endl;
    out<<item.getTipo()<<endl;
    out<<item.getUso()<<endl;
    out<<item.getQuantidade()<<endl;
    out<<item.getCusto()<<endl;
    return out;
};


istream & operator >>(istream & get,Consumivel &item)
{
    string nome = item.nome;
    replace(nome.begin(), nome.end(), '_', ' ');

    get>>item.identificador;
    get>>item.nome;
    get>>item.tipo;
    get>>item.uso;
    get>>item.quantidade;
    get>>item.custo;
    return get;
};
