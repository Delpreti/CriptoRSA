#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// Verifica se o usuario inseriu alguma mensagem
	if (argc < 2) {
		fprintf(stderr, "Voce deve escrever a mensagem a ser criptografada junto com a chamada da funcao\n");
		return -1;
	}

	// Cria um vetor apenas com os caracteres validos e um vetor com as frequencias
	const int SP = 280;
	char asc[SP];
	int freq[SP];
	for (int w = 0; w < SP; w++) {
		asc[w] = w;
		freq[w] = 0;
	}

    // Le a mensagem inserida e guarda no vetor a frequencia dos caracteres
    for (int i = 1; argv[i] != 0; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			for (int k = 0; k < SP; k++) { // Possivelmente redundante fazer um for aqui
				if (argv[i][j] == asc[k]) {
					freq[k] += 1;
				}
			}
		}
	}

	// Imprime na tela os caracteres usados e sua frequencia
	for (int i = 0; i < SP; i++) {
		if (freq[i] > 0) {
			printf("%c - %d\n", asc[i], freq[i]);
		}
	}

	// Finaliza o programa
    return 0;
}