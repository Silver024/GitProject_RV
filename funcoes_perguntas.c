#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funcoes_auxiliares.h"
#include "funcoes_estudantes.h"
#include "constantes.h"

tipoPergunta lePergunta()  //Esta funcao ira criar designacao automatica,perguntar o tipo da prova(1,2,3,4),
// em seguida pede para inserir a pergunta, as respostas e escolher a correta
{
    int typePergunta;
    tipoPergunta pergunta;
    //tipoPergunta.respostas.a;
    //  tipoRespostasPergunta respostaPergunta;
    char respostaCorreta;

    typePergunta=lerInteiro("\nTipo da pergunta:\n(1)Estrutura de Controlo\n(2)Vetor\n(3)Ponteiro\nopcao--->",1,3);
    switch(typePergunta)                          //Guarda na estrutura o tipo de pergunta
    {
    case 1:
        strcpy(pergunta.tipoPergunta,"EstruturaDeControlo");
        break;

    case 2:
        strcpy(pergunta.tipoPergunta,"Vetor");
        break;

    case 3:
        strcpy(pergunta.tipoPergunta,"Ponteiro");
        break;
    }

    lerString("\nIntroduza a pergunta:",pergunta.questao,DIM_PERGUNTA);

//    tipoPergunta.respostas=leResposta();
    lerString("\nIntroduza a resposta para 'a':",pergunta.respostas.a,30);
    lerString("\nIntroduza a resposta para 'b':",pergunta.respostas.b,30);
    lerString("\nIntroduza a resposta para 'c':",pergunta.respostas.c,30);
    lerString("\nIntroduza a resposta para 'd':",pergunta.respostas.d,30);
    do
    {
        printf("Introduza a resposta correta:");
        scanf("%c",&respostaCorreta);
        limpaBufferStdin();

        if (respostaCorreta!='a' && respostaCorreta!='b' && respostaCorreta!= 'c' && respostaCorreta!= 'd')
        {
            printf("\n***!!opcao invalida!!***\n");
        }
    }
    while(respostaCorreta!='a' && respostaCorreta!='b' && respostaCorreta!= 'c' && respostaCorreta!= 'd');

    pergunta.respostasCorreta=respostaCorreta;

    pergunta.prova=lerInteiro("Insira a prova(1,2,3,4) a que deseja inserir as perguntas:",1,4);

    return pergunta;
}// FIM LEPERGUNTA


void acrescentaPergunta(tipoPergunta vPerguntas[MAX_PERGUNTAS], int *quantidadePerguntas)
{

    tipoPergunta pergunta;

    if(*quantidadePerguntas>= MAX_PERGUNTAS)
    {
        printf("***Foi atingido o maximo de perguntas possiveis a adicionar!***");
    }
    else
    {
        if (*quantidadePerguntas==0)
        {
            vPerguntas[*quantidadePerguntas].design = 1;
            pergunta=lePergunta();
            pergunta.design= vPerguntas[*quantidadePerguntas].design;
            vPerguntas[*quantidadePerguntas]=pergunta;
            (*quantidadePerguntas)++;
        }

        else
        {
            vPerguntas[*quantidadePerguntas].design = vPerguntas[*quantidadePerguntas-1].design+1;
            pergunta=lePergunta();
            pergunta.design= vPerguntas[*quantidadePerguntas].design;
            vPerguntas[*quantidadePerguntas]=pergunta;
            (*quantidadePerguntas)++;

        }
    }
}// FIM acrescentaPergunta

int funcaoMenuPergunta()
{
    int opcao;
    do
    {
        printf("\n\n-----------MENU(Perguntas)---------\n");
        printf("(1)Acrescentar Pergunta\n");
        printf("(2)Mostrar dados das Perguntas\n");
        printf("(3)Procura Pergunta\n");
        printf("(4)Elimina pergunta\n");
        printf("(5)Voltar menu principal\n");
        printf("\tOpcao--> ");
        scanf("%d", &opcao);

        if(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5)
        {
            printf("Opcao invalida!!\n");
        }
        limpaBufferStdin();
    }
    while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5);

    return opcao;
}


void mostrarDadosDasPerguntas(tipoPergunta vPerguntas[MAX_PERGUNTAS],int quantidade)
{
    int i;

    if (quantidade==0)
    {

        printf("ERROR: Nao ha perguntas introduzidas\n");

    }
    else
    {
        printf("\ndesignacao  Questao                          Respostas                         RespostaCorreta      TipoDaPergunta        NºProva \n");
        // printf("                                             a-                                                                 ");

        for (i=0; i<quantidade; i++)
        {
            printf("%-11d %-30s   a-%-30s          %c            %-20s       %d\n",vPerguntas[i].design,vPerguntas[i].questao,vPerguntas[i].respostas.a,
                   vPerguntas[i].respostasCorreta,vPerguntas[i].tipoPergunta,vPerguntas[i].prova);
            printf("                                             b-%s\n",vPerguntas[i].respostas.b);
            printf("                                             c-%s\n",vPerguntas[i].respostas.c);
            printf("                                             d-%s\n",vPerguntas[i].respostas.d);
            printf("__________________________________________________________________________________________________________________________________\n");

        }//for


    }


}//FIM DO mostraDadosDasPerguntas()

