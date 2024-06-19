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

void converteTextoIniciaisMaiusculas(char texto[]) {
  
  unsigned int i;
  bool encontrouEspaco = true;

  // Lê o texto do usuário

  // O primeiro caractere depois de espaço fica maiúsculo
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { 
      encontrouEspaco = true;
      continue; 
    }

    // Se encontrou espaço, troca para maiúscula
    if (encontrouEspaco) {
      texto[i] = toupper(texto[i]);
      encontrouEspaco = false;
    }
  }
}

int main(int argc, char **argv) {
    char string[tam_max];

    printf("Digite o texto a ser analisado:\n");
    fgets(string, tam_max, stdin);
    util_removeQuebraLinhaFinal(string);

    converteTextoIniciaisMaiusculas(string);

    printf(": ");
    PRINTF("%s", string);
    printf("\n");

    return SUCESSO;
}