#ifndef ITENS_H
#define ITENS_H

#include<string>
using namespace std;

class Itens
{
protected:
    //atributos da classe item.
    int identificador;
    string nome;
    string tipo;
    float custo;
    int quantidade;
public:

    Itens();
    ~Itens();
    Itens(int id, string nome, string tipo, float custo);

    //getters e setters.
    void setId(int nome);
    int getId();
    void setNome(string nome);
    int getQuantidade();
    void setQuantidade(int quantidade);
    string getNome();
    void setTipo(string tipo);
    string getTipo();
    void setCusto(float custo);
    float getCusto();
};

#endif // ITENS_H
