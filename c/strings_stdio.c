/**
 * Leitura e escrita de strings com scanf e printf
 */
#include <stdio.h>

int main()
{

	char string[150];

	printf("Digite uma frase\n");
	scanf("%s", string);

	printf("A frase digitada é: %s\n", string);

	return 0;
}