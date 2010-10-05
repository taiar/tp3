#include "io.h"

void entradaInit(Entrada *entrada)
{
  entrada->aFlag = 0;
  entrada->bFlag = 0;
  entrada->cFlag = 0;

  entrada->entradaListaDeTextos = NULL;
  entrada->saidaMaisSimilares = NULL;
  entrada->saidaPalavrasChave = NULL;
}

int entradaLe(int argc, char** argv, Entrada *entrada)
{
  entradaInit(entrada);
  int c;
  while ((c = getopt(argc, argv, "a:b:c:")) != -1)
  {
    switch (c)
    {
      case 'a':
        entrada->aFlag = 1;
        entrada->entradaListaDeTextos = optarg;
        break;
      case 'b':
        entrada->bFlag = 1;
        entrada->saidaPalavrasChave = optarg;
        break;
      case 'c':
        entrada->cFlag = 1;
        entrada->saidaMaisSimilares = optarg;
        break;
    }
  }
  if (entrada->aFlag != 1 || entrada->bFlag != 1 || entrada->cFlag != 1)
  {
    printf(
        "Os parâmetros não foram passados corretamente na linha de comando:\n\t");
    printf(
        "%s -a <lista de textos> -b <saida das palavras chave> -c <saida textos mais similares>\n",
        argv[0]);
    return 0;
  }

  entrada->listaTextos = fopen(entrada->entradaListaDeTextos, "r");
  if (!entrada->listaTextos)
  {
    printf(
        "O arquivo passado como parâmetro de lista de textos '%s' não existe.\n",
        entrada->entradaListaDeTextos);
    return 0;
  }
  return 1;
}

int entradaReinicia(Entrada *entrada)
{
  if (entrada->listaTextos) fclose(entrada->listaTextos);
  entrada->listaTextos = fopen(entrada->entradaListaDeTextos, "r");
  if (!entrada->listaTextos)
  {
    printf("Não foi possível reiniciar a leitura da lista de textos");
    return 0;
  }
  return 1;
}

void entradaFree(Entrada *entrada)
{
  fclose(entrada->listaTextos);
}

int saidaInicia(Entrada *entrada)
{
  entrada->palavrasChave = fopen(entrada->saidaPalavrasChave, "w");
  entrada->similares = fopen(entrada->saidaMaisSimilares, "w");
  if (!entrada->palavrasChave || !entrada->similares)
  {
    printf("Não foi possível escrever os arquivos de saída. '%s' e '%s'\n",
        entrada->saidaPalavrasChave, entrada->saidaMaisSimilares);
    return 0;
  }
  return 1;
}

void saidaFree(Entrada *entrada)
{
  fclose(entrada->palavrasChave);
  fclose(entrada->similares);
}

void getToken(FILE *handle, char* string, int *next)
{
  if (feof(handle)) *next = 1;
  int count = 0;
  char buff;
  char min;
  string[0] = '\0';
  buff = getc(handle);
  while (!isalpha(buff) && !feof(handle))
    buff = getc(handle);
  while (isalpha(buff) && !feof(handle))
  {
    min = tolower(buff);
    string[count] = min;
    string[count + 1] = '\0';
    count += 1;
    buff = getc(handle);
  }
  if (count < KEYWORD_MIN_CHAR && !feof(handle)) getToken(handle, string, next);
  else return;
}
