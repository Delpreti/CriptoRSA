#include <stdio.h>
#include <string.h>
#include <math.h>

long N = 297*349;
int Dkey = 29431;

int main(void) {
	// Abre o arquivo com a mensagem
    FILE *f = fopen("mensagem.bin","rb");
    if (f == NULL){
        fprintf(stderr, "Erro de abertura do arquivo\n");
        return -1;
    }

    // Realiza a leitura da mensagem, descriptografa, e exibe na tela
    long Cread;
    while(feof(f) == 0) {
    	fread(&Cread, sizeof(Cread), 1, f);
    	long Decript = (lround(pow(Cread, Dkey)) % N) - 101;
    	printf("%c", (int) Decript);
    }
    printf("\n");

    // Finaliza o programa
    fclose(f);
    return 0;
}