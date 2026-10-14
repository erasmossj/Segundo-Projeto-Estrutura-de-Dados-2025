#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ler_dados_professores.h"

Professor* carregarDadosProfessores(No *head)
{
    FILE *arquivo = fopen("professores.txt", "rb");
    Professor *newProfessor = NULL;

    char getLinha[100];
    memset(getLinha, 0, sizeof(getLinha));

    while (fgets(getLinha, sizeof(getLinha), arquivo) != NULL)
    {
        Professor *new_prof = (Professor*)calloc(1, sizeof(Professor));
        char *token = strtok(getLinha, ";");

        strcpy(new_prof->nome, token);
        
        while ((token = strtok(NULL, ";")) != NULL) 
        {
            if (strncmp(token, "AREA:", 5) == 0) 
            {
                strcpy(new_prof->titulacao, token + 5);
                new_prof->titulacao[strcspn(new_prof->titulacao, "\n")] = '\0';
                break;
            }

            No *disciplina = SearchElement(token, head);

            No *nova_disc = malloc(sizeof(No));
            *nova_disc = *disciplina;
            nova_disc->next = new_prof->lista_materias;
            new_prof->lista_materias = nova_disc;
        }

        new_prof->disciplinasMinistradas = 0;
        new_prof->lista_disciplinas_ministradas = NULL;

        new_prof->proximo = newProfessor;
        newProfessor = new_prof;

        memset(getLinha, 0, sizeof(getLinha));
    }


    fclose(arquivo);
    return newProfessor;
}
