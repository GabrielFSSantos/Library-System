#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Estruturas Auxiliares:
typedef struct data
{
    int dia;
    int mes;
    int ano;

}TData;

typedef struct endereco
{
    char logradouro[100];
    int numero;
    char complemento[100];
    char bairro[100];
    char CEP[100];
    char cidade[100];
    char estado[100];

}TEndereco;

typedef struct isbn
{
    char ISBN[100];

}TISBN;



//Tipos de Registro:
typedef struct livro
{
    TISBN ID;
    char titulo[100];
    char editora[100];
    char local_pub[100];
    TData data_pub;
    char autor1[100];
    char autor2[100];
    int numb_ed;
    int quant;
    int quant_emp;

}TLivro;

typedef struct usuario
{
    char nome[100];
    char sobrenome[100];
    char CPF[100];
    char RG[100];
    TEndereco endereco;
    TData data_nasc;
    int tipo;
    char departamento[100];     //Nome do curso se for aluno ou departamento no caso de professor/funcionario
    int livros;
    float multa;

}TUsuario;

typedef struct emprestimo
{
    char CPF[100];
    TISBN ID;           // vetor de ISBNs de livros de empréstimo
    TData data_emp;     // data da realização do empréstimo
    TData data_ent;     // data em que o usuário deve entregar o livro
    TData data_dev;     // data do dia em que o usuário realizou a entrega
    float multa;        // valor total da multa
    int PG;             // registra 0 se o usuário não pagou a multa e 1 caso tenha pago

}TEmprestimo;



//Modulos:
typedef struct modulo1
{
    TLivro vetor[100];
    int indice;

}TModulo1;

typedef struct modulo2
{
    TUsuario vetor[100];
    int indice;

}TModulo2;

typedef struct modulo3
{
    TEmprestimo vetor[100];
    int indice;

}TModulo3;

//Escopos das Funçoes

//Funções de Inicialização:
void IniciarModulo1(TModulo1 *modulo);
void IniciarModulo2(TModulo2 *modulo);
void IniciarModulo3(TModulo3 *modulo);

//Funções de Leitura:
void LerLivro(TLivro *book);
void LerUsuario(TUsuario *user);
void LerEmprestimo(TEmprestimo *borrow);

//Funções de Impressão:
void ImprLivro(TLivro book);
void ImprUsuario(TUsuario user);
void ImprEmprestimo(TEmprestimo borrow);

//Imprimir Tudo Ja Registrado
void ImprimirTodosLivros(TModulo1 *modulo1);
void ImprimirTodosUsuarios(TModulo2 *modulo2);
void ImprimirTodosEmprestimos(TModulo3 *modulo3);

//Funções de Pesquisa:
int PesquisarLivro(TModulo1 modulo, TLivro book);
int PesquisarUsuario(TModulo2 modulo, TUsuario user);
int PesquisarEmprestimo(TModulo3 modulo, TEmprestimo borrow);

//Funções de Inserir:
void InserirLivro(TModulo1 *modulo, TLivro book);
void InserirUsuario(TModulo2 *modulo, TUsuario user);
void InserirEmprestimo(TModulo3 *modulo, TEmprestimo borrow);

//Funções de Alterar
void AlterarLivro(TModulo1 *modulo, TLivro book);
void AlterarUsuario(TModulo2 *modulo, TUsuario user);
void AlterarEmprestimo(TModulo3 *modulo, TEmprestimo borrow);

//Funções de Excluir
void ExcluirLivro(TModulo1 *modulo, TLivro book);
void ExcluirUsuario(TModulo2 *modulo, TUsuario user);
void ExcluirEprestimo(TModulo3 *modulo, TEmprestimo borrow);

//Funções Adicionais para o Emprestimo
void MSG_SUBMENU_EMP(int numero_modulo);
int Quant_DMes(int mes, int ano);
TData CalcularDataEntrega(TData data_emprestimo);
void DarBaixaEmp(TModulo3 *modulo, TEmprestimo borrow);
void EfetuarPagamento(TModulo3 *modulo, TEmprestimo borrow);

//Funções dos Menus
void MSG_MENU(void);
void MSG_SUBMENU(int numero_modulo);
void SubMenuModulo1(TModulo1 *modulo, TLivro book);
void SubMenuModulo2(TModulo2 *modulo, TUsuario user);
void SubMenuModulo3(TModulo3 *modulo3, TEmprestimo borrow, TModulo2 *modulo2, TUsuario user, TModulo1 *modulo1, TLivro book);



//Funções de Inicialização:
void IniciarModulo1(TModulo1 *modulo)
{
    modulo->indice=0;

}

void IniciarModulo2(TModulo2 *modulo)
{
    modulo->indice=0;

}

void IniciarModulo3(TModulo3 *modulo)
{
    modulo->indice=0;

}



