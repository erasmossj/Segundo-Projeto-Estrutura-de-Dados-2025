#ifndef CONFLITO_HORARIOS_H
#define CONFLITO_HORARIOS_H

#include <stdbool.h>

#include "estruturas.h"

/* Retorna true se o horário de novaMateria não conflita com nenhuma da lista. */
bool verificarDisponibilidadeHorario(No *lista_de_materias, Materias novaMateria);

#endif
