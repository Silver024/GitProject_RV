#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "estruturas.h"
#include "funcoes_estudantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_perguntas.h"

int main()
{
  tipoEstudante vEstudante[MAX_ALUNOS];
  tipoPergunta vPerguntas[40];
  int totalEstudantes=0,numeroEstudante,posicao,opcaoMenu,opcaoSubMenuAlunos,opcaoSubMenuPerguntas,totalPerguntas;
  int numeroPergunta;
 leFicheiroEstudante_Binario(vEstudante,&totalEstudantes);
 leFicheiroPergunta_Binario(vPerguntas,&totalPerguntas);
do
{
    opcaoMenu=funcaoMenuPrincipal();
    switch(opcaoMenu)
    {
    case 1:
        do{
opcaoSubMenuAlunos = funcaoMenuAluno();
switch(opcaoSubMenuAlunos){
        case 1:
            acrescentaEstudante(vEstudante, &totalEstudantes);
            break;
        case 2:
            mostrarDadosEstudante(vEstudante, totalEstudantes);
            break;
        case 3:
            printf("\n->Procurar estudante\n\tInserir numero do estudante: ");
    scanf("%d", &numeroEstudante);
            posicao = procuraEstudante(numeroEstudante, vEstudante, totalEstudantes);
                if(posicao == -1){
                    printf("***Nao ha nenhum estudante com o numero inserido!!***\n");
                }
            break;
        case 4:
            totalEstudantes=eliminaEstudante(vEstudante,totalEstudantes);
            break;
        case 5:
            //voltar ao menu anterior
            break;
    }

}while(opcaoSubMenuAlunos!=5);

        break;
    case 2:

        do{
opcaoSubMenuPerguntas = funcaoMenuPergunta();
switch(opcaoSubMenuPerguntas){
        case 1:                                   //acrescenta Pergunta
            acrescentaPergunta(vPerguntas,&totalPerguntas);
            break;
        case 2:    //Mostra as perguntas
           mostrarDadosDasPerguntas(vPerguntas,totalPerguntas);
            break;
        case 3:
            printf("Introduza o numero da pergunta que deseja procurar:");
            scanf("%d",&numeroPergunta);
            posicao=procuraPergunta(numeroPergunta,vPerguntas,totalPerguntas);
            if(posicao==-1)printf("\n***Essa pergunta nao esta inserida***\n");
            break;
        case 4:
            totalPerguntas=eliminaPergunta(vPerguntas,totalPerguntas);
            break;
        case 5:
            //voltar ao menu anterior
            break;
    }

}while(opcaoSubMenuPerguntas!=5);
        break;
    case 3:
        // acaba o programa
        break;
    }

}while(opcaoMenu!=3);


 gravaFicheiroEstudante_Binario(vEstudante,totalEstudantes);
 gravaFicheiroPerguntas_Binario(vPerguntas,totalPerguntas);

    return 0;
}
