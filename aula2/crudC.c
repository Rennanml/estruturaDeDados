#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define QTD_MAX_ALUNOS 45

int idxDispo = 0;

typedef struct
 {
    int id;
    char nome[100];
    int idade;
    char endereco[100];
 } aluno;
 
 aluno t3A[45];
 
int verificar_id(int id_read){
    for (int i = 0; i < idxDispo; i++)
    {
        if (id_read == t3A[i].id)
        {
            return 1;
        }
    }
    return 0;
}

int cadastrar() {
    int id_read;
    if (idxDispo < QTD_MAX_ALUNOS)
    {
        printf("Digite o valor do id: ");
        scanf("%d%*c", &id_read);
        if (!verificar_id(id_read))
        {
            t3A[idxDispo].id = id_read;
            printf("Digite o nome do aluno: ");
            gets(t3A[idxDispo].nome);
            printf("Digite a idade do aluno: ");
            scanf("%d%*c", &t3A[idxDispo].idade);
            printf("Digite o endereco do aluno: ");
            gets(t3A[idxDispo].endereco);
            idxDispo++;
            return 1;
        }
    }
    return 0;
}

int remover(int remove_index){
    for (int i = 0; i < idxDispo; i++)
	{
		if (t3A[i].id == remove_index)
		{
			for (int j = 0; j < idxDispo; j++)
			{
				t3A[i] = t3A[i + 1];
			}
			idxDispo--;
			return 1;
		}
	}
    return 0;
}

int atualizar(int att_index){
	for (int i = 0; i < idxDispo; i++)
	{
		if (t3A[i].id == att_index)
		{
			printf("Digite o nome do aluno: ");
            gets(t3A[i].nome);
            printf("Digite a idade do aluno: ");
            scanf("%d%*c", &t3A[i].idade);
            printf("Digite o endereco do aluno: ");
            gets(t3A[i].endereco);
            return 1;
		}
	}
    return 0;
}

void mostrar_alunos(){
	if (idxDispo == 0)
	{
		printf("Nao existem alunos cadastrados.\n");
		return;
	}
    printf("---=+ Alunos +=---\n");
    for (int i = 0; i < idxDispo; i++)
    {
        printf("Aluno %s\n", t3A[i].nome);
        printf("ID: %d\n", t3A[i].id);
        printf("Idade %d\n", t3A[i].idade);
        printf("Endereco: %s\n", t3A[i].endereco);
    }
    printf("\n");
}
    
int main(int argc, char const *argv[])
{
    int crud;int remove_index;int att_index;
    while (1)
    {
        do
        {
            printf("O que deseja fazer?\n");
            printf("1 - Cadastrar\n");
            printf("2 - Remover\n");
            printf("3 - Atualizar\n");
            printf("4- Mostrar alunos\n");
            printf("5 - Sair\n\n");
            scanf("%d", &crud);

        } while (crud <= 0 || crud > 5);
        
        switch (crud)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            printf("Digite o ID do aluno que deseja remover: ");
            scanf("%d%*c", &remove_index);
            printf("\n");
            if (remover(remove_index))
            {
                printf("Aluno removido com sucesso.\n");
            }else printf("Erro ao remover");
            break;
        case 3:
            printf("Digite o ID do aluno que deseja atualizar: ");
            scanf("%d%*c", &att_index);
            printf("\n");
            if (atualizar(att_index))
            {
                printf("Aluno atualizado com sucesso!\n");
            }else printf("Erro ao atualizar aluno!\n");
            break;
        case 4:
            mostrar_alunos();
            break;
        case 5:
            printf("Fim da execucao");
			return 0;
        }
    }
    printf("Nao era pra chegar aqui...");
    return 0;
}
