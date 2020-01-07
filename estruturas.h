#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "constantes.h"

typedef struct
{
    int dia,mes,ano;
}tipoData;


typedef struct
{
    int quantidade;
    int respostasCorretas;
    int respostasErradas;
    float Nota;
}tipoInformacao;

typedef struct  // RESPOSTA DADA PELO UTILIZADOR NO TREINO
{
 int design; //designação unica da prova
 int numTreino;
 char resposta;
}tipoRespostaUtilizador;

typedef struct
{
    char a[30];
    char b[30];
    char c[30];
    char d[30];

}tipoRespostasPergunta;

typedef struct
{
    int design;    //designação unica da prova    *strcat*(P1,P2,P3)
    char questao[DIM_PERGUNTA];    //pergunta
    tipoRespostasPergunta respostas; // fazer uma estrutura para as 4 respostas(ID e ou (a,b,c,d),TEXTO)
    char respostasCorreta; //a,b,c,d
    char tipoPergunta[20]; //EstruturaDeControlo,Vetor ou Ponteiro
    int prova;   // Prova 1,2,3,4

}tipoPergunta;


typedef struct
{
    int numAluno;   //Num Aluno
    char nome[MAX_NOME];
    char alunoTipo[15]; //Normal,Trabalhador,Extraordinario
    char regime[12];//pos-laboral e diurno
    char turno[15]; //
}tipoEstudante;


typedef struct
{
    int numTreino;
    int numEstudante;
    tipoData data;
    int hora;
    int tempoProva;
    int prova;    // prova(1 a 4)
    char estado;
    tipoInformacao treino;
}tipoTreino;




#endif // ESTRUTURAS_H_INCLUDED
