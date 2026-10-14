#ifndef LER_DADOS_MATERIAS_H
#define LER_DADOS_MATERIAS_H

#include <stdio.h>
#include "estruturas_e_funcoes.h"

/* Lê a próxima linha do arquivo; no fim do arquivo, deixa a linha vazia. */
static void lerLinha(char *linha, int tamanho, FILE *arquivo)
{
    if (fgets(linha, tamanho, arquivo) == NULL) linha[0] = '\0';
}

void associarPreReq(No *materia, No *pre_req_materia, int i) 
{
    if (materia->data->pre_req[i] == NULL) materia->data->pre_req[i] = pre_req_materia->data;
}

void associarCoReq(No *materia, No *co_req_materia) 
{
    materia->data->co_req = co_req_materia->data;
    co_req_materia->data->co_req = materia->data;
}

No* carregarDados(No *head)
{
    FILE *materias = fopen("materias.txt", "rb");

    char getLinha[200];

    lerLinha(getLinha, sizeof(getLinha), materias);

    while(strcmp(getLinha, "INICIO PRE-REQUISITOS\r\n") != 0)
    {
        No *newNode = (No*) calloc(1, sizeof(No));
        newNode->data = (Materias *)calloc(1, sizeof(Materias));
        newNode->next = NULL;

        if (strcmp("\r\n", getLinha) == 0)
        {
            lerLinha(getLinha, sizeof(getLinha), materias);
            continue;
        }

        char *dado = strtok(getLinha, ";");
        strcpy(newNode->data->cod_comp, dado);

        dado = strtok(NULL, ";");
        strcpy(newNode->data->no_comp, dado);

        dado = strtok(NULL, ";");
        strcpy(newNode->data->tipo, dado);

        dado = strtok(NULL, ";");
        char optativo[12];
        strcpy(optativo, dado);

        if (strcmp(optativo, "OPTATIVO") == 0) newNode->data->optativo = true;
        else newNode->data->optativo = false;

        dado = strtok(NULL, ";");
        strcpy(newNode->data->horario, dado);

        dado = strtok(NULL, ";");
        strcpy(newNode->data->area, dado);

        dado = strtok(NULL, ";");
        strcpy(newNode->data->area, dado);

        dado = strtok(NULL, "\r\n");
        newNode->data->periodo = atoi(dado);

        newNode->data->qntPR = -1;
        newNode->data->qntCR = -1;
        if (newNode->data->periodo != 1) newNode->data->alunosDependentes = 0;
        else newNode->data->alunosDependentes = 40;

        if (head == NULL) head = newNode;
        else
        {
            No *aux = head;
            while (aux->next != NULL) aux = aux->next;
            aux->next = newNode;
        }

        memset(getLinha, 0, sizeof(getLinha));

        lerLinha(getLinha, sizeof(getLinha), materias);
    }

    memset(getLinha, 0, sizeof(getLinha));
    lerLinha(getLinha, sizeof(getLinha), materias);
    memset(getLinha, 0, sizeof(getLinha));

    lerLinha(getLinha, sizeof(getLinha), materias);

    while (strcmp(getLinha, "FIM") != 0)
    {

        if (strcmp(getLinha, "\r\n") == 0)
        {
            lerLinha(getLinha, sizeof(getLinha), materias);
            continue;
        }

        char *dado = strtok(getLinha, ";");
        No *dependente = SearchElement(dado, head);
        dado = strtok(NULL, ";");

        while (strcmp(dado, "\r\n") != 0)
        {
            No *dependência = SearchElement(dado, head);

            dependente->data->qntPR = dependente->data->qntPR + 1;

            associarPreReq(dependente, dependência, dependente->data->qntPR);

            dado = strtok(NULL, ";");
        }

        memset(getLinha, 0, sizeof(getLinha));
        lerLinha(getLinha, sizeof(getLinha), materias);
    }
    
    No *codependente = SearchElement("COMP372", head);
    No *codependencia = SearchElement("COMP373", head);

    associarCoReq(codependente, codependencia);

    fclose(materias);

    return head;   
}

#endif