#include "EstoqueItens.h"

void EstoqueItens::manipulaItens(list<Arma> listaArmas, int id)
{
    list<Arma>::iterator it;
    while(true){
        for(it = listaArmas.begin(); it != listaArmas.end(); it++)
        {
            if(it->getId() == id)
            {
            system("cls||clear");

            cout<< "\n          ARMA SELECIONADA"
                << "\n  ID         = " <<it->getId()
                << "\n  NOME       = " <<it->getNome()
                << "\n  DANO       = " << it->getDano()
                << "\n  QUANTIDADE = " << it->getQuantidade()
                << "\n  CUSTO      = " << it->getCusto() << " PO"<<endl;
                break;
            };
        };
        switch(menuItem())
        {
        case 1:
            {
                it->setQuantidade(alterarQuantidade());;
                break;
            };
        case 2:
            {
                *it = vendeItem(*it);
                break;
            };
        case 3:
            {
                listaArmas.erase(it);
                cout<< "\nItem apagado do estoque....\n";
                cout<<"Enter para continuar..."<<endl;
                getchar();getchar();
                break;
            };
        case 4:
            {
                return;
                break;
            };
        default:
            {
            cout << "Opção invalida, tente novamente......";
            cout<<"Enter para continuar..."<<endl;
            getchar();getchar();
            break;
            };
        };
    };
    this->listaArmas = listaArmas;
};


void EstoqueItens::manipulaItens(list<Armadura> listaArmaduras, int id)
{
    list<Armadura>::iterator it;
    while(true){
        for(it = listaArmaduras.begin(); it != listaArmaduras.end(); it++)
        {
            if(it->getId() == id)
            {
            system("cls||clear");

            cout<< "\n          ARMADURA SELECIONADA"
                << "\n  ID          = " <<it->getId()
                << "\n  NOME        = " <<it->getNome()
                << "\n  DURABILIDAE = " << it->getDurabilidade()
                << "\n  QUANTIDADE  = " << it->getQuantidade()
                << "\n  CUSTO       = " << it->getCusto() << " PO"<<endl;
                break;
            };
        };
        switch(menuItem())
        {
        case 1:
            {
                it->setQuantidade(alterarQuantidade());
                break;
            }
        case 2:
            {
                *it = vendeItem(*it);
                break;
            };
        case 3:
            {
                listaArmaduras.erase(it);
                cout<< "\nItem apagado do estoque....\n";
                cout<<"Enter para continuar..."<<endl;
                getchar();getchar();
                break;
            }
        case 4:
            {
                return;
                break;
            }
        default:
            {
            cout << "Opção invalida, tente novamente......";
            getchar();getchar();
            break;
            };
        };
    };
    this->listaArmaduras = listaArmaduras;
};


void EstoqueItens::manipulaItens(list<Consumivel> listaConsumiveis, int id)
{
    list<Consumivel>::iterator it;
    while(true){
        for(it = listaConsumiveis.begin(); it != listaConsumiveis.end(); it++)
        {
            if(it->getId() == id)
            {
            system("cls||clear");

            cout<< "\n          CONSUMIVEL SELECIONADO"
                << "\n  ID          = " <<it->getId()
                << "\n  NOME        = " <<it->getNome()
                << "\n  USO         = " << it->getUso()
                << "\n  QUANTIDADE  = " << it->getQuantidade()
                << "\n  CUSTO       = " << it->getCusto() << " PO"<<endl;
                break;
            };
        };

        switch(menuItem())
        {
            case 1:
                {
                    it->setQuantidade(alterarQuantidade());
                    break;
                };
            case 2:
                {
                    *it = vendeItem(*it);
                    break;
                };
            case 3:
                {
                    listaConsumiveis.erase(it);
                    cout<< "\nItem apagado do estoque....\n";
                    cout<<"Enter para continuar..."<<endl;
                    getchar();getchar();
                    break;
                };
            case 4:
                {
                    return;
                    break;
                };
            default:
                {
                cout << "Opção invalida, tente novamente......";
                getchar();getchar();

                };
            };
    };

    this->listaConsumiveis = listaConsumiveis;
};