//Funções de Leitura:
void LerLivro(TLivro *book)
{
    printf("\n\nDigite as Informacoes do Livro\n\n");

    printf("ISBN: ");
    fflush(stdin);
    fgets(book->ID.ISBN,100,stdin);

    printf("Titulo: ");
    fflush(stdin);
    fgets(book->titulo,100,stdin);

    printf("Editora: ");
    fflush(stdin);
    fgets(book->editora,100,stdin);

    printf("Local de Publicacao: ");
    fflush(stdin);
    fgets(book->local_pub,100,stdin);



    printf("\nData de Publicacoo:\n");

    printf("Dia: ");
    fflush(stdin);
    scanf("%d",&book->data_pub.dia);

    printf("Mes: ");
    fflush(stdin);
    scanf("%d",&book->data_pub.mes);

    printf("Ano: ");
    fflush(stdin);
    scanf("%d",&book->data_pub.ano);



    printf("\nPrimeiro Autor: ");
    fflush(stdin);
    fgets(book->autor1,100,stdin);

    printf("Segundo Autor: ");
    fflush(stdin);
    fgets(book->autor2,100,stdin);

    printf("Numero da Edicao: ");
    fflush(stdin);
    scanf("%d",&book->numb_ed);

    printf("Quantidade de Livros: ");
    fflush(stdin);
    scanf("%d",&book->quant);

    book->quant_emp = 0;

}

void LerUsuario(TUsuario *user)
{
    printf("\n\nDigite as Informacoes do Usuario\n\n");

    printf("Nome: ");
    fflush(stdin);
    fgets(user->nome,100,stdin);

    printf("Sobrenome: ");
    fflush(stdin);
    fgets(user->sobrenome,100,stdin);

    printf("CPF: ");
    fflush(stdin);
    fgets(user->CPF,100,stdin);

    printf("Identidade: ");
    fflush(stdin);
    fgets(user->RG,100,stdin);



    printf("\nEndereco do Usuario\n");

    printf("Logradouro: ");
    fflush(stdin);
    fgets(user->endereco.logradouro,100,stdin);

    printf("Numero: ");
    fflush(stdin);
    scanf("%d",&user->endereco.numero);

    printf("Complemento: ");
    fflush(stdin);
    fgets(user->endereco.complemento,100,stdin);

    printf("Bairro: ");
    fflush(stdin);
    fgets(user->endereco.bairro,100,stdin);

    printf("Cidade: ");
    fflush(stdin);
    fgets(user->endereco.cidade,100,stdin);

    printf("CEP: ");
    fflush(stdin);
    fgets(user->endereco.CEP,100,stdin);


    printf("\nData de Nascimento\n");

    printf("Dia: ");
    fflush(stdin);
    scanf("%d",&user->data_nasc.dia);

    printf("Mes: ");
    fflush(stdin);
    scanf("%d",&user->data_nasc.mes);

    printf("Ano: ");
    fflush(stdin);
    scanf("%d",&user->data_nasc.ano);



    printf("\nTipo de Usuario (Para Professor use ""1"" e Aluno  use ""2""): ");
    fflush(stdin);
    scanf("%d",&user->tipo);

    printf("Departamento/Curso: ");
    fflush(stdin);
    fgets(user->departamento,100,stdin);

    user->livros = 0;
    user->multa = 0.0;

}

void LerEmprestimo(TEmprestimo *borrow)
{

    printf("\n\nData de Emprestimo:\n");

    printf("Dia: ");
    fflush(stdin);
    scanf("%d",&borrow->data_emp.dia);

    printf("Mes: ");
    fflush(stdin);
    scanf("%d",&borrow->data_emp.mes);

    printf("Ano: ");
    fflush(stdin);
    scanf("%d",&borrow->data_emp.ano);

    borrow->multa = 0;
    borrow->PG = 0;

}



//Funções de Impressão:
void ImprLivro(TLivro book)
{
    printf("\n------------------------------------------------");
    printf("\n\nInformacoes do Livro\n\n");

    printf("ISBN: ");
    puts(book.ID.ISBN);

    printf("Titulo: ");
    puts(book.titulo);

    printf("Editora: ");
    puts(book.editora);

    printf("Local de Publicacao: ");
    puts(book.local_pub);


    printf("Data de Publicacao:\n");

    printf("Dia: ");
    printf("%d\n",book.data_pub.dia);

    printf("Mes: ");
    printf("%d\n",book.data_pub.mes);

    printf("Ano: ");
    printf("%d\n",book.data_pub.ano);



    printf("\nPrimeiro Autor: ");
    puts(book.autor1);

    printf("Segundo Autor: ");
    puts(book.autor2);

    printf("Numero da Edicao: ");
    printf("%d\n\n",book.numb_ed);

    printf("Quantidade de Livros: ");
    printf("%d\n\n",book.quant);

    printf("Livros Emprestados: ");
    printf("%d",book.quant_emp);
}

