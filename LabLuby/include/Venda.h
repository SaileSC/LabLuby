#ifndef VENDA_H
#define VENDA_H

#include<iostream>
#include<string>

using namespace std;

class Venda
{
private:
    //dados da venda.
    int identificador;
    int quantidadeVendida;
    float custoFinal;

    //dados do item vendido.
    int identificadorItem;
    string nomeItem;
    float custoUnidade;

    //sobrecarga metodos de saida para inserir venda em um arquivo txt.
    friend ostream & operator <<(ostream &out,Venda &venda);

public:
    Venda();
    ~Venda();
    Venda(int quant, float custoTotal, int idItem, string nomeItem, float custoUnidade);

    //getters and setters.
    int getId();
    void setId(int id);
    int getIdItem();
    void setIdItem(int id);
    int getQuantVendida();
    void setQuantVendida(int quant);
    float getcustoFinal();
    void setcustoFinal(float custoFinal);
    int getIdentificadorItem();
    void setIdentificadorItem(int identificadorItem);
    string getNomeItem();
    void setNomeItem(string nome);
    float getcustoUnidade();
    void setcustoUnidade(float custoUnidade);



};

#endif // VENDA_H
