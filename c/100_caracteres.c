/**
 * A partir de uma frase contendo no máximo 100 caracteres inseridos via teclado (incluindo brancos),
 * escrever um algoritmo/programa para:
 *
 * a) Contar quantos espaços em branco existem na frase e quais são suas posições relativas;
 * b) Contar quantas palavras a frase tem, independentemente que sejam artigos, preposições ou pronomes;
 * c) Verificar e mostrar quais são os caracteres que se repetem na frase, quantas vezes os mesmos aparecem,
 * 	quais são eles e suas posições relativas;
 * d) Contar quantas consoantes tem a frase, quais são e as suas posições relativas;
 * e) Efetira as seguites trocas de posições dos caracteres: troque o primeiro caracter com o último,
 * 	o segundo com o penúltimo, etc..., assim sucessivamente, até o meio da frase, e mostre a mesma
 * 	modificada..
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Definindo os caracteres WhiteSpace como constantes
#define SPACE ' '
#define HTAB '\t'
#define NEWL '\n'
#define VTAB '\v'
#define FEED '\f'
#define CARR '\r'

/**
 * Função que pega do teclado uma string
 * @param  string string para ser populada
 * @return int Retorna o número de caracteres da string inputada
 */
int entra_string(char string[]) {

	char str[MAX];
	int i = 0;

	puts("------------------------------------------------------");
	puts("\tEntre com a string, com no máximo de 100 caracteres:");
	while ((str[i] = getchar()) != '\n') {
	    i++;
	}
	str[i] = '\0';

	strcpy(string, str);

	i = strlen(str);

	return i;

}

/**
 * Printa na tela do usuário o cabeçalho do programa
 * @param str string atual utilizada no programa
 */
void cabecalho_menu(char str[]) {
	int len = strlen(str);
	if(!len)
		str = "Não Inserida";
	puts("------------------------------------------------------");
	puts("\tOperações com string:");
	printf("\tString atual -->  \"%s\"\n", str);
	printf("------------------------------------------------------\n");
}

/**
 * Função placeholder para opções do menu ainda não implementadas
 */
void nao_implementado() {
	printf("------------------------------------------------------\n");
	printf("| Função não implementada ainda\n");
	printf("------------------------------------------------------\n");
}

/**
 * Para o menu
 */
void para_menu() {
	puts("\nPressione enter para continuar");
	getchar();
}

/**
 * Limpa a stream stdin
 */
