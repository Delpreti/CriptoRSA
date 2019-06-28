#include <stdio.h>
#include <string.h>

int main(void) {
	// Abre o arquivo com a mensagem
    FILE *f = fopen("mensagem.bin","rb");
    if (f == NULL){
        fprintf(stderr, "Erro de abertura do arquivo\n");
        return -1;
    }

    // Realiza a leitura da mensagem sem descriptografar e exibe na tela
    int Cread;
    while(feof(f) == 0) {
    	fread(&Cread, sizeof(Cread), 1, f);
    	printf("%c", Cread);
    }
    printf("\n");

    // Finaliza o programa
    fclose(f);
    return 0;
}
