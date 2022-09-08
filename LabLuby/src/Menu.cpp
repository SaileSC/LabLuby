#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>
#include <algorithm>

#include<fstream>

#include "Menu.h"

using namespace std;

Menu::Menu()
{
    EstoqueItens listaItens = itensInicio();

    do{
        system("clear||cls");
        cout<<"**Bem-Vindo ao mercado**"<<endl
            <<"1.Cadastrar um item"<<endl
            <<"2.Listar estoque"<<endl
            <<"3.Historico de vendas"<<endl
            <<"4.Fechar loja"<<endl;

        cout<<"Insira a opção desejada: ";
        cin >> opcao;

        switch(opcao)
        {
            case 1:
            {
                listaItens = cadastraItem(listaItens);
                break;
            };
            case 2:
            {
                listaItens = manipulaEstoque(listaItens);
                break;
            };
            case 3:
            {
                logVendas(listaItens.getVendas());
                break;
            };
            case 4:
            {
                cout<<"Ate a proxima...."<<endl;
                getchar();getchar();
                exit(EXIT_SUCCESS);
                break;

            };

            default:
            {

                cout<<"Opção invalida, tente novamente"<<endl;
                cout<<"Enter para continuar..."<<endl;
                getchar();getchar();
                break;
            };
        };
    }while(true);
};


EstoqueItens Menu::cadastraItem(EstoqueItens lista)
{
    int opc;
    do{
    system("cls||clear");
    cout << "Que tipo de item deseja cadastrar?\n"
         << "1.Armadura\n2.Arma\n3.Consumivel\n4.voltar\n"
         << "insira opcao: ";
    cin >> opc;
        switch(opc)
        {
            case 1:
            {
                string nome;
                float custo;
                float durabilidade;
                int quantidade;
                system("cls||clear");
                cin.sync();

                cout << "insira os dados do item:\n";
                cout << "Nome : ";
                getline(cin, nome);
                cin.sync();

                cout << "Durabilidade : ";
                cin  >> durabilidade;
                cin.sync();

                cout << "Quantidade : ";
                cin  >> quantidade;
                cin.sync();

                cout << "Custo : ";
                cin >> custo;
                cin.sync();

                Armadura armadura(nome, durabilidade, quantidade, custo);
                lista.setArmaduras(armadura);
                cout<<"Item cadastrado\nEnter para continuar..."<<endl;
                getchar();
                return lista;
                break;
            };
            case 2:
            {
                string nome;
                float custo;
                float dano;
                int quantidade;
                system("cls||clear");
                cin.sync();

                cout << "insira os dados do item:\n";
                cout << "Nome : ";
                getline(cin, nome);
                cin.sync();

                cout << "Dano : ";
                cin  >> dano;
                cin.sync();

                cout << "Quantidade : ";
                cin  >> quantidade;
                cin.sync();

                cout << "Custo : ";
                cin >> custo;
                cin.sync();


                Arma arma(nome, dano, quantidade, custo);
                lista.setArmas(arma);
                cout<<"Item cadastrado\nEnter para continuar..."<<endl;
                getchar();
                return lista;
                break;
            };
            case 3:
            {
                string nome;
                float custo;
                float uso;
                int quantidade;

                system("cls||clear");
                cin.sync();

                cout << "insira os dados do item:\n";
                cout << "Nome : ";
                getline(cin, nome);
                cin.sync();

                cout << "Uso : ";
                cin  >> uso;
                cin.sync();

                cout << "Quantidade : ";
                cin  >> quantidade;
                cin.sync();

                cout << "Custo : ";
                cin >> custo;
                cin.sync();


                Consumivel consumivel(nome, uso, quantidade, custo);
                lista.setConsumiveis(consumivel);
                cout<<"Item cadastrado\nEnter para continuar..."<<endl;
                getchar();
                return lista;
                break;
            }
            case 4:
            {
                return lista;
                break;
            }
            default:
            {
                cout<<"Opção invalida...\n"
                    <<"Enter para continuar..."<<endl;
                getchar();getchar();
            }
        };
    }while(true);

};


