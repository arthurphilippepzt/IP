#include <stdio.h>
#include <string.h>
#define SUCESSO 0
#define sobrecarga (1)
#define tam_max (100 + sobrecarga)
/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
     dados[tamanho - 1] = '\0';
    }
}

void imprimeTextoSemEspacos(char texto[]) {
  
  int i;
  
  // Imprime todos os caracteres, exceto espaço (' ')
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { continue; }

    // Se chegou aqui, não é espaço, então imprime.
    printf("%c", texto[i]);
  }
}

int main(int argc, char **argv) {
    char string[tam_max];

    printf("Digite um texto para ser analisado(Até %d caracteres):\n", tam_max - sobrecarga);
    fgets(string, tam_max, stdin);

    util_removeQuebraLinhaFinal(string);

    imprimeTextoSemEspacos(string);

    return SUCESSO;
}