int EstoqueItens::alterarQuantidade(){
    int quantidade;
    cout<<"Digite o nova quantidade : ";
    cin >> quantidade;
    cout<< "\nQuantidade atualizada....\n";
    cout<<"Enter para continuar..."<<endl;
    getchar();getchar();
    return quantidade;
};


int EstoqueItens::menuItem()
{
    int opc;
    cout << "\n             Menu Item \n"
    << "   1. Alterar quantidade do item\n"
    << "   2. Vender Item\n"
    << "   3. Deletar item\n"
    << "   4. Voltar\n"
    << "    Insira a opção : ";
    cin >> opc;

    return opc;
};


Arma EstoqueItens::vendeItem(Arma item)
{
    int quantidade;
    float custoFinal;
    float custoSemDesc;
    cout<<"Venda de item\n"
        <<"Quantas unidades do item deseja vender?\n"<<endl;

    do{
        cout<<"Digite a quantidade: ";
        cin>> quantidade;
        if(quantidade < 0  || quantidade > item.getQuantidade())
        {
            cout<<"\nQuantidade invalida, tente novamente...\n";
        };
    }while(quantidade < 0  || quantidade > item.getQuantidade());

    custoSemDesc = (item.getCusto() * quantidade);
    custoFinal = (item.getCusto() * quantidade) * ((float) 1.00  - (quantPrimos(quantidade) /(float) 100));

    Venda venda(quantidade,custoFinal,item.getId(),item.getNome(),item.getCusto());

    if(confirmaVenda(item.getCusto(), custoSemDesc, quantPrimos(quantidade), custoFinal)== true)
    {
      item.setQuantidade(item.getQuantidade() - quantidade);
      setVendas(venda);
      cout<<" Venda concluida...\n";
    }else{
      cout<<" Venda cancelada...\n";
    };

    cout<<"Enter para continuar..."<<endl;
    getchar();getchar();
    return item;
};


Armadura EstoqueItens::vendeItem(Armadura item)
{
    int quantidade;
    float custoFinal;
    float custoSemDesc;
    cout<<"Venda de item\n"
        <<"Quantas unidades do item deseja vender?\n";

    do{
        cout<<"Digite a quantidade: "<<endl;
        cin>> quantidade;
        if(quantidade < 0  || quantidade > item.getQuantidade())
        {
            cout<<"\nQuantidade invalida, tente novamente...\n";
        };
    }while(quantidade < 0  || quantidade > item.getQuantidade());

    custoSemDesc = (item.getCusto() * quantidade);
    custoFinal = (item.getCusto() * quantidade) * ((float) 1.00  - (quantPrimos(quantidade) /(float) 100));

    Venda venda(quantidade,custoFinal,item.getId(),item.getNome(),item.getCusto());

    if(confirmaVenda(item.getCusto(), custoSemDesc, quantPrimos(quantidade), custoFinal)== true)
    {
      item.setQuantidade(item.getQuantidade() - quantidade);
      setVendas(venda);
      cout<<" Venda concluida...\n";
    }else{
      cout<<" Venda cancelada...\n";
    };
        cout<<"Enter para continuar..."<<endl;
        getchar();getchar();

    return item;
};


Consumivel EstoqueItens::vendeItem(Consumivel item)
{
    int quantidade;
    float custoFinal;
    float custoSemDesc;
    cout<<"Venda de item\n"
        <<"Quantas unidades do item deseja vender?\n";

    do{
        cout<<"Digite a quantidade: ";
        cin>> quantidade;
        if(quantidade < 0  || quantidade > item.getQuantidade())
        {
            cout<<"\nQuantidade invalida, tente novamente...\n";
        };
    }while(quantidade < 0  || quantidade > item.getQuantidade());

    custoSemDesc = (item.getCusto() * quantidade);
    custoFinal = (item.getCusto() * quantidade) * ((float) 1.00  - (quantPrimos(quantidade) /(float) 100));

    Venda venda(quantidade, custoFinal,item.getId(),item.getNome(),item.getCusto());

    if(confirmaVenda(item.getCusto(), custoSemDesc, quantPrimos(quantidade), custoFinal) == true)
    {
      item.setQuantidade(item.getQuantidade() - quantidade);
      setVendas(venda);
      cout<<" Venda concluida...\n";
    }else{
      cout<<" Venda cancelada...\n";
    };
        cout<<"Enter para continuar..."<<endl;
        getchar();getchar();

    return item;
};


