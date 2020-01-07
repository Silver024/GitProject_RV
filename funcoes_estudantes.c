#include <stdio.h>
#include <ctype.h>
#include "funcoes_auxiliares.h"
#include "funcoes_estudantes.h"
#include "constantes.h"
#include <string.h>           // criar uma funcao para mostrar os paramatros de uma estrutura
                            // consultar um estudante fun

tipoEstudante lerDadosEstudante()
{
    tipoEstudante estudante;
    int typeAluno,regAluno,turnoAluno;


   // estudante.numAluno=lerInteiro("\nIntroduza o numero de estudante:",1,9999); //Le o numero de estudante
    lerString("\nIntroduza o nome:",estudante.nome,MAX_NOME);

    typeAluno=lerInteiro("\ntipo de aluno\n(1)Normal\n(2)Trabalhador\n(3)Extraordinario\nopcao--->",1,3);
    switch(typeAluno) //Guarda na estrutura o tipo de aluno(Normal Trabalhador Extraordinario)
    {
    case 1:
        strcpy(estudante.alunoTipo,"Normal");
        break;

    case 2:
        strcpy(estudante.alunoTipo,"Trabalhador");
        break;

    case 3:
        strcpy(estudante.alunoTipo,"Extraordinario");
        break;
    }

    regAluno=lerInteiro("\nRegime do Aluno (1-Diurno 2-(pos-laboral) )",1,2);
    switch(regAluno)
    {
    case 1:
        strcpy(estudante.regime,"Diurno");
        turnoAluno=lerInteiro("\n Turno(1-(turno_1_Diurno) 2-(Turno_2_Diurno))",1,2);
        if(turnoAluno==1)
        {
            strcpy(estudante.turno,"turno_1_Diurno");
        }
        else
        {
            strcpy(estudante.turno,"turno_2_Diurno");
        }
        break;

    case 2:
        strcpy(estudante.regime,"pos-laboral");
        turnoAluno=lerInteiro("\n Turno(1-(turno_1_PL) 2-(Turno_2_PL))",1,2);
        if(turnoAluno==1)
        {
            strcpy(estudante.turno,"turno_1_PL");
        }
        else
        {
            strcpy(estudante.turno,"turno_2_PL");
        }
        break;
    }


    return estudante;
}//FIM DO lerDadosEstudante


void mostrarDadosEstudante(tipoEstudante vEstudantes[MAX_ALUNOS],int quantidade)
{
    int i;

    if (quantidade==0)
    {

        printf("ERROR: Nao ha estudantes inscritos\n");

    }
    else
    {
        printf("\n\nNumero  Nome                          TipoAluno      Regime      Turno \n");

        for (i=0; i<quantidade; i++)
        {
            printf("%-7d %-30s%-15s%-12s%-15s\t\n",vEstudantes[i].numAluno,vEstudantes[i].nome,vEstudantes[i].alunoTipo,vEstudantes[i].regime,vEstudantes[i].turno);

        }//for

    }


}//FIM DO mostrarDadosEstudante()

int procuraEstudante(int numero, tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade)
{
    int i, posicao=-1;

    for(i=0; i<quantidade; i++)
    {
        if (numero==vEstudantes[i].numAluno)
        {
            printf("\nNome do estudante:%s\n", vEstudantes[i].nome);
            printf("Tipo do aluno:%s\nRegime:%s\nTurno:%s\n",vEstudantes[i].alunoTipo,vEstudantes[i].regime,vEstudantes[i].turno);
            posicao = i;
            i=quantidade;
        }
    }

    return posicao;
}//FIM procuraEstudante



