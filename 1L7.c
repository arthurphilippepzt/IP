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

unsigned int contaEspacosBranco(char texto[]) {

    int i;
    unsigned int nEspacos = 0;

    // Conta o número de espaços
    for (i = 0; i < strlen(texto); i++) {
        if (texto[i] == ' ') {
            nEspacos++;
        }
    }

    // Retorna a quantidade de espaçoes em branco encontrados
    return nEspacos;
}

void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
     dados[tamanho - 1] = '\0';
    }
}


int main(int argc, char **argv) {
    char string[tam_max];
    unsigned int n_Espacos;

    printf("Digite o texto a ser analisado (Ate %d caracteres):\n", tam_max - sobrecarga);
    fgets(string, tam_max, stdin);
    util_removeQuebraLinhaFinal(string);

    n_Espacos = contaEspacosBranco(string);

    printf("O texto digitado possui ");
    PRINTF("%u", n_Espacos);
    printf(" espacos em branco.\n");

    return SUCESSO;
}