#ifndef ALOCACAO_PROFESSORES_H
#define ALOCACAO_PROFESSORES_H

#include "estruturas.h"

/* Procura a relação da disciplina pelo código; retorna NULL se não encontrar. */
RelacaoSalaMateriaProfessor* SearchElementRelacao(RelacaoSalaMateriaProfessor *relacao, char *codMateria);

/* Atribui um professor a cada disciplina já alocada em sala. */
void escolherProfessorMateria(RelacaoSalaMateriaProfessor *relacao, Professor *professor);

#endif
