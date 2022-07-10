#include <iostream>
//Permite usar controles de leituras e gravações como cin, getline etc..
#include <stdio.h>
//Permite entrada e saída de dados
#include <locale.h>
//Permite para usar setlocale
#include <conio.h>
//Permite o uso de kbhit
#include <windows.h>
//Permite fazer o uso de todas as funções da API do windows
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

void cadastrar_Produto()
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

void listar_Produto()
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
int i = 0;
size_t count = 0;
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
            if ( strcmp( entry->d_name, "." ) && strcmp( entry->d_name, ".." ) )
            {
                printf("    %zu) - %s\n", count + 1, entry->d_name);
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
cout<<li;
//Imprime a linha selecionada, futuramente será usada como index
system("PAUSE");
//Pausa o sistema para podermos visualizar a variavel li
//Essa parte será excluido posteriormente, é apenas para verificação do Index.

                        switch(li)
/*
Após a tecla ENTER ser presionada ele pega o numero armazenado em li e troca para caso
correspondente.
*/
                        {
/*
Agora precisamos fazer com que pelo index pegue o nome do produto(arquivo)
Swtich apenas aceita constant ou seja apenas numeros 1,2,3 etc..
tirar o switch por if talvez.
*/
                            case 1:
                            cadastrar_Produto();
                            //break;
                        }while(tecla != 27);
}


int main(){
    system("MODE con cols=60 lines=40");
/*
Definimos o tamanho do CMD(Menu) que queremos
Se mudar a quantidade de colunas e linhas isso altera
nosso programa causando bugs.
*/
    system("title Programa Vendas");
/*
	Define título do CMD(Menu/Programa)
*/



    int li=1,tecla;
/*
Declaramos a variável li que representa Linha na posição 1 e tecla que será  usada para armazenar a tecla pressionada pelo usuário.
*/
    setlocale(LC_ALL,"Portuguese");
/*
	Declara localidade como Brasil Portugues para podermos usar a acentuação.
*/

/*
	Do (faça) While (Enquanto) é basicamente oque ele faz. Faça o menu do sistema e	espere por teclas pressionadas.
	Se pressionada executa função tudo isso
	enquanto tecla for diferente de 13, quero alterar para tecla ESC enquanto
	tecla !=(Diferente) de 27 mas por algum motivo não funciona.
	27 é o número correspondente a tecla ESC em ASCII.

*/
    do{
        textcolor(9,15);//cor do sistema, (Cor da letra, Fundo do CMD)
        system("cls");// Limpa a tela do CMD
        cout<<("\t\tMENU\n");

        printf("\t1 - CADASTRAR PRODUTO         \n");
        printf("\t2 - LISTAR PRODUTOS           \n");
        printf("\t3 - DELETAR                   \n");
        printf("\t4 - VENDAS                    \n");
        printf("\t5 - SAIR                      \n");

        gotoxy(4,li);//Inicia na posição na coluna 4 linha 1.
        printf("->");//Imprime na posição acima o desenho.
        gotoxy(79,24);// tira o cursor do cmd da tela.
        do{
            tecla=0;
            if(kbhit()){
                tecla = getch();
                gotoxy(4,li);
                printf("  ");
                if(tecla==224)
                    tecla = getch();
                if(tecla == 72)
                    li--;
                else
                    if(tecla == 80)
                        li++;
                if(li > 4)
                    li=1;
                else
                    if(li < 1)
                        li=4;
                gotoxy(4,li);
                printf("->");
                gotoxy(79,24); /* se não quiser que cursor fique piscando ali */
            }
        }while(tecla != 13);
	/*
		Enquanto diferente da tecla ENTER(ASCI 13), se for igual entra em Switch
        onde podemos criar os Submenus e suas funções.
    */
        system("cls");
        switch(li){
        case 1:
            cadastrar_Produto();
            break;
        case 2:
            listar_Produto();
            break;
        case 3:
            return 0;
        case 4:
            return 0;
        case 5:
            return 0;
        }

 }while(li != 6);//Linha do menu que representa Sair, ao clicar retorna 0, finaliza o //programa.
    return 0;
}
