#ifndef ESTOQUEITENS_H
#define ESTOQUEITENS_H
#include<list>
#include<iostream>

#include "Arma.h"
#include "Armadura.h"
#include "Consumivel.h"
#include "Venda.h"

class EstoqueItens
{
    private:
    //listas de armas, armaduras, consumiveis e os registros de vendas.
    list<Arma> listaArmas;
    list<Armadura> listaArmaduras;
    list<Consumivel> listaConsumiveis;
    list<Venda> listaVendas;


    public:
        EstoqueItens();
        ~EstoqueItens();

        //menu que chama as alterações(Venda, Deletar, Altera quantidade) de itens no estoque.
        int menuItem();

        //funçoes que chamam alterações (Altera, Deletar, Vender).
        int alterarQuantidade();
        void manipulaItens(list<Arma> listaArmas, int id);
        void manipulaItens(list<Armadura> listaArmaduras, int id);
        void manipulaItens(list<Consumivel> listaConsumiveis, int id);
        Arma vendeItem(Arma armaVendida);
        Armadura vendeItem(Armadura armaVendida);
        Consumivel vendeItem(Consumivel armaVendida);

        // menu de confirmação da venda.
        bool confirmaVenda(float custoUnidade, float valorSemDesc,int taxaDesc, float ValorFinal);

        //metodos para determinar quantos primos há em um intervalo.
        int quantPrimos(int valor);
        bool ehPrimo(int valor);


        //getters e setters.
        void setArmas(Arma arma);
        void setArmas(list<Arma> arma);
        list<Arma> getArmas();

        void setVendas(Venda venda);
        void setVendas(list<Venda> venda);
        list<Venda> getVendas();

        void setArmaduras(Armadura armadura);
        void setArmaduras(list<Armadura> armadura);
        list<Armadura> getArmaduras();

        void setConsumiveis(Consumivel Consumivel);
        void setConsumiveis(list<Consumivel> Consumivel);
        list<Consumivel> getConsimiveis();
        void alterarArma(int id);

};
#endif // ESTOQUEITENS_H