void ImprUsuario(TUsuario user)
{
    printf("\n------------------------------------------------");
    printf("\n\nInformacoes do Usuario\n\n");

    printf("Nome: ");
    puts(user.nome);

    printf("CPF: ");
    puts(user.CPF);

    printf("Identidade: ");
    puts(user.RG);


    printf("\nEndereço do Usuario\n\n");

    printf("Logradouro: ");
    puts(user.endereco.logradouro);

    printf("Numero: ");
    printf("%d\n\n",user.endereco.numero);

    printf("Complemento: ");
    puts(user.endereco.complemento);

    printf("Bairro: ");
    puts(user.endereco.bairro);

    printf("Cidade: ");
    puts(user.endereco.cidade);

    printf("CEP: ");
    puts(user.endereco.CEP);


    printf("\nData de Nascimento\n\n");

    printf("Dia: ");
    printf("%d\n",user.data_nasc.dia);

    printf("Mes: ");
    printf("%d\n",user.data_nasc.mes);

    printf("Ano: ");
    printf("%d\n\n",user.data_nasc.ano);


    printf("\nTipo de Usuario: ");
    printf("%d\n\n",user.tipo);

    printf("Quantidade de Livros: ");
    printf("%d\n\n",user.livros);

    printf("Departamento/Curso: ");
    puts(user.departamento);


}

void ImprEmprestimo(TEmprestimo borrow)
{
    printf("\n------------------------------------------------");
    printf("\n\nInformacoes do Emprestimo\n\n");

    printf("CPF do Usuario: ");
    puts(borrow.CPF);

    printf("ISBN: ");
    puts(borrow.ID.ISBN);


    printf("Data de Emprestimo:\n");

    printf("Dia: ");
    printf("%d\n",borrow.data_emp.dia);

    printf("Mes: ");
    printf("%d\n",borrow.data_emp.mes);

    printf("Ano: ");
    printf("%d\n",borrow.data_emp.ano);


    printf("\nData de Entrega:\n");

    printf("Dia: ");
    printf("%d\n",borrow.data_ent.dia);

    printf("Mes: ");
    printf("%d\n",borrow.data_ent.mes);

    printf("Ano: ");
    printf("%d\n",borrow.data_ent.ano);


    printf("\nEstado do Emprestimo: ");
    printf("%d\n\n",borrow.PG);


}



//Imprimir Tudo Ja Registrado
void ImprimirTodosLivros(TModulo1 *modulo1)
{
    int i;

    system("cls");
    printf("\n>>>>>>>>>>>>>> TODOS OS REGISTROS DE LIVRO: <<<<<<<<<<<<<<<\n");
    printf("______________________________________________________________\n");

    for(i=0;i<modulo1->indice;i++)
    {
        ImprLivro(modulo1->vetor[i]);
    }

}

void ImprimirTodosUsuarios(TModulo2 *modulo2)
{
    int i;

    system("cls");
    printf("\n>>>>>>>>>>>>>> TODOS OS REGISTROS DE USUARIO: <<<<<<<<<<<<<<<\n");
    printf("________________________________________________________________\n");

    for(i=0;i<modulo2->indice;i++)
    {
        ImprUsuario(modulo2->vetor[i]);
    }

}

void ImprimirTodosEmprestimos(TModulo3 *modulo3)
{
    int i;

    system("cls");
    printf("\n>>>>>>>>>>>>>> TODOS OS REGISTROS DE EMPRESTIMO: <<<<<<<<<<<<<<<\n");
    printf("___________________________________________________________________\n");

    for(i=0;i<modulo3->indice;i++)
    {
        ImprEmprestimo(modulo3->vetor[i]);
    }

}



//Funções de Pesquisa:
int PesquisarLivro(TModulo1 modulo, TLivro book)
{
    int i;

    for(i=0;i<modulo.indice;i++)
    {
        if(strcmp(modulo.vetor[i].ID.ISBN,book.ID.ISBN)==0)
        {
            return i;
        }
    }
    return -1;
}

int PesquisarUsuario(TModulo2 modulo, TUsuario user)
{
    int i;

    for(i=0;i<modulo.indice;i++)
    {
        if(strcmp(modulo.vetor[i].CPF,user.CPF)==0)
        {
            return i;
        }
    }
    return -1;
}

int PesquisarEmprestimo(TModulo3 modulo, TEmprestimo borrow)
{
    int i;

    for(i=0;i<modulo.indice;i++)
    {
        if(strcmp(modulo.vetor[i].CPF,borrow.CPF)==0 && strcmp(modulo.vetor[i].ID.ISBN,borrow.ID.ISBN)==0 &&
           modulo.vetor[i].data_emp.dia == borrow.data_emp.dia &&
           modulo.vetor[i].data_emp.mes == borrow.data_emp.mes &&
           modulo.vetor[i].data_emp.ano == borrow.data_emp.ano)
        {
            return i;
        }
    }
    return -1;
}



//Funções de Inserir:
void InserirLivro(TModulo1 *modulo, TLivro book)
{
    if(modulo->indice<100)
    {
        modulo->vetor[modulo->indice]=book;
        modulo->indice++;
        printf("\nCadastro Efetuado com Sucessso\n\n");
    }

    else
    {
        printf("O Cadastro não pode ser Efetuado");
    }

    printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
    system("PAUSE");
}