EstoqueItens Menu::manipulaEstoque(EstoqueItens lista)
{
    int opc;
    do
    {
    system("cls||clear");
    listaArmas(lista);
    listaArmaduras(lista);
    listaConsumiveis(lista);

    cout<< " \n\n                  ***MENU DO ESTOQUE***\n"
        << "   Selecione um item para Vender, Deletar ou alterar quantidade \n"
        << "   "<<"1. Selecionar Arma\n"
        << "   "<<"2. Selecionar Armadura\n"
        << "   "<<"3. Selecionar Consumivel\n"
        << "   "<<"4. Exportar estoque\n"
        << "   "<<"5. Importar estoque\n"
        << "   "<<"6. Voltar\n"
        << "   "<<"Insira a opção desejada : ";

        cin >> opc;
    switch(opc)
    {
        case 1:
        {
            system("cls||clear");
            listaArmas(lista);
            int id = selecionaId(lista.getArmas());

            if(id>=0)
            {
                lista.manipulaItens(lista.getArmas(), id);
            };
            break;
        };

        case 2:
        {
            system("cls||clear");
            listaArmaduras(lista);

            int id = selecionaId(lista.getArmaduras());

            if(id>=0)
            {
                lista.manipulaItens(lista.getArmaduras(), id);
            };
            break;
        };
        case 3:
        {
            system("cls||clear");
            listaConsumiveis(lista);
            int id = selecionaId(lista.getConsimiveis());
            if(id>=0)
            {
                lista.manipulaItens(lista.getConsimiveis(), id);
            };
            break;
        }
        case 4:
        {
            exportaEstoque(lista);
            break;
        };
        case 5:
        {
            lista = importaEstoque();
        }
        case 6:
        {
            return lista;
            break;
        };
        default:
        {
            cout << "  Opção invalida, tente novamente.......\n";
            cout<<"Enter para continuar..."<<endl;
            getchar();getchar();
            break;
        }
    };
    }while(opc != 4);
    return lista;
};


void Menu::listaArmaduras(EstoqueItens lista)
{
    list<Armadura> mostarArmaduras = lista.getArmaduras();
    cout <<"\n\n            LISTA DE ARMADURAS\n";

    cout<< "  ID  ||  "
        << "          NOME           ||  "
        << " DURABILIDADE  ||  "
        << " QUANTIDADE    ||  "
        << " CUSTO\n";

    if(!mostarArmaduras.empty())
    {
        for (list<Armadura>::iterator it = mostarArmaduras.begin(); it != mostarArmaduras.end(); ++it)
        {
            cout <<setw(5)<<it->getId()<<setw(25)
                 <<it->getNome()<<setw(16)
                 <<it->getDurabilidade()<<setw(15)
                 <<it->getQuantidade()<<setw(22)
                 <<it->getCusto()<< " PO"<<endl;
        };
    }else{
        cout << "Sem armaduras no estoque...."<<endl;
    }
};


void Menu::listaArmas(EstoqueItens lista)
{

    list<Arma> mostarArmas = lista.getArmas();
    cout <<"\n\n            LISTA DE ARMAS\n";

    cout<< "  ID  ||  "
        << "          NOME           ||  "
        << "   DANO    ||  "
        << " QUANTIDADE    ||  "
        << " CUSTO\n";

    if(!mostarArmas.empty())
    {
        for (list<Arma>::iterator it = mostarArmas.begin(); it != mostarArmas.end(); ++it)
        {
            cout <<setw(5)<<it->getId()<<setw(25)
                 <<it->getNome()<<setw(15)
                 <<it->getDano()<<setw(15)
                 <<it->getQuantidade()<<setw(20)
                 <<it->getCusto()<< " PO"<<endl;
        };
    }else{
        cout << "Sem armas no estoque...."<<endl;

    };
};


