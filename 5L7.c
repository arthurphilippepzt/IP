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

bool verificaPalindromo(char texto[]) {
  
  // Começa palíndromo e se mantém até que alguma letra altere essa condição.
  bool ePalindromo = true;

  int posFrenteTras;
  int posTrasFrente;

  posFrenteTras = 0;

  // Começando de trás pra frente, é o início + tamanho do texto -1
  posTrasFrente = strlen(texto) - 1;

  while (posFrenteTras < posTrasFrente) {

    if (texto[posFrenteTras] != texto[posTrasFrente]) {
      ePalindromo = false;
      break;
    }

    posFrenteTras++;
    posTrasFrente--;
  }
  
  // Retorna se é palíndromo ou não
  return ePalindromo;
}

int main(int argc, char **argv) {
    char string[tam_max];
    bool ehPalindromo;

    printf("Digite o texto a ser analisado:\n");
    fgets(string, tam_max, stdin);
    util_removeQuebraLinhaFinal(string);

    ehPalindromo = verificaPalindromo(string);

    printf("A palavra <%s>, eh palindromo ?\n", string);
    PRINTF("%s", ehPalindromo ? "Sim" : "Nao");
    printf("\n");

    return SUCESSO;
}