void InserirUsuario(TModulo2 *modulo, TUsuario user)
{
    if(modulo->indice<100)
    {
        modulo->vetor[modulo->indice]=user;
        modulo->indice++;
        printf("\nCadastro Efetuado com Sucessso");
    }

    else
    {
        printf("O Cadastro não pode ser Efetuado");
    }

    printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
    system("PAUSE");
}

void InserirEmprestimo(TModulo3 *modulo, TEmprestimo borrow)
{

    if(modulo->indice<100)
    {
        borrow.data_ent = CalcularDataEntrega(borrow.data_emp);

        modulo->vetor[modulo->indice] = borrow;
        modulo->indice++;

        printf("\nEmprestimo Efetuado com Sucessso");
    }

    else
    {
        printf("O Emprestimo não pode ser Efetuado, Pois ja foi Feito o Maximo de Emprestimo Possiveis na Biblioteca");
    }
}




//Funções de Alterar
void AlterarLivro(TModulo1 *modulo, TLivro book)
{
    int i;

    i=PesquisarLivro(*modulo,book);

    if(i!=-1)
    {
        LerLivro(&book);
        modulo->vetor[i]=book;
        printf("\nAlteracao do Livro Efetuada com Sucesso");
    }

    else
    {
        printf("\nLivro nao Encontrado para Alteracao");
    }

    printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
    system("PAUSE");
}

void AlterarUsuario(TModulo2 *modulo, TUsuario user)
{
    int i;

    i=PesquisarUsuario(*modulo,user);

    if(i!=-1)
    {
        LerUsuario(&user);
        modulo->vetor[i]=user;
        printf("\nAlteracao do Usuario Efetuada com Sucesso");
    }

    else
    {
        printf("\nUsuario nao Encontrado para Alteracao");
    }

    printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
    system("PAUSE");
}

void AlterarEmprestimo(TModulo3 *modulo, TEmprestimo borrow)
{
    int i;

    i=PesquisarEmprestimo(*modulo,borrow);

    if(i!=-1)
    {
        system("cls");
        printf("\n>>>>>>>>>>>>>> ALTERAR: <<<<<<<<<<<<<<<\n");

        LerEmprestimo(&borrow);

        borrow.data_ent = CalcularDataEntrega(borrow.data_emp);

        modulo->vetor[i] = borrow;
        printf("\nAlteracao do Emprestimo Efetuada com Sucesso");
    }

    else
    {
        printf("\nEmprestimo nao Encontrado para Alteracao");
    }

}



//Funções de Excluir
void ExcluirLivro(TModulo1 *modulo, TLivro book)
{
    int i;

    i=PesquisarLivro(*modulo,book);

    if(i!=-1)
    {
        while(i<modulo->indice-1)
        {
            modulo->vetor[i]=modulo->vetor[i+1];
            i++;
        }

        modulo->indice--;
        printf("\nLivro Exluido com Sucesso");
    }

    else
    {
        printf("\nLivro nao Encontrado para Exclusao");
    }

    printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
    system("PAUSE");
}

void ExcluirUsuario(TModulo2 *modulo, TUsuario user)
{
    int i;

    i=PesquisarUsuario(*modulo,user);

    if(i!=-1)
    {
        while(i<modulo->indice-1)
        {
            modulo->vetor[i]=modulo->vetor[i+1];
            i++;
        }

        modulo->indice--;
        printf("\nUsuario Exluido com Sucesso");
    }

    else
    {
        printf("\nUsuario nao Encontrado para Exclusao");
    }

    printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
    system("PAUSE");
}

void ExcluirEprestimo(TModulo3 *modulo, TEmprestimo borrow)
{
    int i;

    i=PesquisarEmprestimo(*modulo,borrow);

    if(i!=-1)
    {
        while(i<modulo->indice-1)
        {
            modulo->vetor[i]=modulo->vetor[i+1];
            i++;
        }

        system("cls");
        printf("\n>>>>>>>>>>>>>> EXCLUIR: <<<<<<<<<<<<<<<\n");

        modulo->indice--;
        printf("\nEmprestimo Exluido com Sucesso");
    }

    else
    {
        printf("\nEmprestimo nao Encontrado para Exclusao");
    }

}



//Funções Adicionais para o Emprestimo
void MSG_SUBMENU_EMP(int numero_modulo)
{
    system("cls");
    printf("\n>>>>>>>>>>>>>>>>>>>> MODULO %d: <<<<<<<<<<<<<<<<<<<<",numero_modulo);
    printf("\n\n\t1. INSERIR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. ALTERAR");
    printf("\n\t4. EXCLUIR");
    printf("\n\t5. DAR BAIXA");
    printf("\n\t6. EFETUAR PAGAMENTO");
    printf("\n\t7. IMPRIMIR TODOS REGISTROS");
    printf("\n\t8. SAIR");
 }

