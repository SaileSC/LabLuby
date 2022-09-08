#include "Itens.h"


Itens::Itens()
{

};


Itens::~Itens()
{

};


Itens::Itens(int id, string nome, string tipo, float custo)
{
    this->identificador = id;
    this->nome = nome;
    this->tipo = tipo;
    this->custo = custo;
};


void Itens::setId(int id)
{
    this->identificador = id;
};


int Itens::getId()
{
    return identificador;
};


void Itens::setNome(string nome)
{
    this->nome = nome;
};


string Itens::getNome()
{
    return nome;
};


void Itens::setTipo(string tipo)
{
    this->tipo = tipo;
};


string Itens::getTipo()
{
    return tipo;
};


void Itens::setCusto(float custo)
{
    this->custo = custo;
};


float Itens::getCusto()
{
    return custo;
};


void Itens::setQuantidade(int quantidade)
{
    this->quantidade = quantidade;
};


int Itens::getQuantidade()
{
    return quantidade;
};

