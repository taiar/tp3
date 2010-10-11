#include "io.h"

void entradaInit(Entrada *entrada)
{
  entrada->aFlag = 0;
  entrada->bFlag = 0;
  entrada->cFlag = 0;
  entrada->dFlag = 0;
  entrada->eFlag = 0;
  entrada->fFlag = 0;

  entrada->totalDias = 0;
  entrada->diasAway = 0;

  entrada->dinheiro = 0.;
  entrada->precoKmCarro = 0.;
  entrada->precoKmAviao = 0.;

  entrada->algoritmo = NULL;
  entrada->cidadeInicio = NULL;
}

int entradaLe(int argc, char** argv, Entrada *entrada)
{
  entradaInit(entrada);
  int c;
  while ((c = getopt(argc, argv, "a:b:c:d:e:f:g:")) != -1)
  {
    switch (c)
    {
      case 'a':
        entrada->aFlag = 1;
        entrada->totalDias = atoi(optarg);
        break;
      case 'b':
        entrada->bFlag = 1;
        entrada->cidadeInicio = optarg;
        break;
      case 'c':
        entrada->cFlag = 1;
        entrada->dinheiro = atof(optarg);
        break;
      case 'd':
        entrada->dFlag = 1;
        entrada->diasAway = atoi(optarg);
        break;
      case 'e':
        entrada->eFlag = 1;
        entrada->precoKmCarro = atof(optarg);
        break;
      case 'f':
        entrada->fFlag = 1;
        entrada->precoKmAviao = atof(optarg);
        break;
      case 'g':
        entrada->gFlag = 1;
        entrada->algoritmo = optarg;
        break;
    }
  }
  if (entrada->aFlag != 1 || entrada->bFlag != 1 || entrada->cFlag != 1
      || entrada->dFlag != 1 || entrada->eFlag != 1 || entrada->fFlag != 1
      || entrada->gFlag != 1)
  {
    printf("Os parâmetros não foram passados corretamente na linha de comando:\n");
    printf("%s \n-a <Quantidade total de dias de viagem> \n-b <Cidade que começa a viagem> \n-c <Dinheiro que possuem para viajar>", argv[0]);
    printf("\n-d <Quantidade máxima de dias sem visitar alguma região do Brasil> \n-e <Preço por Km para viajar de carro> \n-f");
    printf(" <Preço por Km para viajar de avião> -g [otima|heuristica]\n");
    return 0;
  }

  if((strcmp(entrada->algoritmo, "otima") != 0) && (strcmp(entrada->algoritmo, "heuristica") != 0))
  {
    printf("O algoritmo escolhido não existe.\n");
    return 0;
  }

  entrada->distancias = fopen("distancias", "r");
  if (!entrada->distancias)
  {
    printf("O arquivo de distâncias não está correto.\n");
    return 0;
  }
  return 1;
}

void entradaFree(Entrada *entrada)
{
  fclose(entrada->distancias);
}

void entradaVerifica(Entrada *entrada)
{
  char buff[30];
  int i;

  printf("Flags: \n");
  printf("a: %d\n", entrada->aFlag);
  printf("b: %d\n", entrada->bFlag);
  printf("c: %d\n", entrada->cFlag);
  printf("d: %d\n", entrada->dFlag);
  printf("e: %d\n", entrada->eFlag);
  printf("f: %d\n", entrada->fFlag);
  printf("g: %d\n\n", entrada->gFlag);

  printf("Valores: \n");

  printf("totalDias: %d\n", entrada->totalDias);
  printf("diasAway: %d\n", entrada->diasAway);
  printf("dinheiro: %f\n", entrada->dinheiro);
  printf("precoKmCarro: %f\n", entrada->precoKmCarro);
  printf("precoKmAviao: %f\n", entrada->precoKmAviao);
  printf("cidadeInicio: %s\n", entrada->cidadeInicio);
  printf("algoritmo: %s\n", entrada->algoritmo);

  printf("primeiras 5 palavras do arquivo: ");
  for(i = 0; i < 5; i += 1)
  {
    fscanf(entrada->distancias, "%s", buff);
    printf("%s ", buff);
  }
  printf("\n\n");
}