void acrescentaEstudante(tipoEstudante vEstudantes[MAX_ALUNOS], int *quantidade)
{
    int indice,numeroEstudante;
    tipoEstudante aluno;


    if (*quantidade == MAX_ALUNOS)
    {
        printf("Limite de alunos atingido. Nao é possivel inscrever mais estudantes!\n");
    }
    else
    {
        aluno.numAluno=lerInteiro("\nIntroduza o numero de estudante:",1,9999);
        numeroEstudante=aluno.numAluno;
        indice = procuraEstudante(aluno.numAluno, vEstudantes, *quantidade);
        if (indice!=-1)                                               //aluno existe//
        {
            printf("\n***Ja existe um estudante com esse numero!***\n");
        }
        else
        {

            aluno = lerDadosEstudante();
            aluno.numAluno= numeroEstudante;

            vEstudantes[*quantidade] = aluno;
            (*quantidade)++;
            printf("\n\n");

        }

    }

}//FIM acrescentaAvaliado//

int eliminaEstudante(tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade)
{
    int codigoEliminar, posicao=-1,confirm;

    if (quantidade==0)
    {
        printf("\n\n ------ Nao existem Estudantes ------\n\n");
    }
    else
    {
        codigoEliminar = lerInteiro("Qual é o estudante que pretende eliminar?\n", 1, 9999);
        posicao = procuraEstudante(codigoEliminar,vEstudantes,quantidade);            //Procura no vetor se existe o estudante//
        if (posicao == -1)                                                            // se posição==-1 não existe//
        {
            printf("\n---- Nao existe esse estudante ----\n");
        }
        else
        {
          confirm=lerInteiro("\nPretende eliminar esse aluno?\n1-Sim  2-Nao\n",1,2);

          if(confirm ==1)                                                           //Confirma se pretende eliminar o estudante ou nao //
          {
              for (int i=posicao; i<quantidade-1; i++)                             //Move todos os elementos do vetor uma unidade para tras//
            {
                vEstudantes[i] = vEstudantes[i+1];
            }
            quantidade--;
          }

        }
    }

    return quantidade;
}//FIM eliminaEstudante//


void gravaFicheiroEstudante_Binario(tipoEstudante vEstudantes[], int quantidade)
{

    FILE *ficheiro;
    int escrito;

    ficheiro =fopen("Estudantes.dat","wb");

    if (ficheiro == NULL)
    {
        printf("Erro ao abrir o ficheiro\n");
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
            escrito = fwrite(vEstudantes, sizeof(tipoEstudante), quantidade, ficheiro);
            if (escrito!=quantidade)
            {
                printf("Erro ao escrever info dos Estudantes\n");
            }
            else
                printf("Estudantes Gravados com sucesso\n");
        }
        fclose(ficheiro);
    }

}//FIM gravaFicheiroEstudante_Binario


void leFicheiroEstudante_Binario(tipoEstudante vEstudante[], int *quantidade)
{

    FILE *ficheiro;
    int lido;

    *quantidade = 0;

    ficheiro =fopen("Estudantes.dat","rb");

    if (ficheiro == NULL)
    {
        printf("Erro ao abrir o ficheiro\n");

    }
    else //abriu ficheiro com sucesso
    {
        lido = fread(quantidade, sizeof(int),1,ficheiro);
        if (lido!=1)
        {
            printf("Erro ao ler a quantidade de Estudantes\n");
            *quantidade = 0;
        }
        else
        {
            lido = fread(vEstudante, sizeof(tipoEstudante),*quantidade, ficheiro);
            if (lido!=(*quantidade))
            {
                printf("Erro ao ler a info dos Estudantes\n");
                *quantidade = 0;
            }
        }
        fclose(ficheiro);
    }
}//FIM leFicheiroEstudante_Binario()
int funcaoMenuAluno()
{
    int opcao;
    do{
    printf("\n\n-----------MENU(ESTUDANTE)---------\n");
    printf("(1)Acrescentar estudante\n");
    printf("(2)Mostrar dados estudantes\n");
    printf("(3)Procura estudante\n");
    printf("(4)Eliminar dados estudante\n");
    printf("(5)Voltar menu principal\n");
    printf("\tOpcao--> ");
    scanf("%d", &opcao);
        if(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
            printf("Opcao invalida!!\n");
        }
        limpaBufferStdin();
    }while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5);

    return opcao;
}
