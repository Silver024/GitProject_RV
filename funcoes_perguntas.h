#ifndef FUNCOES_PERGUNTAS_H_INCLUDED
#define FUNCOES_PERGUNTAS_H_INCLUDED


tipoPergunta lePergunta();
void acrescentaPergunta(tipoPergunta vPerguntas[MAX_PERGUNTAS], int *quantidadePerguntas);
int funcaoMenuPergunta();
void mostrarDadosDasPerguntas(tipoPergunta vPerguntas[MAX_PERGUNTAS],int quantidade);
int procuraPergunta(int numero, tipoPergunta vPerguntas[MAX_PERGUNTAS], int quantidade);
int eliminaPergunta(tipoPergunta vPerguntas[MAX_PERGUNTAS], int quantidade);
void gravaFicheiroPerguntas_Binario(tipoPergunta vPerguntas[], int quantidade);
void leFicheiroPergunta_Binario(tipoPergunta vPerguntas[], int *quantidade);
#endif // FUNCOES_PERGUNTAS_H_INCLUDED
