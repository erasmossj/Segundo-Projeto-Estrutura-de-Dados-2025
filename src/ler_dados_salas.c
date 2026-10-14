#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ler_dados_salas.h"

Sala* carregarDadosSalas(void)
{
    FILE *arquivo = fopen("salas.txt", "rb");
    Sala *newSala = NULL;

    char getLinha[100];
    memset(getLinha, 0, sizeof(getLinha));

    while (fgets(getLinha, sizeof(getLinha), arquivo) != NULL)
    {
        Sala *new_sala = (Sala*)calloc(1, sizeof(Sala));
        char *token = strtok(getLinha, ";");

        strcpy(new_sala->nome_sala, token);
        
        token = strtok(NULL, ";");
        new_sala->capacidade = atoi(token);

        token = strtok(NULL, ";");
        strcpy(new_sala->tipo_sala, token);

        new_sala->proxima = newSala;
        newSala = new_sala;

        memset(getLinha, 0, sizeof(getLinha));
    }

    fclose(arquivo);

    return newSala;
}
