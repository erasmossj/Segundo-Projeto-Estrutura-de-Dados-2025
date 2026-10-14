#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

/* Estruturas de dados compartilhadas e funções auxiliares de lista. */

#include <stdbool.h>

typedef struct Materias
{
    char no_comp[50];
    char cod_comp[9];
    char tipo[32];
    int periodo;
    bool optativo;
    int qntPR;
    int qntCR;
    struct Materias *pre_req[22];
    struct Materias *co_req;
    char horario[12];
    char area[11];
    int alunosDependentes;
} Materias;

typedef struct OptativasEnfase
{
    char enfase[30];
    Materias *optativas[5];
} OptativasEnfase;

typedef struct node
{
    Materias *data;;
    struct node *next;
} No;

typedef struct Professor{
    char nome[256];
    No *lista_materias;   
    char titulacao[50];
    int disciplinasMinistradas;
    No *lista_disciplinas_ministradas;
    struct Professor *proximo;
} Professor;

typedef struct Sala{
    char nome_sala[50];
    int capacidade;
    char tipo_sala[50];
    struct Sala *proxima;
} Sala;

typedef struct RelacaoSalaMateriaProfessor{
    Sala *sala;
    No *materia;
    Professor *professor;
    struct RelacaoSalaMateriaProfessor *proxima;
} RelacaoSalaMateriaProfessor;

/* Cria uma lista de disciplinas vazia. */
No* CreateNewNode(void);

/* Procura a disciplina pelo código; retorna NULL se não encontrar. */
No* SearchElement(char *cod_comp, No *head);

#endif
