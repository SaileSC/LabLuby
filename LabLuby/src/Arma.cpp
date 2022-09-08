#include "Arma.h"
#include <algorithm>

Arma::Arma()
{
    this->tipo = "Arma";
};


Arma::~Arma()
{

};


Arma::Arma(string nome,float dano ,int quantidade,float custo )
{
    this->nome = nome;
    this->custo = custo;
    this->quantidade = quantidade;
    this->dano = dano;
    this->tipo = "Arma";
};


void Arma::setDano(float dano)
{
    this->dano = dano;
};


float Arma::getDano()
{
    return dano;
};


ostream & operator <<(ostream & out,Arma &item)
{
    string nome = item.getNome();
    replace(nome.begin(), nome.end(), ' ', '_');

    out<<item.getId()<<endl;
    out<<nome<<endl;
    out<<item.getTipo()<<endl;
    out<<item.getDano()<<endl;
    out<<item.getQuantidade()<<endl;
    out<<item.getCusto()<<endl;
    return out;
};


istream & operator >>(istream & get,Arma &item)
{
    get>>item.identificador;
    get>>item.nome;
    get>>item.tipo;
    get>>item.dano;
    get>>item.quantidade;
    get>>item.custo;
    return get;
};
