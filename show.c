#include <stdio.h>
#include <string.h>

int main(){
    FILE *f = fopen("mensagem.bin","rb");
    if (f == NULL){
        fprintf(stderr, "Arquivo vazio\n");
        return 0;
    }
    fclose(f);
    return 0;
}
