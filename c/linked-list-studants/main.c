#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct aluno
{
    char matricula[10];
    char nome[40];
    float media_geral;
    Data data_nascimento;
    struct aluno *proximo;
} Aluno;

Aluno *primeiro_aluno;

void printData(Data d)
{
    printf("%d/%d/%d", d.dia, d.mes, d.ano);
}

void print_aluno(Aluno *aluno)
{
    printf("%s, ", aluno->matricula);
    printf("%s, ", aluno->nome);
    printData(aluno->data_nascimento);
    printf(", ");
    printf("%.2f\n", aluno->media_geral);
}

void add_aluno()
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    scanf("%s", &aluno->matricula);
    scanf("%s", &aluno->nome);
    scanf("%d/%d/%d", &aluno->data_nascimento.dia, &aluno->data_nascimento.mes, &aluno->data_nascimento.ano);
    scanf("%f", &aluno->media_geral);
    aluno->proximo = NULL;

    if (!primeiro_aluno)
    {
        primeiro_aluno = aluno;
    }
    else
    {
        Aluno *alunoI = primeiro_aluno;
        while (alunoI)
        {
            if (!alunoI->proximo)
            {
                alunoI->proximo = aluno;
                break;
            }
            alunoI = alunoI->proximo;
        }
    }
}

void delete_aluno_by_matricula()
{
    char matricula[10];
    scanf("%s", &matricula);
    Aluno *alunoI = primeiro_aluno;
    Aluno *prevAluno;
    while (alunoI)
    {
        if (!strcmp(alunoI->matricula, matricula))
        {
            if (alunoI == primeiro_aluno)
            {
                Aluno *aux = primeiro_aluno->proximo;
                free(alunoI);
                primeiro_aluno = aux;
            }
            else
            {
                prevAluno->proximo = alunoI->proximo;
                free(alunoI);
            }
        }
        prevAluno = alunoI;
        alunoI = alunoI->proximo;
    }
}

void print_list()
{
    Aluno *alunoI = primeiro_aluno;
    if (!primeiro_aluno) {
        printf("Lista vazia\n");
        return;
    }
    while (alunoI)
    {
        print_aluno(alunoI);
        alunoI = alunoI->proximo;
    }
}

int count_elements()
{
    int acc = 0;
    Aluno *alunoI = primeiro_aluno;
    while (alunoI)
    {
        acc++;
        alunoI = alunoI->proximo;
    }
    return acc;
}

void print_elements()
{

    printf("%d\n", count_elements());
}

void print_reverse_list()
{
    if (!primeiro_aluno) {
        printf("Lista vazia\n");
        return;
    }
    for (int i = count_elements() - 1; i >= 0; i--)
    {
        Aluno *alunoI = primeiro_aluno;
        for (int j = i - 1; j >= 0; j--)
        {
            alunoI = alunoI->proximo;
        }
        print_aluno(alunoI);
    }
}

int main()
{
    int menu;

    while (scanf("%d", &menu))
    {
        printf("%d\n", menu);
        switch (menu)
        {
        case 1:
            add_aluno();
            break;

        case 2:
            delete_aluno_by_matricula();
            break;

        case 3:
            print_list();
            break;

        case 4:
            print_reverse_list();
            break;

        case 5:
            print_elements();
            break;

        case 0:
            return 0;
        }
    };

    return 0;
}
