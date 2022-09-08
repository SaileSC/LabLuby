#ifndef MENU_H
#define MENU_H

#include <string>

#include "EstoqueItens.h"

using namespace std;

class Menu
{
    private:
        int opcao;

        //função da acesso as metodos de adição a lista.
        EstoqueItens cadastraItem(EstoqueItens lista);
        EstoqueItens manipulaEstoque(EstoqueItens lista);

        //metodos para gerar uma tabela com os itens.
        void listaArmaduras(EstoqueItens lista);
        void listaArmas(EstoqueItens lista);
        void listaConsumiveis(EstoqueItens lista);

        //metodo para inserir e remover itens de suas listas.
        EstoqueItens manipulaArmas(EstoqueItens lista, int id);
        EstoqueItens manipulaArmaduras(EstoqueItens lista, int id);
        EstoqueItens manipulaConsumiveis(EstoqueItens lista, int id);

        //metodo para selecionar um item pelo identificador.
        int selecionaId(list<Arma> lista);
        int selecionaId(list<Armadura> lista);
        int selecionaId(list<Consumivel> lista);

        //metodo spara mostrar e exportas o log de vendas.
        void logVendas(list<Venda> listaVendas);
        void exportaLogVendas(list<Venda> listaVendas);

        //metodos para importar de um arquivo(Estoque.txt) ou exportar para um arquivo(Estoque.txt) o estoque.
        EstoqueItens importaEstoque();
        void exportaEstoque(EstoqueItens listaEstoque);

        //metodo para sanar RNF05, realiza a inserção de um objeto de cada tipo, ao iniciar programa.
        EstoqueItens itensInicio();

        string removeBarra(string nome);

    public:
        Menu();
        ~Menu();
};

#endif // MENU_H