int procuraPergunta(int numero, tipoPergunta vPerguntas[MAX_PERGUNTAS], int quantidade)
{
    int i, posicao=-1;

    for(i=0; i<quantidade; i++)
    {
        if (numero==vPerguntas[i].design)
        {
            printf("\ndesignacao  Questao                          Respostas                         RespostaCorreta      TipoDaPergunta        NºProva \n");
            printf("%-11d %-30s   a-%-30s          %c            %-20s       %d\n",vPerguntas[i].design,vPerguntas[i].questao,vPerguntas[i].respostas.a,
                   vPerguntas[i].respostasCorreta,vPerguntas[i].tipoPergunta,vPerguntas[i].prova);
            printf("                                             b-%s\n",vPerguntas[i].respostas.b);
            printf("                                             c-%s\n",vPerguntas[i].respostas.c);
            printf("                                             d-%s\n",vPerguntas[i].respostas.d);
            posicao = i;
            i=quantidade;
        }
    }

    return posicao;
}//FIM procuraPergunta


int eliminaPergunta(tipoPergunta vPerguntas[MAX_PERGUNTAS], int quantidade)
{
    int codigoEliminar, posicao=-1,confirm;

    if (quantidade==0)
    {
        printf("\n\n ------ Nao existem Perguntas ------\n\n");
    }
    else
    {
        codigoEliminar = lerInteiro("Qual é a pergunta que pretende eliminar?\n", 1, MAX_PERGUNTAS);
        posicao = procuraPergunta(codigoEliminar,vPerguntas,quantidade);            //Procura no vetor se existe a pergunta//
        if (posicao == -1)                                                            // se posição==-1 não existe//
        {
            printf("\n---- Nao existe essa pergunta ----\n");
        }
        else
        {
          confirm=lerInteiro("\nPretende eliminar esse aluno?\n1-Sim  2-Nao\n",1,2);

          if(confirm ==1)                                                           //Confirma se pretende eliminar a pergunta ou nao //
          {
              for (int i=posicao; i<quantidade-1; i++)                             //Move todos os elementos do vetor uma unidade para tras//
            {
                vPerguntas[i] = vPerguntas[i+1];
            }
            quantidade--;
          }

        }
    }

    return quantidade;
}//FIM eliminaEstudante//

void gravaFicheiroPerguntas_Binario(tipoPergunta vPerguntas[], int quantidade)
{

    FILE *ficheiro;
    int escrito;

    ficheiro =fopen("Perguntas.dat","wb");

    if (ficheiro == NULL)
    {
        printf("Erro ao gravar o ficheiro\n");
    }
    else
    {
        //abriu ficheiro com sucesso
        escrito = fwrite(&quantidade, sizeof(int),1,ficheiro);
        if (escrito!=1)
        {
            printf("Erro ao escrever a quantidade de reservas\n");
        }
        else
        {
            escrito = fwrite(vPerguntas, sizeof(tipoPergunta), quantidade, ficheiro);
            if (escrito!=quantidade)
            {
                printf("Erro ao escrever info das Perguntas\n");
            }
            else
                printf("Perguntas Gravadas com sucesso\n");
        }
        fclose(ficheiro);
    }

}//FIM gravaFicheiroPergunta_Binario

void leFicheiroPergunta_Binario(tipoPergunta vPerguntas[], int *quantidade)
{

    FILE *ficheiro;
    int lido;

    *quantidade = 0;

    ficheiro =fopen("Perguntas.dat","rb");

    if (ficheiro == NULL)
    {
        printf("Erro ao abrir o ficheiro\n");

    }
    else //abriu ficheiro com sucesso
    {
        lido = fread(quantidade, sizeof(int),1,ficheiro);
        if (lido!=1)
        {
            printf("Erro ao ler a quantidade de Perguntas\n");
            *quantidade = 0;
        }
        else
        {
            lido = fread(vPerguntas, sizeof(tipoPergunta),*quantidade, ficheiro);
            if (lido!=(*quantidade))
            {
                printf("Erro ao ler a info das Perguntas\n");
                *quantidade = 0;
            }
        }
        fclose(ficheiro);
    }
}//FIM leFicheiroPerguntas_Binario()



