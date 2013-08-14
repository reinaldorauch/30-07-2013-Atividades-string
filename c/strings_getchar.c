/**
 * Leitura e escrita de strings com while e getchar()
 */
#include <stdio.h>

int main()
{

	char string[150];
	int tamanho = 0;

	puts("Digite uma frase");

	while ((string[tamanho] = getchar()) != '\n') {
		tamanho++;
	}
	string[tamanho] = '\0';

	puts("A frase digitada é:");
	puts(string);

	puts("A frase tem tamnho de:");
	printf("%d\n\n", tamanho);

	return 0;
}