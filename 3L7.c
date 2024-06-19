#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SUCESSO 0
#define sobrecarga (1)
#define tam_max (100 + sobrecarga)

#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

void util_removeQuebraLinhaFinal(char texto[]) {
  
  int tamanho = strlen(texto);
  
  if ((tamanho > 0) && (texto[tamanho -1] == '\n')) {
    texto[tamanho - 1] = '\0';
  }  
}

// Lista de vogais
static const char LISTA_VOGAIS[] = {'A','a','E','e','I','i','O','o','U','u'};

bool ehVogal(char letra) {

  unsigned int i;

  for (i = 0; i < sizeof(LISTA_VOGAIS); i++) {
    if (letra == LISTA_VOGAIS[i]) return true;
  }

  // Se chegou até aqui é porque não encontrou
  return false;
}

unsigned int contaVogais(char texto[]) {
  
  int i;
  unsigned int nVogais = 0;
  
  // Conta o número de vogais
  for (i = 0; i < strlen(texto); i++) {
    if (ehVogal(texto[i])) {
      nVogais++;
    }
  }
  
  // Retorna a quantidade de vogais encontradas
  return nVogais;
}

int main(int argc, char **argv) {
    char string[tam_max];
    unsigned int n_Vogais;

    printf("Digite o texto a ser analisado:\n");
    fgets(string, tam_max, stdin);
    util_removeQuebraLinhaFinal(string);

    n_Vogais = contaVogais(string);

    printf("O texto digitado possui ");
    PRINTF("%u", n_Vogais);
    printf(" vogal(is).\n");
  
  return SUCESSO;
}