int Quant_DMes(int mes, int ano)
{
    switch(mes)
    {
        case 1:

            return 31;

        break;

        case 2:

            if(ano%4==0 && ano%400!=0) //Anos Bissestos
            {
                return 29;
            }

            else
            {
                return 28;
            }

        break;

        case 3:

            return 31;

        break;

        case 4:

            return 30;

        break;

        case 5:

            return 31;

        break;

        case 6:

            return 30;

        break;

        case 7:

            return 31;

        break;

        case 8:

            return 30;

        break;

        case 9:

            return 31;

        break;

        case 11:

            return 30;

        break;

        case 12:

            return 31;

        break;
    }
}

TData CalcularDataEntrega(TData data_emprestimo)
{
    TData data_ent = data_emprestimo;
    int i;
    int quant_dia = Quant_DMes(data_ent.mes, data_ent.ano);

    for(i=0;i<14;i++)
    {
        data_ent.dia++;

        if(data_ent.dia>quant_dia)
        {
            data_ent.dia=1;
            data_ent.mes++;
            quant_dia = Quant_DMes(data_ent.mes, data_ent.ano);

            if(data_ent.mes>12)
            {
                data_ent.mes=1;
                data_ent.ano++;
            }
        }
    }

    return data_ent;

}

void DarBaixaEmp(TModulo3 *modulo, TEmprestimo borrow)
{
    int i,d=0;
    int DiasEnt, DiasDev;
    float multa;
    char r;

    i = PesquisarEmprestimo(*modulo,borrow);

    system("cls");
    printf("\n>>>>>>>>>>>>>> DAR BAIXA: <<<<<<<<<<<<<<<\n");

    printf("\n\nData de Devolucao:\n");

    printf("Dia: ");
    fflush(stdin);
    scanf("%d",&borrow.data_dev.dia);

    printf("Mes: ");
    fflush(stdin);
    scanf("%d",&borrow.data_dev.mes);

    printf("Ano: ");
    fflush(stdin);
    scanf("%d",&borrow.data_dev.ano);

    DiasEnt = modulo->vetor[i].data_ent.dia;
    DiasDev = borrow.data_dev.dia;

    switch(modulo->vetor[i].data_ent.mes - 1)
    {
        case 11:
            DiasEnt = DiasEnt + 30;

        case 10:
            DiasEnt = DiasEnt + 31;

        case 9:
            DiasEnt = DiasEnt + 30;

        case 8:
            DiasEnt = DiasEnt + 31;

        case 7:
            DiasEnt = DiasEnt + 30;

        case 6:
            DiasEnt = DiasEnt + 31;

        case 5:
            DiasEnt = DiasEnt + 30;

        case 4:
            DiasEnt = DiasEnt + 31;

        case 3:
            DiasEnt = DiasEnt + 30;

        case 2:
            if(modulo->vetor[i].data_ent.ano%4==0 && modulo->vetor[i].data_ent.ano%400!=0) //Anos Bissestos
                {
                    DiasEnt = DiasEnt + 29;
                }

                else
                {
                    DiasEnt = DiasEnt + 28;
                }

        case 1:
            DiasEnt = DiasEnt + 30;
    }

    switch(borrow.data_dev.mes - 1)
    {
        case 11:
            DiasDev = DiasDev + 30;

        case 10:
            DiasDev = DiasDev + 31;

        case 9:
            DiasDev = DiasDev + 30;

        case 8:
            DiasDev = DiasDev + 31;

        case 7:
            DiasDev = DiasDev + 30;

        case 6:
            DiasDev = DiasDev + 31;

        case 5:
            DiasDev = DiasDev + 30;

        case 4:
            DiasDev = DiasDev + 31;

        case 3:
            DiasDev = DiasDev + 30;

        case 2:
            if(borrow.data_dev.ano%4==0 && borrow.data_dev.ano%400!=0) //Anos Bissestos
                {
                    DiasDev = DiasDev + 29;
                }

                else
                {
                    DiasDev = DiasDev + 28;
                }

        case 1:
            DiasDev = DiasDev + 30;
    }


    d = (DiasDev - DiasEnt) + ((borrow.data_dev.ano - modulo->vetor[i].data_ent.ano)*365);

    multa = (d * 2.0);


    if(multa<=0)
    {
        printf("\nBaixa Realizada com Sucesso");
        modulo->vetor[i].PG = 0;
    }
    else
    {
        modulo->vetor[i].PG = 0;
        modulo->vetor[i].multa = multa;
        printf("\nBaixa Realizada com Sucesso, o Usuario Possue uma Multa de R$%.2f por Atraso de %d Dia(s).\n\n", multa, d);
        system("PAUSE");

        EfetuarPagamento(modulo,borrow);

    }
}

void EfetuarPagamento(TModulo3 *modulo, TEmprestimo borrow)
{
    int i;
    char r;

    i = PesquisarEmprestimo(*modulo,borrow);

    system("cls");
    printf("\n>>>>>>>>>>>>>> EFETUAR PAGAMENTO: <<<<<<<<<<<<<<<");

    printf("\n\nA Multa e de %.2f. Deseja Efetuar o Pagamento? (Use (s) para Sim e (n) para nao)\n", modulo->vetor[i].multa);
    fflush(stdin);
    scanf("%c",&r);

    if(r=='s')
    {
        modulo->vetor[i].PG = 1;
        printf("\nPagamento Efetuado");
    }

}



