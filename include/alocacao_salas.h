#ifndef ALOCACAO_SALAS_H
#define ALOCACAO_SALAS_H

#include "estruturas.h"

/* Aloca as disciplinas nas salas e monta a relação sala-disciplina em *pRel. */
void AlocarSala(No *headMaterias, Sala *headSalas, RelacaoSalaMateriaProfessor **pRel);

#endif
