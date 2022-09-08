#include "Armadura.h"
#include <algorithm>

Armadura::Armadura()
{
    this->tipo = "Armadura";
};


Armadura::~Armadura()
{

};


Armadura::Armadura(string nome,float durabilidade, int quantidade, float custo)
{
    this->nome = nome;
    this->durabilidade = durabilidade;
    this->quantidade = quantidade;
    this->custo = custo;
    this->tipo = "Armadura";
};


void Armadura::setDurabilidade(float durabilidade)
{
    this-> durabilidade = durabilidade;
};


float Armadura::getDurabilidade()
{
    return durabilidade;
};


ostream & operator <<(ostream & out,Armadura &item)
{
    string nome = item.getNome();
    replace(nome.begin(), nome.end(), ' ', '_');

    out<<item.getId()<<endl;
    out<<nome<<endl;
    out<<item.getTipo()<<endl;
    out<<item.getDurabilidade()<<endl;
    out<<item.getQuantidade()<<endl;
    out<<item.getCusto()<<endl;
    return out;
};


istream & operator >>(istream & get,Armadura &item)
{
    get>>item.identificador;
    get>>item.nome;
    get>>item.tipo;
    get>>item.durabilidade;
    get>>item.quantidade;
    get>>item.custo;
    return get;
};