//Funções dos Menus
void MSG_MENU(void)
{
    printf("\n>>>>>>>>>>>>>>>>>>> MENU: <<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. MODULO - LIVRO");
    printf("\n\t2. MODULO - USUARIO");
    printf("\n\t3. MODULO - EMPRESTIMO");
    printf("\n\t4. SAIR");
 }

void MSG_SUBMENU(int numero_modulo)
{
    system("cls");
    printf("\n>>>>>>>>>>>>>>>>>>>> MODULO %d: <<<<<<<<<<<<<<<<<<<<",numero_modulo);
    printf("\n\n\t1. INSERIR");
    printf("\n\t2. PESQUISAR");
    printf("\n\t3. ALTERAR");
    printf("\n\t4. EXCLUIR");
    printf("\n\t5. IMPRIMIR TODOS REGISTROS");
    printf("\n\t6. SAIR");
 }

void SubMenuModulo1(TModulo1 *modulo, TLivro book)
{
    int opcao = 0;
    int r;
    do
    {
        MSG_SUBMENU(1);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // Chamada da Função Inserir
                system("cls");
                printf("\n>>>>>>>>>>>>>> INSERIR: <<<<<<<<<<<<<<<");
                LerLivro(&book);
                InserirLivro(modulo,book);
                break;

            case 2:
                // Chamada da Função Pesquisar
                printf("\n\nDigite o ISBN para Pesquisa: ");
                fflush(stdin);
                fgets(book.ID.ISBN,100,stdin);

                r = PesquisarLivro(*modulo,book);

                if(r!=-1)
                {
                    system("cls");
                    printf("\n>>>>>>>>>>>>>> PESQUISAR: <<<<<<<<<<<<<<<");


                    printf("\n\nLivro Encontrado:");
                    ImprLivro(modulo->vetor[r]);
                }
                else
                {
                    printf("\n\nLivro nao Encontrado");
                }

                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 3:
                // Chamada da Função Alterar
                printf("\n\nDigite o ISBN para Alterar: ");
                fflush(stdin);
                fgets(book.ID.ISBN,100,stdin);

                system("cls");
                printf("\n>>>>>>>>>>>>>> ALTERAR: <<<<<<<<<<<<<<<");

                AlterarLivro(modulo,book);

                break;

            case 4:
                // Chamada da Função Excluir
                printf("\n\nDigite o ISBN para Excluir: ");
                fflush(stdin);
                fgets(book.ID.ISBN,100,stdin);

                system("cls");
                printf("\n>>>>>>>>>>>>>> Excluir: <<<<<<<<<<<<<<<");

                ExcluirLivro(modulo,book);

                break;

            case 5:
                ImprimirTodosLivros(modulo);
                printf("\n\n");
                system("PAUSE");
                break;

            case 6:
                printf("\n\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");

                break;

            default:
                printf("\n\n\n>>>> MSG: Digite uma opcao valida!!! <<<<");
                system("PAUSE");

        }
    }
    while(opcao != 6);
 }

void SubMenuModulo2(TModulo2 *modulo, TUsuario user)
{
    int opcao = 0;
    int r;
    do
    {
        MSG_SUBMENU(2);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // Chamada da Função Inserir
                system("cls");
                printf("\n>>>>>>>>>>>>>> INSERIR: <<<<<<<<<<<<<<<");
                LerUsuario(&user);
                InserirUsuario(modulo,user);
                break;

            case 2:
                // Chamada da Função Pesquisar
                printf("\n\nDigite o CPF para Pesquisa: ");
                fflush(stdin);
                fgets(user.CPF,100,stdin);

                r = PesquisarUsuario(*modulo,user);

                if(r!=-1)
                {
                    system("cls");
                    printf("\n>>>>>>>>>>>>>> PESQUISAR: <<<<<<<<<<<<<<<");


                    printf("\n\nUsuario Encontrado:");
                    ImprUsuario(modulo->vetor[r]);
                }
                else
                {
                    printf("\n\nUsuario nao Encontrado");
                }

                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 3:
                // Chamada da Função Alterar
                printf("\n\nDigite o CPF para Alterar: ");
                fflush(stdin);
                fgets(user.CPF,100,stdin);

                system("cls");
                printf("\n>>>>>>>>>>>>>> ALTERAR: <<<<<<<<<<<<<<<");

                AlterarUsuario(modulo,user);

                break;

            case 4:
                // Chamada da Função Excluir
                printf("\n\nDigite o CPF para Excluir: ");
                fflush(stdin);
                fgets(user.CPF,100,stdin);

                system("cls");
                printf("\n>>>>>>>>>>>>>> Excluir: <<<<<<<<<<<<<<<");

                ExcluirUsuario(modulo,user);

                break;

            case 5:

                ImprimirTodosUsuarios(modulo);
                printf("\n\n");
                system("PAUSE");
                break;

            case 6:
                printf("\n\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            default:
                printf("\n\n\n>>>> MSG: Digite uma opcao valida!!! <<<<");
                system("PAUSE");

        }
    }while(opcao != 6);
}