void limpa_stdin(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

/**
 * Força a saída do programa
 */
void encerra_programa() {
	puts("\n Saindo....");
	exit(0);
}

/**
 * Função que retorna 1 se o caractere passado como parâmetro é um whitespace
 */
int is_whitespace(char c) {
	switch (c) {
		case SPACE:
		case HTAB:
		case NEWL:
		case VTAB:
		case FEED:
		case CARR:
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

/**
 * Conta quantos whitespaces há na string e printa na tela do usuário a quantidade e suas respectivas
 * posições
 */
void conta_espacos(char str[]) {
	int count = 0, i, pos[100], j = 0;

	for(i = 0; str[i] != '\0'; i++) {
		if(is_whitespace(str[i])) {
			if(i > 0)
				if(is_whitespace(str[i - 1]))
					continue;
			count++;
			pos[j++] = i;
		}
	}

	puts("------------------------------------------------------");
	if(count > 0) {
		printf("\tHá %d whitespaces, nas posições:", count);
		for(i = 0; i < j; i++)
			printf(" %d", (pos[i] + 1));
		putchar('\n');
	} else
		puts("\tNão há whitespaces na string atual");
	puts("------------------------------------------------------");

}

/**
 * Função que conta o número de palavras na frase
 */
void conta_palavras(char str[]) {
	int count = 0, i;

	for (i = 0; str[i] != '\0'; i++) {
		if(!is_whitespace(str[i])) {
			if(i > 0)
				if(!is_whitespace(str[i - 1]))
					continue;
			count++;
		}
	}

	puts("------------------------------------------------------");
	if(count > 0)
		printf("\tO número de palavras na frase é de %d\n", count);
	else
		puts("\tNão há palavras na frase");
	puts("------------------------------------------------------");

}

// retorna 1 se é uma consoante e 0 se não
int is_consoante(char c) {
	switch (c) {
		case 'b':
		case 'B':
		case 'c':
		case 'C':
		case 'd':
		case 'D':
		case 'f':
		case 'F':
		case 'g':
		case 'G':
		case 'h':
		case 'H':
		case 'j':
		case 'J':
		case 'k':
		case 'K':
		case 'l':
		case 'L':
		case 'm':
		case 'M':
		case 'n':
		case 'N':
		case 'p':
		case 'P':
		case 'q':
		case 'Q':
		case 'r':
		case 'R':
		case 's':
		case 'S':
		case 't':
		case 'T':
		case 'v':
		case 'V':
		case 'x':
		case 'X':
		case 'w':
		case 'W':
		case 'y':
		case 'Y':
		case 'z':
		case 'Z':
			return 1;		
		default:
			return 0;
	}
}

void conta_repetidos(char str[], int consoantes) {
	char rep[100], aux;
	int rep_c[100][2], count = 0, i, j = 0, k, l, exists = 0;

	// Itera sobre o array original para pegar samples
	for (i = 0; str[i] != '\0'; i++) {

		if(consoantes && !is_consoante(str[i]))
			continue;

		// Verifica no array de repetição se há o caractere a ser testado
		for (k = i; k >= 0; k--)	{
			if((rep[k] == str[i]) && (rep_c[k][0] >= 1)) {
				exists = 1;
				break;
			}
		}

		// Se sim, continua a verificação
		if(exists) {
			exists = 0;
			rep_c[k][0]++;
		} else {
			rep[j] = str[i];
			rep_c[j][0] = 1;
			rep_c[j][1] = i;
			j++;
		}

	}

	// ordena arrays de acordo com a quantidade de repetições
	i = j - 1;
	while (i >= 0) {
		for (l = 0; l < j - 1; l++) {

			if(rep_c[l][0] < rep_c[l + 1][0]) {

				// Trocam as poslções no array de char
				aux = rep[l];
				rep[l] = rep[l+1];
				rep[l+1] = aux;

				// Troca as poslções no array de repetição
				k = rep_c[l][0];
				rep_c[l][0] = rep_c[l + 1][0];
				rep_c[l + 1][0] = k;

				k = rep_c[l][1];
				rep_c[l][1] = rep_c[l + 1][1];
				rep_c[l + 1][1] = k;
			}

		}
		i--;
	}

	// Conta os caracteres que se repetem mais que 1 vez e acha o que tem mais repetições
	for(i = 0; i < j; i++)
		if(rep_c[i][0] > 1)
			count++;
		else if((rep_c[i][0] > 0) && consoantes)
			count++;


	// Inicia a impressão dos resultados
	puts("------------------------------------------------------");

	if(count) {

		k = (rep_c[0][0] - 2);

		if(consoantes)
			printf("\tHá %d consoantes: \n", count);
		else
			printf("\tHá a repetição de %d caracteres: \n", count);

		printf("+------+------+----------");
		for(i = 0; i < k; i++)
			printf("----");
		puts("+");

		printf("| Char | Reps | Posições ");
		for(i = 0; i < k; i++)
			printf("    ");
		puts("|");

		printf("+------+------+----------");
		for(i = 0; i < k; i++)
			printf("----");
		puts("+");

		for (i = 0; i < count; i++) {
			printf("|  \"%c\" | %4d | ", rep[i], rep_c[i][0]);

			for(j = 0; str[j] != '\0'; j++)
				if(str[j] == rep[i])
					if(consoantes && rep_c[0][0] == 1)
						printf("%7d ", j+1);
					else
						printf("%3d ", j+1);

			if(i != 0)
				for(j = ((k - rep_c[i][0]) + 2); j > 0; j--)
					printf("    ");

			puts(" |");

			printf("+------+------+----------");
			for(j = 0; j < k; j++)
				printf("----");
			puts("+");
		}

	} else
		if(consoantes)
			puts("\t Não há consoantes na frase");
		else
			puts("\t Não há caracteres repetidos");

	puts("\n------------------------------------------------------");

}

void inverte_string(char string[]) {

	char inv[MAX], aux;
	int i, j = 0;

	for(i = strlen(string); i >= 0; i--) {
		if(string[i] == '\0')
			continue;
		inv[j] = string[i];
		j++;
	}
	inv[j] = '\0';

	puts("------------------------------------------------------");

	printf("A string invertida é: %s\n", inv);

	puts("------------------------------------------------------");

}

int main() {
	
	char string[100], aux;
	int l = 0;

	string[0] = '\0';

	while(1) {

		// Limpa a tela
		system("clear");

		// Imprime o cabeçalho
		cabecalho_menu(string);

		// Verifica se já existe uma string
		if(!strlen(string)) {
			// Se não, pede ao usuário para digitá-la
			l = entra_string(string);

			continue;

		}

		// Imprime as opções do menu
		puts("Selecione uma opção:");
		puts("(1) Contar nº de espaços da frase");
		puts("(2) Contar nº de palavras da frase");
		puts("(3) Exibir caracteres que se repentem e seus respectivos nºs de repetição na frase");
		puts("(4) Contar nº de consoantes da frase, seus nºs de repetição e suas posições");
		puts("(5) Inverter string");
		puts("(6) Inserir uma nova string");
		puts("(0) Sair do programa");

		aux = getchar();
		limpa_stdin();

		switch (aux) {
			case '1':
				// Contagem de espaços
				conta_espacos(string);
				break;
			case '2':
				// Contagem de palavras
				conta_palavras(string);
				break;
			case '3':
				// Caracteres que se repetem 
				conta_repetidos(string, 0);
				break;
			case '4':
				conta_repetidos(string, 1);
				break;
			case '5':
				inverte_string(string);
				break;
			case '6':
				entra_string(string);
				break;
			case '0':
				encerra_programa();
				break;
		}

		para_menu();

	}

	return 0;
}