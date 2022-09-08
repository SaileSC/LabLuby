#include "Venda.h"

Venda::Venda()
{

};


Venda::~Venda()
{

};


Venda::Venda(int quant, float custoTotal, int idItem, string nomeItem, float custoUnidade)
{
    this->quantidadeVendida = quant;
    this->custoFinal = custoTotal;
    this->identificadorItem = idItem;
    this->nomeItem = nomeItem;
    this->custoUnidade = custoUnidade;
};


int Venda::getId()
{
    return identificador;
};


void Venda::setId(int id)
{
    this->identificador = id;
};


int Venda::getIdItem()
{
    return identificadorItem;
};


void Venda::setIdItem(int id)
{
    this->identificadorItem = id;
};


int Venda::getQuantVendida()
{
    return quantidadeVendida;
};


void Venda::setQuantVendida(int quant)
{
    this->quantidadeVendida = quant;
};


void Venda::setcustoFinal(float custoFinal)
{
    this->custoFinal = custoFinal;
};


float Venda::getcustoFinal()
{
    return custoFinal;
};


int Venda::getIdentificadorItem()
{
    return identificadorItem;
};


void Venda::setIdentificadorItem(int identificadorItem)
{
  this->identificadorItem = identificadorItem;
};


string Venda::getNomeItem()
{
    return nomeItem;
};


void Venda::setNomeItem(string nome)
{
    this->nomeItem = nome;
};


float Venda::getcustoUnidade()
{
    return custoUnidade;
};


void Venda::setcustoUnidade(float custoUnidade)
{
    this->custoUnidade = custoUnidade;
};


//sobrecarga de operador para iserir log de vendas no txt.
ostream & operator <<(ostream & out,Venda &venda)
{
    out<<"ID venda              = "<<venda.getId()<<endl;
    out<<"ID item vendido       = "<<venda.getIdItem()<<endl;
    out<<"Nome do item vendido  = "<<venda.getNomeItem()<<endl;
    out<<"Quantidade vendida    = "<<venda.getQuantVendida()<<endl;
    out<<"Custo por item sem desconto = "<<venda.getcustoUnidade()<<" PO"<<endl;
    out<<"Custo final da venda  = "<<venda.getcustoFinal()<<" PO"<<endl;
    return out;
};