void SubMenuModulo3(TModulo3 *modulo3, TEmprestimo borrow, TModulo2 *modulo2, TUsuario user, TModulo1 *modulo1, TLivro book)
{
    int opcao = 0;
    int x,y,z;

    do
    {
        MSG_SUBMENU_EMP(3);
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // Chamada da Função Inserir

                printf("\n\nDigite o CPF para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.CPF,100,stdin);

                printf("\nDigite o ISBN para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.ID.ISBN,100,stdin);

                strcpy(user.CPF, borrow.CPF);
                strcpy(book.ID.ISBN, borrow.ID.ISBN);

                y = PesquisarUsuario(*modulo2,user); // Pesquisa indice do Usuario
                x = PesquisarLivro(*modulo1,book); // Pesquisa indice do Livro


                if(x!=-1 && y!=-1 && (modulo1->vetor[x].quant_emp)/(modulo1->vetor[x].quant)<=0.9) // Calcula a Porcentagem de Livros
                {
                    if(modulo2->vetor[y].tipo == 1 && modulo2->vetor[y].livros<5 && modulo2->vetor[y].multa<=0) // Confere se o Usuario é Professorou Aluno e se Tem Multa
                    {
                        system("cls");
                        printf("\n>>>>>>>>>>>>>> INSERIR: <<<<<<<<<<<<<<<");

                        printf("\n\nDigite as Informacoes do Emprestimo\n\n");
                        LerEmprestimo(&borrow);
                        InserirEmprestimo(modulo3,borrow);
                        modulo1->vetor[x].quant_emp++; // Adiciona um livro Emprestado nos Livros
                        modulo2->vetor[y].livros++; // Adiciona um livro Emprestado no Usuario

                    }

                    if(modulo2->vetor[y].tipo == 2 && modulo2->vetor[y].livros<3 && modulo2->vetor[y].multa<=0) // Confere se o Usuario é Aluno
                    {
                        system("cls");
                        printf("\n>>>>>>>>>>>>>> INSERIR: <<<<<<<<<<<<<<<");

                        LerEmprestimo(&borrow);
                        InserirEmprestimo(modulo3,borrow);
                        modulo1->vetor[x].quant_emp++; // Adiciona um livro Emprestado nos Livros
                        modulo2->vetor[y].livros++; // Adiciona um livro Emprestado no Usuario

                    }

                    else
                    {
                        printf("\nO Cadastro nao pode ser Efetuado, pois o Usuario Ja Atingiou o Numero Maximo de Emprestimos ou Contem Multa");
                    }

                }

                else
                {
                    printf("\nO Cadastro nao pode ser Efetuado, pois o a Blioteca Atingiu a Quantidade Minima de Livros ou Usuario ou Livro nao Existe\n");
                }

                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 2:
                // Chamada da Função Pesquisar

                printf("\n\nDigite o CPF para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.CPF,100,stdin);

                printf("\nDigite o ISBN para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.ID.ISBN,100,stdin);

                LerEmprestimo(&borrow);

                z = PesquisarEmprestimo(*modulo3,borrow);

                if(z!=-1)
                {
                    system("cls");
                    printf("\n>>>>>>>>>>>>>> PESQUISAR: <<<<<<<<<<<<<<<");


                    printf("\n\nEmprestimo Encontrado:");
                    ImprEmprestimo(modulo3->vetor[z]);
                }
                else
                {
                    printf("\n\nEmprestimo nao Encontrado");
                }

                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 3:
                // Chamada da Função Alterar

                printf("\n\nDigite o CPF para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.CPF,100,stdin);

                printf("\nDigite o ISBN para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.ID.ISBN,100,stdin);

                LerEmprestimo(&borrow);

                strcpy(book.ID.ISBN,borrow.ID.ISBN);

                z = PesquisarEmprestimo(*modulo3,borrow); // Pesquisa indice do Emprestimo
                x = PesquisarLivro(*modulo1,book); // Pesquisa indice do Livro

                if(z!=-1 && modulo1->vetor[x].quant_emp>0)
                {
                    modulo1->vetor[x].quant_emp--; // Tira o Livro Emprestado de Livro
                }
                else
                {
                    printf("\n\nCPF, ISBN ou Data Invalida\n\n");
                    system("PAUSE");
                }

                do
                {
                    printf("\nDigite o Novo ISBN para Pesquisa: ");
                    fflush(stdin);
                    fgets(book.ID.ISBN,100,stdin);

                    x = PesquisarLivro(*modulo1,book); //Pesquisa se Livro Existe
                    if(x!=-1)
                    {
                        strcpy(book.ID.ISBN,borrow.ID.ISBN);
                        AlterarEmprestimo(modulo3,borrow);
                        modulo1->vetor[x].quant_emp++; // Adiciona um livro Emprestado no Novo Livro
                    }
                    else
                    {
                       printf("ISBN Invalido");
                    }
                }while(x<0);

                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 4:
                // Chamada da Função Excluir

                printf("\n\nDigite o CPF para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.CPF,100,stdin);

                printf("\nDigite o ISBN para Pesquisa: ");
                fflush(stdin);
                fgets(book.ID.ISBN,100,stdin);

                LerEmprestimo(&borrow);

                strcpy(book.ID.ISBN,borrow.ID.ISBN);
                strcpy(user.CPF, borrow.CPF);

                z = PesquisarEmprestimo(*modulo3,borrow); // Pesquisa indice do Emprestimo
                y = PesquisarUsuario(*modulo2,user); // Pesquisa indice do Usuario
                x = PesquisarLivro(*modulo1,book); // Pesquisa indice do Livro

                if(z!=-1 && modulo1->vetor[x].quant_emp>0)
                {
                    modulo1->vetor[x].quant_emp--; // Tira o Livro Emprestado de Livro
                    modulo2->vetor[y].livros--; // Tira o Livro Emprestado no Usuario
                    ExcluirEprestimo(modulo3, borrow);
                }
                else
                {
                    printf("\n\nCPF, ISBN ou Data Invalida\n\n");
                    system("PAUSE");
                }

                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 5:
                // Chamada da Função Dar Baixa

                printf("\n\nDigite o CPF para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.CPF,100,stdin);

                printf("\nDigite o ISBN para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.ID.ISBN,100,stdin);

                LerEmprestimo(&borrow);

                strcpy(book.ID.ISBN,borrow.ID.ISBN);
                strcpy(user.CPF, borrow.CPF);

                z = PesquisarEmprestimo(*modulo3,borrow); // Pesquisa indice do Emprestimo
                y = PesquisarUsuario(*modulo2,user); // Pesquisa indice do Usuario
                x = PesquisarLivro(*modulo1,book); // Pesquisa indice do Livro

                if(z!=-1 && modulo1->vetor[x].quant_emp>0)
                {
                    modulo1->vetor[x].quant_emp--; // Tira o Livro Emprestado de Livro
                    modulo2->vetor[y].livros--; // Tira o Livro Emprestado no Usuario
                    DarBaixaEmp(modulo3, borrow);

                    if(modulo3->vetor[z].multa>0 && modulo3->vetor[z].PG == 0)
                    {
                        modulo2->vetor[y].multa = modulo3->vetor[z].multa;
                    }
                }
                else
                {
                    printf("\n\nCPF, ISBN ou Data Invalida\n\n");
                }

                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 6:
                // Chamada da Função Efetuar Pagamento

                printf("\n\nDigite o CPF para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.CPF,100,stdin);

                printf("\nDigite o ISBN para Pesquisa: ");
                fflush(stdin);
                fgets(borrow.ID.ISBN,100,stdin);

                LerEmprestimo(&borrow);

                strcpy(book.ID.ISBN,borrow.ID.ISBN);
                strcpy(user.CPF,borrow.CPF);

                z = PesquisarEmprestimo(*modulo3,borrow); // Pesquisa indice do Emprestimo
                y = PesquisarUsuario(*modulo2,user); // Pesquisa indice do Usuario

                if(z!=-1 && modulo3->vetor[z].PG == 0)
                {
                    EfetuarPagamento(modulo3,borrow);
                    modulo2->vetor[y].multa = 0.0;
                }
                else
                {
                    printf("\n\nCPF, ISBN ou Data Invalida\n\n");
                }

                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 7:
                // Chamada da Função Imprimir Todos Emprestimos

                ImprimirTodosEmprestimos(modulo3);
                printf("\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            case 8:
                printf("\n\n\n>>>> MSG: Saindo do MODULO...!!! <<<<");
                system("PAUSE");
                break;

            default:
                printf("\n\n\n>>>> MSG: Digite uma opcao valida!!! <<<<");
                system("PAUSE");

        }
    }while(opcao != 8);
}



//Função Main
int main(void)
{
    // Declaração das variáveis módulo
    TModulo1 mod1;
    TModulo2 mod2;
    TModulo3 mod3;


    //Declaração de variáveis auxiliares
    TLivro book;
    TUsuario user;
    TEmprestimo borrow;
    int opcao = 0;
    int r;


    //Teste Chamada de Função
    IniciarModulo1(&mod1);
    IniciarModulo2(&mod2);
    IniciarModulo3(&mod3);


    do{
        system("cls");
        MSG_MENU();

        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                // Chamada de Função para o submenu do Módulo I
                SubMenuModulo1(&mod1,book);
            break;

            case 2:
                // Chamada de Função para o submenu do Módulo II
                SubMenuModulo2(&mod2, user);
            break;

            case 3:
                // Chamada de Função para o submenu do Módulo III
                SubMenuModulo3(&mod3, borrow, &mod2, user, &mod1, book);
                break;

            case 4:
                printf(">>>> MSG: Saindo do programa...!!! <<<<");
                system("PAUSE");
                break;

            default:
                printf(">>>> MSG: Digite uma opcao valida!!! <<<<");
                system("PAUSE");

        }
    } while(opcao != 4);

    printf("\n\n");
    return 0;
}
