/**
 * Leitura e escrita de strings com gets e puts
 */
#include <stdio.h>

int main()
{

	char string[150];
	int tamanho = 0;

	puts("Digite uma frase");
	gets(string);

	tamanho = strlen(string);

	puts("A frase digitada é:");
	puts(string);

	puts("A frase tem tamnho de:");
	printf("%d\n\n", tamanho);

	return 0;
}