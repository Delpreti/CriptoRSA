#include <stdio.h>
#include <string.h>

int N = 37*71;
int Ekey = 11;

// Funcao para calcular potencias modulo n
int potm(int x, int exp, int n) {
	int r = 1;
	for (; exp > 0; exp--) {
		r = (r*x)%n;
	}
	return r;
}

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
			int Cript = potm(argv[i][j] + 101, Ekey, N);
			fwrite(&Cript, sizeof(Cript), 1, f);
		}
		// Refaz o espaco no final de cada palavra
		int Cspace = potm(' ' + 101, Ekey, N);
		fwrite(&Cspace, sizeof(Cspace), 1, f);
	}

	// Finaliza o programa
	printf("Mensagem encriptada!\n");
    fclose(f);
    return 0;
}
