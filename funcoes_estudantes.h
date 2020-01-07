#ifndef FUNCOES_ESTUDANTES_H_INCLUDED
#define FUNCOES_ESTUDANTES_H_INCLUDED

tipoEstudante lerNumeroEstudante();
tipoEstudante lerDadosEstudante();
char lerTipoAluno();
void mostrarDadosEstudante (tipoEstudante vEstudantes[MAX_ALUNOS],int quantidade);
int procuraEstudante(int numero, tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade);
void acrescentaEstudante(tipoEstudante vEstudantes[MAX_ALUNOS], int *quantidade);
int eliminaEstudante(tipoEstudante vEstudantes[MAX_ALUNOS], int quantidade);
void gravaFicheiroEstudante_Binario(tipoEstudante vEstudantes[], int quantidade);
void leFicheiroEstudante_Binario(tipoEstudante vEstudante[], int *quantidade);





int funcaoMenuAluno();

#endif // FUNCOES_ESTUDANTES_H_INCLUDED
