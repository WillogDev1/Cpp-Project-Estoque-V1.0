#include <iostream>
//Permite usar controles de leituras e gravações como cin, getline etc..
#include <stdio.h>
//Permite entrada e saída de dados
#include <locale.h>
//Permite para usar setlocale
#include <conio.h>
//Permite o uso de kbhit
#include <windows.h>
//Permite fazer o uso de todas as funções da API do windows, exemplo cor do CMD e cor da letra
#include <string.h>
//Permite o uso de strcpy, strncpy, strcmp dentre outros
#include <stdlib.h>
//Permite o uso do size_t wchar_t entre outros
#include <cctype>
//Permite declara tolower, toupper, isdigit, isspace etc...
#include <cstring>
//Permite funções adicionais para manipular strings e arrays
#include <cstdio>
//Permite entrada e saída de dados como printf, gets e etc..
#include <fstream>
//Permite o uso de Ifstream, ofstream e afins
#include <string>
//Permite manipular Strings
#include <dirent.h>
//Permite o uso de readdir para acessar e ler diretorios
#include <winsock2.h>
//Permite usar algumas funções sem STD::cout
#include <vector>
//Permite usar vector, push dentre outras//Classe

using namespace std;
//             0    1     2    3    4     5      6       7        8
typedef enum{BLACK,BLUE,GREEN,CYAN,RED,MAGENTA,BROWN,LIGHTGRAY,DARKGRAY,
LIGHTBLUE,LIGHTGREEN,LIGHTCYAN,LIGHTRED,LIGHTMAGENTA,YELLOW,WHITE} COLORS;
/* 9         10        11        12        13          14    15          */
/*
    Declarando enum assim todas os nomes dentro se torne um index.
*/
//declara as cores plano de fundo e o contorno da linha por default
static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

