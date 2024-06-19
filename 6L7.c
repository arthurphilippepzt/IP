#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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
    
    // Verifica se as posições possuem caracteres válidos (letras, não símbolos e números)
    if (!isalpha(texto[posFrenteTras])) {
      posFrenteTras++;
      continue;
    }
    if (!isalpha(texto[posTrasFrente])) {
      posTrasFrente--;
      continue;
    }

    // Se chegou até aqui, então estão comparando caracteres válidos
    // Faço a comparação sempre de minúsculo para evitar diferença entre A e a
    if (tolower(texto[posFrenteTras]) != tolower(texto[posTrasFrente])) {
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

    printf("O texto <%s>, eh palindromo ?\n", string);
    PRINTF("%s", ehPalindromo ? "Sim" : "Nao");
    printf("\n");

    return SUCESSO;
}