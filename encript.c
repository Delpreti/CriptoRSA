#include <stdio.h>
#include <string.h>
#include <math.h>

long N = 297*349;
int Ekey = 7;
int phi = 103008;

int main(int argc, char *argv[]) {
	// Verifica se o usuario inseriu alguma mensagem
	if(argc < 2){
		fprintf(stderr, "Voce deve escrever a mensagem a ser criptografada junto com a chamada da funcao\n");
		return -1;
	}

	// Cria o arquivo onde ira escrever a mensagem criptografada
    FILE *f = fopen("mensagem.bin", "wb");
    if (f == NULL){
        fprintf(stderr, "Erro de criacao do arquivo\n");
        return -1;
    }

    // Converte os caracteres para (ASCII + 101), encripta modulo N e escreve no arquivo
    for (int i = 1; argv[i] != 0; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			long Cript = lround(pow(argv[i][j] + 101, Ekey)) % N;
			fwrite(&Cript, sizeof(Cript), 1, f);
		}
		// Refaz o espaco no final de cada palavra
		long Cspace = lround(pow(' ' + 101, Ekey)) % N;
		fwrite(&Cspace, sizeof(Cspace), 1, f);
	}

	// Finaliza o programa
	printf("Mensagem encriptada!\n");
    fclose(f);
    return 0;
}
