/**
 * Busca de um caracter dentro de uma string
 */
#include <stdio.h>

int main()
{

	char string[150], letra;
	int tamanho = 0;

	puts("Digite uma frase");

	while ((string[tamanho] = getchar()) != '\n') {
		tamanho++;
	}
	string[tamanho] = '\0';

	puts("Digite uma letra para buscá-la na frase:");
    letra = getchar();
	while (letra == '\n' || letra == '\t') {
	    letra = getchar();
	}

	for(int i = 0; string[i] != '\0'; i++) {
		if(string[i] == letra) {
			printf("%c encontrado! Está na posição %d da string\n", letra, i+1);
		}
	}

	puts("A frase digitada é:");
	puts(string);

	puts("A frase tem tamnho de:");
	printf("%d\n\n", tamanho);

	return 0;
}