void Menu::listaConsumiveis(EstoqueItens lista)
{
    list<Consumivel> mostrarConsumiveis = lista.getConsimiveis();
    cout <<"\n\n            LISTA DE CONSUMIVEIS\n";

    cout<< "  ID  ||  "
        << "          NOME           ||  "
        << "   USO    ||  "
        << " QUANTIDADE    ||  "
        << " CUSTO\n";

    if(!mostrarConsumiveis.empty())
    {
        for (list<Consumivel>::iterator it = mostrarConsumiveis.begin(); it != mostrarConsumiveis.end(); ++it)
        {
            cout <<setw(5)<<it->getId()<<setw(25)
                 <<it->getNome()<<setw(15)
                 <<it->getUso()<<setw(15)
                 <<it->getQuantidade()<<setw(18)
                 <<it->getCusto()<< " PO"<<endl;
        };
    }else{
        cout << "Sem consumiveis no estoque...."<<endl;
    };
};


int Menu::selecionaId(list<Arma> lista)
{
    int auxiliar = -1;
    int id;
    do{
    cout << "Digite o ID da arma (ID < 0 para sair): ";
    cin >> id;
        for(list<Arma> ::iterator it = lista.begin(); it != lista.end(); it++)
        {
            if(it->getId() == id)
            {
                auxiliar = id;
                break;
            };
        };
            if(id < 0)
            {
                break;
            }
            else if(auxiliar != id)
            {
                cout << "\nID invalido\nTente novamente, ID < 0 para sair.....\n";
            };
        }while(auxiliar<0);

   return auxiliar;
};


int Menu::selecionaId(list<Armadura> lista)
{
    int auxiliar = -1;
    int id;
    do{
    cout << "Digite o ID da arma (ID < 0 para sair): ";
    cin >> id;
        for(list<Armadura> ::iterator it = lista.begin(); it != lista.end(); it++)
        {
            if(it->getId() == id)
            {
                auxiliar = id;
                break;
            };
        };
            if(id < 0)
            {
                break;
            }
            else if(auxiliar != id)
            {
                cout << "\nID invalido\nTente novamente, ID < 0 para sair.....\n";
            };
        }while(auxiliar<0);

   return auxiliar;
};


int Menu::selecionaId(list<Consumivel> lista)
{
    int auxiliar = -1;
    int id;
    do{
    cout << "Digite o ID da arma (ID < 0 para sair): ";
    cin >> id;
        for(list<Consumivel> ::iterator it = lista.begin(); it != lista.end(); it++)
        {
            if(it->getId() == id)
            {
                auxiliar = id;
                break;
            };
        };
            if(id < 0)
            {
                break;
            }
            else if(auxiliar != id)
            {
                cout << "\nID invalido\nTente novamente, ID < 0 para sair.....\n";
            };
        }while(auxiliar<0);

   return auxiliar;
};


void Menu::logVendas(list<Venda> listaVendas)
{
    system("cls||clear");
    if(!listaVendas.empty())
    {
        list<Venda>::iterator it;
        int opc = 0;

        cout<<"        HISTORICO DE VENDAS \n\n"<<endl;
        for(it = listaVendas.begin(); it != listaVendas.end(); it ++)
        {
            cout<<"      DADOS DA VENDA \n"
                <<"- Id da venda                   = " << it->getId()<<endl
                <<"- Id Item vendido               = " << it->getIdItem()<<endl
                <<"- Nome do Item                  = " << it->getNomeItem()<<endl
                <<"- Quantidade de itens vendidos  = " << it->getQuantVendida()<<endl
                <<"- Custo por Item sem desconto   = " << it->getcustoUnidade()<<" PO"<<endl
                <<"- Custo final                   = " << it->getcustoFinal()<<" PO"<<endl
                <<endl;
        };
        cout<<"Deseja exportar esse historico?\n"
            <<" 1.Sim\n"
            <<" 2.Não, sair.\n";
        do{
        cout<<"\n Digite a opção : ";
        cin >> opc;

            if(opc != 1 && opc != 2)
            {
              cout<<"Opção invalida....";
            };

        }while(opc != 1 && opc != 2);


        if(opc == 1){
            exportaLogVendas(listaVendas);
        };
    }else{
        cout<<"LOG DE VENDAS ESTA VAZIO...\n";

    };
        cout<<"Enter para continuar..."<<endl;
        getchar();getchar();
};