bool EstoqueItens::confirmaVenda(float custoUnidade, float valorSemDesc,int taxaDesc, float ValorFinal)
{
    int opc = 0;
    float valorDesconto = (float) valorSemDesc - ValorFinal;
    system("cls||clear");
    cout<<"       CONFIRMAÇÃO DA COMPRA   \n"
        <<" Custo por unidade    = "<<custoUnidade<<" PO"
        <<"\n Valor sem desconto   = "<<valorSemDesc<<" PO"
        <<"\n Valor do desconto    = "<<valorDesconto<<" PO"
        <<"\n Desconto             = "<<taxaDesc<<"%"
        <<"\n Valor final da venda = "<<ValorFinal<<" PO"<<endl
        <<"\n 1.Confirma"
        <<"\n 2.Cancelar"
        <<"\n Digite a opção : ";
    do{
        cin>>opc;

        if(opc>2 || opc<1)
        {
            cout<<"\nOpção invalida...\n";
        };
    }while(opc>2 || opc<1);

    if(opc == 1)
    {
        return true;
    };
    return false;
};


int EstoqueItens::quantPrimos(int valor)
{
    int quantidade = 0;
    for(int x = 1; x<= valor; x++ )
    {
        if(ehPrimo(x) == true)
        {
            quantidade++;
        };
    };
    return quantidade;
};


bool EstoqueItens::ehPrimo(int valor)
{
  int quantDivisores = 0;
    for(int x = 1; x <= valor; x++)
    {
        if((valor % x) == 0)
        {
            quantDivisores++;
        };
    };

    if(quantDivisores == 2)
    {
        return true;
    }else{
        return false;
    };
};


EstoqueItens::EstoqueItens()
{

};


EstoqueItens::~EstoqueItens()
{

};


void  EstoqueItens::setArmas(Arma arma)
{
  arma.setId(listaArmas.size() + listaArmaduras.size() + listaConsumiveis.size());
  listaArmas.insert(listaArmas.end(), arma);
};


void  EstoqueItens::setArmas(list<Arma> arma)
{
    this->listaArmas = arma;
};


list<Arma>  EstoqueItens::getArmas(){
    return listaArmas;
};


void  EstoqueItens::setArmaduras(Armadura armadura)
{
  armadura.setId(listaArmas.size() + listaArmaduras.size() + listaConsumiveis.size());
  listaArmaduras.insert(listaArmaduras.end(), armadura);
};


void  EstoqueItens::setArmaduras(list<Armadura> armadura)
{
    this->listaArmaduras = armadura;
};


list<Armadura>  EstoqueItens::getArmaduras(){
    return listaArmaduras;
};


void  EstoqueItens::setConsumiveis(Consumivel consumivel)
{
  consumivel.setId(listaArmas.size() + listaArmaduras.size() + listaConsumiveis.size());
  listaConsumiveis.insert(listaConsumiveis.end(), consumivel);
};


void  EstoqueItens::setConsumiveis(list<Consumivel> consumivel)
{
    this->listaConsumiveis = consumivel;
};


list<Consumivel>  EstoqueItens::getConsimiveis(){
    return listaConsumiveis;
};


void EstoqueItens::setVendas(Venda venda)
{
    venda.setId(listaVendas.size());
    this->listaVendas.insert(listaVendas.end(), venda);
};


void EstoqueItens::setVendas(list<Venda> venda)
{
    this->listaVendas = listaVendas;
};


list<Venda> EstoqueItens::getVendas()
{
   return listaVendas;
};
