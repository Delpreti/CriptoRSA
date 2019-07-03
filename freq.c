#include <stdio.h>
#include <string.h>

#define SP 256

int main(int argc, char *argv[]) {
	// Verifica se o usuario inseriu alguma mensagem
	if (argc < 2) {
		fprintf(stderr, "Voce deve escrever a mensagem junto com a chamada da funcao\n");
		return -1;
	}

	// Cria um vetor nulo e guarda as frequencias nele
	int quant[SP] = {0};
    for (int i = 1; argv[i] != 0; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			quant[(int)argv[i][j]] += 1;
		}
	}

	// Imprime na tela os caracteres usados e sua frequencia
	for (int i = 0; i < SP; i++) {
		if (quant[i] > 0) {
			printf("%c - %d\n", i, quant[i]);
		}
	}

	// Finaliza o programa
    return 0;
}