#include <stdio.h>
#include <string.h>
#include <math.h>

int N = 37*71;
int Dkey = 2291;

// Funcao para calcular potencias modulo n
int potm(int x, int exp, int n) {
	int r = 1;
	while (exp > 0){
		r *= x;
		r = r%n;
		exp--;
	}
	return r;
}

int main(void) {
	// Abre o arquivo com a mensagem
    FILE *f = fopen("mensagem.bin","rb");
    if (f == NULL){
        fprintf(stderr, "Erro de abertura do arquivo\n");
        return -1;
    }

    // Realiza a leitura da mensagem, descriptografa, e exibe na tela
    int Cread;
    while(feof(f) == 0) {
    	fread(&Cread, sizeof(Cread), 1, f);
    	int Decript = potm(Cread, Dkey, N) - 101;
    	printf("%c", Decript);
    }
    printf("\n");

    // Finaliza o programa
    fclose(f);
    return 0;
}