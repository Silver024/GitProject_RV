#include <stdio.h>
#include <string.h>
#include "funcoes_auxiliares.h"


// Acrescentada variavel controlo para repetir insercao se ao for inserido numero int
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }

    }
    while (tamanhoString == 1);

    if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
    {
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString-1] = '\0'; 	//Elimina o \n da string armazenada em vetor
    }

}

tipoData LerData()
{
    tipoData data;
    int max;

    data.mes=lerInteiro("introduza o mes:",0,12);
    data.ano=lerInteiro("introduza o ano:",MIN_ANO,MAX_ANO);

    switch (data.mes)
    {


    case 4:
    case 6:
    case 9:
    case 11:
        max=30;
        break;
    case 2:
        if ((data.ano%400==0) || (data.ano%4==0 && data.ano%100!=0))
        {
            max=29;
        }
        else
        {
            max=28;
        }

        break;

    default:
        max=31;

    }
    data.dia=lerInteiro("Introduza o dia:",1,max);

    return data;
}

int funcaoMenuPrincipal()
{
    int opcao;
    do{
    printf("\n\n-----------MENU(Principal)---------\n");
    printf("(1)Menu Estudantes\n");
    printf("(2)Menu Perguntas\n");
    printf("(3)Fechar programa\n");
    printf("\tOpcao--> ");
    scanf("%d", &opcao);
        if(opcao!=1 && opcao!=2 && opcao!=3){
            printf("Opcao invalida!!\n");
        }
        limpaBufferStdin();
    }while(opcao!=1 && opcao!=2 && opcao!=3);

    return opcao;
}

void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}