void textcolor (int letra, int fundo)
{
//Para mudar a cor de fundo do sistema ou a letra
    __FOREGROUND = letra;//cor da Letra
    __BACKGROUND = fundo;//cor do Fundo
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
    letra + (__BACKGROUND << 4));
}
void gotoxy(int x,int y)
{
//Permite se movimentar por localização
    COORD c;//Struct COORD recebe c
    c.X = x;//Coluna
    c.Y = y;//Linha
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void cadastrarProduto()
{
//Declaramos um diretório para salvar os arquivos
string directory = "C:/db_NoSQL/produtos/";
/*
Lembra do “using namespace std;” então, basicamente não precisamos mais usar o std
teste para ver que conseguimos rodar com ambas as declarações.
Note, se a variável foi declarada com std:: ela precisa ser usada com std:: posteriormente
*/
std::string name;
std::string qtd;
char ch;
//Declarando variável para tecla ESC
bool ESCAPE = false;
//Booleano para loop do while
    while (!ESCAPE)
//Enquanto ESCAPE for diferente de FALSE faça
    {
    cout<<"*************************\n";
    cout<<"Insira o nome do produto: ";
    std::getline(std::cin,name);
//Usando Getline para conseguir pegar string com espaços
    std::ofstream out(directory + name + ".txt");
//Entra o diretório depois o nome do arquivo e o tipo de arquivo
    cout<<"Insira a Quantidade: ";
    getline(std::cin,qtd);
    out << qtd;
/*
    Grava a quantidade usando "out".
    Para o futuro pretendo fazer que salve em forma JSON
    assim poderemos trabalhar de uma forma mais estruturada
    ao receber os dados.
*/
        if (kbhit)
//determinar se uma tecla foi pressionada ou não
        {
            cout<<"Cadastrar novo Item aperte ENTER ou aperte ESC para voltar ao menu principal"<<endl;
            ch = getch();
            if ((int)ch == 27)
            break;
            cout<<"Quantidade Cadastrada: " + qtd + "\n";
        }
    }
}

void listarProduto()
{
system("MODE con cols=168 lines=60");
DIR *dir;
struct dirent *entry;
/*
    struct dirent{
        long d_ino;
        ...
        char d_name[PATH_MAX+1]
    }
Dirent é um struct do proprio sistema contendo essas variaveis pré declaradas
oque nos permite chamar o d_name com o entry
entry é um ponteiro na memoria que liga a dirent
entry->d_name
*/
string arqV;
std::vector<std::string> files;
string directory = "C:/db_NoSQL/produtos/";
string qtdAtualiza;
size_t count = 0;
char *indexar[100] = {"foo"};
int j = 0;
int i = 0;
/*
    Usado para indexar o array que contaremos quanta arquivos temos
*/
//Abre o diretorio para preparar para listagem
    if ((dir = opendir("C:/db_NoSQL/produtos/")) == NULL)
    perror("opendir() error");
    int li=0,tecla;
    puts("      Produtos cadastrados");
        do
        {
            while ((entry = readdir(dir)) != NULL)
/*
    declara a variavel entry para receber o readddir de do dir e se for difrente de NULL
    ou seja, enquanto arquivo existir (for diferente de nulo) faça
*/
            if ( strcmp( entry->d_name, "." ) && strcmp( entry->d_name, ".." ))

            {

                printf("    %zu) - %s\n", count + 0, indexar[count] = entry->d_name);
                count++;

            }
            gotoxy(0,li);
            printf("->");
            gotoxy(79,24);
                tecla=0;
                if(kbhit())
                {
                    tecla = getch();
                    gotoxy(0,li);
                    printf("  ");
                    if(tecla==224)
                        tecla = getch();
                    if(tecla == 72)
                        li--;
                    else
                        if(tecla == 80)
                            li++;
                    if(li > count)
//se a linha que estamos percorrendo for maior que count ele volta para linha 0
                        li=0;
                    else
                        if(li < 1)
//se a linha que estamos percorrendo for menor que 1 ele pula para posição total
                            li=count;
                    gotoxy(0,li);
                    printf("->");
                    gotoxy(79,24);/* se não quiser que cursor fique piscando ali */
                    }

                        }while (tecla != 13);
//Quando tecla for igual a ENTER
system("cls");

    if ((dir = opendir("C:/db_NoSQL/produtos/")) != nullptr) {
        while ((entry = readdir(dir)) != nullptr) {
            if ( strcmp( entry->d_name, "." ) && strcmp( entry->d_name, ".." ))
            files.push_back(std::string (entry->d_name));
        }//Declaramos novamente para abrir o local de arquivo e listar no vetor files
         //assim podemos indexar cada nome encontrado no diretorio
        closedir (dir);
    } else {
        perror ("opendir");
    }


    arqV = files[li - 1];//arqV recebe a posição li -1 que corresponde a opção selecionada
    cout<<arqV<<endl;//imprime para verificar
    puts("Insira a quantidade atualizada \n");
    std::getline(std::cin,qtdAtualiza);
    std::ofstream out(directory + arqV);//abri o arquivo selecionado
    out<<qtdAtualiza;//atualiza a quantidade
    /*
        -Implementar
            -Perguntar ao usuario se deseja atualizar ou voltar ao menu
            -Atualiza no final do arquivo e não apaga o anterior
                -Futuro distante
                    -Como já comentado queremos salvar dado em formato JSON assim conseguimos salvar mais dados
                        e logo, aqui, faremos alterar apenas a quantidade desse formato.
                            info{
                                "codigo": "codigo",
                                "quantidade": "quantidade",
                                "categoria": "categoria"
                            }
    */
system("PAUSE");
}
void excluirProduto()
{
system("MODE con cols=168 lines=60");
DIR *dir;
struct dirent *entry;
std::vector<std::string> files;
string directory = "C:/db_NoSQL/produtos/";
size_t conta = 0;
    if ((dir = opendir("C:/db_NoSQL/produtos/")) == NULL)
    perror("opendir() error");
    int li=1,tecla;
    puts("      Produtos cadastrados");
        do

        {
            while ((entry = readdir(dir)) != NULL)
            {
                if ( strcmp( entry->d_name, "." ) && strcmp( entry->d_name, ".." ))

                {
                        printf("    %zu) - %s\n", conta + 1, entry->d_name);
                        conta++;

                }
            }
            gotoxy(0,li);
            printf("->");
            gotoxy(79,24);
                tecla=0;
                if(kbhit())
                {
                    tecla = getch();
                    gotoxy(0,li);
                    printf("  ");
                    if(tecla==224)
                        tecla = getch();
                    if(tecla == 72)
                        li--;
                    else
                        if(tecla == 80)
                            li++;
                    if(li > conta)

                        li=0;
                    else
                        if(li < 1)

                            li=conta;
                    gotoxy(0,li);
                    printf("->");
                    gotoxy(79,24);
                    }

                        }while (tecla != 13);

system("cls");
    if ((dir = opendir("C:/db_NoSQL/produtos/")) != nullptr) {
        while ((entry = readdir(dir)) != nullptr) {
            if ( strcmp( entry->d_name, "." ) && strcmp( entry->d_name, ".." ))
            files.push_back(std::string (entry->d_name));//adiciona o elemento ao final do vetor files
        }
        closedir (dir);
    } else {
        perror ("opendir");
    }

    string deleteArqv;
    char diretorio[100] = "C:/db_NoSQL/produtos/";//Declaramos o diretorio
    deleteArqv = files[li - 1];//deleteArqv recebe a posição do vetor
    const char * c = deleteArqv.c_str();//trasnforma em consta char
    strcat(diretorio,c);//concatena diretorio com o nome do arquivo
    cout<<diretorio<<endl;
    int rc = remove( diretorio );//remove o arquivo selecionado
    system("PAUSE");
}

int main(){
/*
   - Em int main() vamos criar nosso menu principal
    e partir dele os submenus que executam outras funções
*/
    system("MODE con cols=60 lines=40");
//Aqui conseguimos dizer o tamanho do CMD cols(colunas) lines(linha)
    system("title Programa Vendas");
//Define um título que aparece na parte superior do
    int li=1,tecla;
/*
Declaramos variáveis "li" e "tecla", "li" irá representar a linha
atual e tecla será usado para esperar por uma entrada do teclado
*/
    setlocale(LC_ALL,"Portuguese");
//Diz que a localização é portugues para podermos usar caracteres com acentuação

    do{
//Faça
        textcolor(9,15);
//Declara (Cor da Linha, Cor de fundo)
        system("cls");
//Limpa o CMD
        cout<<("\t\tMENU\n");
        printf("\t1 - CADASTRAR PRODUTO         \n");
        printf("\t2 - LISTAR PRODUTOS           \n");
        printf("\t3 - DELETAR                   \n");
        printf("\t4 - VENDAS                    \n");
        printf("\t5 - SAIR                      \n");
//Desenho do Menu
        gotoxy(4,li);//Inicia na posição coluna 4 linha 1.
        printf("->");//Imprime na posição acima o desenho.
        gotoxy(79,24);// tira o cursor do cmd da tela.
        do{
            tecla=0;
            if(kbhit()){
                tecla = getch();
                gotoxy(4,li);
                printf("  ");
 // Se tecla for pressionada vai para posição anterior e imprime backspaces para apagar a seta da opção anterior "->"
                if(tecla == 72)
//se tecla for igual 72 (Seta para cima)
                    li--;
//li(Linha) andar -1 posição da linha
                else
//se tecla for igual 80 (Seta para baixo)
                    if(tecla == 80)
                        li++;
//li(Linha) andar +1 posição da linha
                if(li > 5)
                    li=1;
//Se li(Linha) for maior que 4, li recebe 1 retornando a posição 1 do menu
                else
                    if(li < 1)
                        li=5;
//Se li(Linha) for menor que 1 li recebe 4 retornando a posição 4 do menu
                gotoxy(4,li);
                printf("->");
                gotoxy(79,24);
//Imprime a seta "->" quando pressionado as teclas
            }
        }while(tecla != 13);
//Enquanto for diferente da tecla ENTER se pressionado faça
        system("cls");
        switch(li){
//Pegamos a li atual quando pressionado ENTER e criamos CASE
        case 1:
            cadastrarProduto();
            break;
        case 2:
            listarProduto();
            break;
        case 3:
            excluirProduto();
            break;
        case 4:
            return 0;
        case 5:
            return 0;
        }
 }while(li != 27);
//Repete enquanto li for diferente de 27
//se caso for 27 retorna 0
    return 0;

}
