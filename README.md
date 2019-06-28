# Criptografia RSA
Conjunto de programas escritos em linguagem C para enviar e receber mensagens criptografadas de texto ASCII. Feito para fins educacionais, não utilize em um sistema sério de criptografia.

## How to compile:
* Clone the repository with `git clone https://github.com/Delpreti/CriptoRSA`
* CD into the new directory with `cd CriptoRSA`
* Compile with `gcc encript.c -o encriptar -Wall`, `gcc show.c -o ler -Wall`, `gcc decript.c -o descriptar -Wall`

## How to use:
Os arquivos `encriptar`, `ler` e `descriptar` aqui disponiveis já se encontram compilados e prontos para uso.
* Para encriptar uma mensagem: Basta escrever a mensagem como argumento para a funcao encriptar diretamente.
* A funcao ler apenas exibe o conteúdo encriptado do arquivo binário para fins didáticos.
* Para desencriptar uma mensagem: Basta chamar a funcao descriptar e a mensagem será exibida na tela.
