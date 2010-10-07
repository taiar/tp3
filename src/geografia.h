/*
 * geografia.h
 *
 *  Created on: 06/10/2010
 *      Author: taiar
 */

#ifndef GEOGRAFIA_H_
#define GEOGRAFIA_H_

#include "grafo.h"

/**
 * Definições padrões do número de capitais e regiões do Brasil.
 */
#define N_CIDADES 27
#define N_MAX_CHAR_CIDADES_NAME 16
#define N_REGIOES 5
#define N_MAX_CIDADES_REGIAO 9

/**
 * Vetor que armazena os nomes das capitais do Brasil em ordem alfabética.
 */
static char cidades[N_CIDADES][N_MAX_CHAR_CIDADES_NAME] =
{ "aracaju", "belem", "belohorizonte", "boavista", "brasilia", "campogrande",
    "cuiaba", "curitiba", "florianopolis", "fortaleza", "goiania",
    "joaopessoa", "macapa", "maceio", "manaus", "natal", "palmas",
    "portoalegre", "portovelho", "recife", "riobranco", "riodejaneiro",
    "salvador", "saoluis", "saopaulo", "teresina", "vitoria" };

/**
 * Vetor que especifica à qual região do Brasil cada capital pertence.
 */
static int regioes[N_REGIOES][N_MAX_CIDADES_REGIAO] =
{
  //Centro-oeste
  { 6, 5, 10, 4, -1, -1, -1, -1, -1 },
  //Nordeste
  { 13, 22, 9, 23, 11, 19, 25, 15, 0 },
  //Norte
  { 20, 12, 14, 1, 18, 3, 16, -1, -1 },
  //Sudeste
  { 26, 2, 21, 24, -1, -1, -1, -1, -1 },
  //Sul
  { 7, 8, 17, -1, -1, -1, -1, -1, -1 } };

/**
 * Retorna índice único da cidade.
 */
int cidadeGetIndice(char*);

/**
 * Retorna região da cidade.
 */
int cidadeGetRegiao(int);

#endif /* GEOGRAFIA_H_ */
