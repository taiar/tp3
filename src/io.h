#ifndef __io__
#define __io__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

/**
 * Esta constante define o menor número de caracteres que uma palavra deve ter
 * para ser considerada no algoritmo de indexação.
 */
#define KEYWORD_MIN_CHAR 3

/**
 * Armazena dados lidos da entrada.
 */
typedef struct
{
  int aFlag, bFlag, cFlag;
  char *entradaListaDeTextos, *saidaPalavrasChave, *saidaMaisSimilares;
  FILE *listaTextos, *palavrasChave, *similares;
} Entrada;

/**
 * Seta os valores iniciais da estrutura de entrada.
 */
void entradaInit(Entrada*);

/**
 * Faz leitura dos dados de entrada e os armazena.
 */
int entradaLe(int, char**, Entrada*);

/**
 * Realoca o arquivo de lista de textos para leitura.
 */
int entradaReinicia(Entrada*);

/**
 * Libera dados utilizados na leitura da entrada.
 */
void entradaFree(Entrada*);

/**
 * Aloca arquivos de saida.
 */
int saidaInicia(Entrada*);

/**
 * Libera dados utilizados na saida do programa.
 */
void saidaFree(Entrada*);

/**
 * Lê e armazena em uma variável uma string retirada do arquivo de passado como
 * parâmetro. A string é definida arbitráriamente segundo especificação.
 * Sinaliza um flag inteiro interpretando o valor char da próxima leitura para
 * facilitar o trabalho na leitura dos arquivos.
 */
void getToken(FILE*, char*, int*);

#endif
