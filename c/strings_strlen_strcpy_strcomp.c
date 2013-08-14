/**
 * strlen, strcpy, strcomp
 */
#include <stdio.h>
#include <string.h>

int main()
{

	char string[150], letras[150];
	int tamanho = 0;

	puts("Digite uma frase");

	while ((string[tamanho] = getchar()) != '\n') {
		tamanho++;
	}
	string[tamanho] = '\0';

	puts("A frase digitada é:");
	puts(string);

	puts("A frase tem tamnho de:");
	printf("%un\n", strlen(string));

	puts("Digite uma outra frase:");
	gets(letras);

	puts("A nova frase tem");
	printf("%u caracteres;\n", strlen(letras));

	if(strcomp(string, letras))
		puts("A primeira frase é diferente da segunda");
	else
		puts("A primeira frase é igual à segunda");


	puts("string original:");
	puts(string);

	strcpy(string, letras);

	puts("string nova:");
	puts(string);

	return 0;
}