void Menu::exportaLogVendas(list<Venda> listaVendas)
{
    ofstream ofs("LogVendas.txt");
    ofs << " ***** LOG DE VENDAS ***** "<<endl;
    for(list<Venda>::iterator it =listaVendas.begin(); it != listaVendas.end(); it++)
    {
        ofs << (*it);
        ofs << endl;
    };
    ofs.close();
};


void Menu::exportaEstoque(EstoqueItens lista)
{
    ofstream ofs("Estoque.txt");
    list<Arma> listaArmas = lista.getArmas();
    list<Arma>::iterator pArma;

    list<Armadura> listaArmaduras = lista.getArmaduras();
    list<Armadura>::iterator pArmadura;

    list<Consumivel> listaConsumiveis = lista.getConsimiveis();
    list<Consumivel>::iterator pConsumivel;

    ofs<< " ***** ITENS DO ESTOQUE ***** \n"<<endl;

    ofs<<"LISTA DE ARMAS"<<endl;
    for(pArma = listaArmas.begin(); pArma != listaArmas.end(); pArma++)
    {
        ofs<<"-ARMA"<<endl;
        ofs << (*pArma);

    };


    ofs<<"LISTA DE ARMADURA"<<endl;
    for(pArmadura =listaArmaduras.begin(); pArmadura != listaArmaduras.end(); pArmadura++)
    {
        ofs<<"-ARMADURA"<<endl;
        ofs << (*pArmadura);

    };

    ofs<<"LISTA DE CONSUMIVEIS"<<endl;
    for(pConsumivel =listaConsumiveis.begin(); pConsumivel != listaConsumiveis.end(); pConsumivel++)
    {
        ofs<<"-CONSUMIVEL"<<endl;
        ofs << (*pConsumivel);
    };

    ofs.close();


    cout<<"Arquivo Estoque.txt foi criado com o registro do Estoque\n"
        <<"Enter para continuar...\n";
        getchar();getchar();


};


EstoqueItens Menu::importaEstoque()
{
    EstoqueItens estoque;

    list<Arma> listaArma;
    list<Armadura> listaArmadura;
    list<Consumivel> listaConsumiveis;

    Consumivel consumivel;
    Arma arma;
    Armadura armadura;

    ifstream arquivoEstoque("Estoque.txt");
    string linha;
    string nome;

    if(arquivoEstoque.is_open())
    {
        while(getline(arquivoEstoque, linha))
        {
            if(linha == "-ARMA")
            {
               arquivoEstoque >> arma;
               arma.setNome(removeBarra(arma.getNome()));
               listaArma.insert(listaArma.end(), arma);
            }

            if(linha == "-ARMADURA")
            {
               arquivoEstoque >> armadura;
               armadura.setNome(removeBarra(armadura.getNome()));
               listaArmadura.insert(listaArmadura.end(), armadura);
            };

            if(linha == "-CONSUMIVEL")
            {
                arquivoEstoque >> consumivel;
                consumivel.setNome(removeBarra(consumivel.getNome()));
                listaConsumiveis.insert(listaConsumiveis.end(), consumivel);
            };

        };

        arquivoEstoque.close();

        cout<<"Estoque carregado com sucesso\n"
            <<"Pressione Enter para continuar...\n";
            getchar();getchar();
    }else{
        cout<<"Arquivo Estoque.txt não encontrado\n"
            <<"Pressione Enter para continuar...\n";
            getchar();getchar();
    };


    estoque.setArmas(listaArma);
    estoque.setArmaduras(listaArmadura);
    estoque.setConsumiveis(listaConsumiveis);

    return estoque;
};


EstoqueItens Menu::itensInicio()
{
    EstoqueItens lista ;


    Arma arma("Adaga", 1370, 10, 317.4F);
    Armadura armadura("Armadura de espinhos", 100.0F, 3, 570.34F);
    Consumivel consumivel("Poção de HP", 3, 30, 50.4F);

    lista.setArmaduras(armadura);
    lista.setArmas(arma);
    lista.setConsumiveis(consumivel);

    return lista;
};

string Menu::removeBarra(string nome)
{
    replace(nome.begin(), nome.end(), '_', ' ');
    return nome;
};


Menu::~Menu()
{

};



