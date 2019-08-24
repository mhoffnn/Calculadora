#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Estilização e perfumaria
#define CLEAR printf("\e[1;1H\e[2J")
#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define NOCOLOR "\033[0m"
#define YELLOW "\033[0;33m"
#define BYELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"

//Declaração de funções antes da main
double somaLonga(double*, int);
double maior(double*, int);
double media(double*, int);
double soma(double*, double*);
double multiplicacao(double*, double*);
double divisao(double*, double*);
double subtracao(double*, double*);
void calculator(void);
void menu(void);
void leitor(void);

//Declaração de variáveis globais
double a;
double b;
double vetor[5];
char operacao[1];

//Função principal que requisita as funções secundárias
int main(void) {
	operacao[1] = 'j';
	while(operacao[1] != 's' && operacao[1] != 'S'){
	menu();
	scanf(" %c", &operacao[1]);
	CLEAR;
	calculator();	
}
	printf(BYELLOW"Saindo, foi bom trabalhar com voce!\n");
	return 0;
}

double soma(double* a, double* b){
	return *a + *b;
}

double subtracao(double *a, double *b){
	return *a - *b;
}

double multiplicacao(double *a, double *b){
	return *a * *b;
}

double divisao(double *a, double *b){
	double result;
	do{
		if(*b == 0){
			printf(RED"Favor insira valores validos\n");
			leitor();
		}
	}while(*b == 0);
	result = *a / *b;
	return result;
}

double media(double* vetor, int tam){
	int i; 
	double result = 0;
	for(i = 0; i < tam; i++){
		printf(GREEN"valor %i: ", i + 1);
		scanf(" %lf", &vetor[i]);
		result += vetor[i];
	}
	return result / 5;
}

double somaLonga(double* vetor, int tam){
	int i;
	double result = 0;
	for(i = 0; i < tam; i++){
		printf(GREEN"valor %i: ", i + 1);
		scanf(" %lf", &vetor[i]);
		result += vetor[i];
	}
	return result;
}

double maior(double* vetor, int tam){
	int i;
	double result = -99999999;
	for(i = 0; i < tam; i++){
		printf(GREEN"valor %i: ", i + 1);
		scanf(" %lf", &vetor[i]);
		if(vetor[i] >= result)
		result = vetor[i];
	}
	return result;
}

// Função que informa o usuário as opções
void menu(void){
	printf(BYELLOW"Escolha a operacao a ser realizada:\n");
	printf(BYELLOW"A"YELLOW" - Soma entre 2 numeros\n");
	printf(BYELLOW"B"YELLOW" - Subtracao entre 2 numeros\n");
	printf(BYELLOW"C"YELLOW" - Divisao entre 2 numeros\n");
	printf(BYELLOW"D"YELLOW" - Multipliacacao entre 2 numeros\n");
	printf(BYELLOW"E"YELLOW" - Media entre 5 numeros\n");
	printf(BYELLOW"F"YELLOW" - Soma entre 5 numeros\n");
	printf(BYELLOW"G"YELLOW" - Maior numero decimal entre 5 numeros\n");
	printf(BYELLOW"Para sair digite "RED"'s'\n"NOCOLOR);
}

// Função de seleção de operação de acordo com a entrada do usuário
void calculator(void){
	double resultado;
	switch(operacao[1]){
		case 'a':
		case 'A':
			printf(MAGENTA"Voce esta realizando soma entre 2 numeros\n"NOCOLOR);
			leitor();
			resultado = soma(&a, &b);
			printf(GREEN"resultado = %.2lf\n\n"NOCOLOR, resultado);
			break;
			
		case 'b':
		case 'B':
			printf(MAGENTA"Voce esta realizando subtracao entre 2 numeros\n"NOCOLOR);
			leitor();
			resultado = subtracao(&a, &b);
			printf(GREEN"resultado = %.2lf\n\n"NOCOLOR, resultado);
			break;
			
		case 'c':
		case 'C':
			printf(MAGENTA"Voce esta realizando divisão entre 2 numeros\n"NOCOLOR);
			leitor();
			resultado = divisao(&a, &b);
			printf(GREEN"resultado = %.2lf\n\n"NOCOLOR, resultado);
			break;
			
		case 'd':
		case 'D':
			printf(MAGENTA"Voce esta realizando multiplicao entre 2 numeros\n"NOCOLOR);
			leitor();
			resultado = multiplicacao(&a, &b);
			printf(GREEN"resultado = %.2lf\n\n"NOCOLOR, resultado);
			break;
			
		case 'e':
		case 'E':
			printf(MAGENTA"Voce esta realizando a operação de media\n"NOCOLOR);
			resultado = media(vetor, 5);
			printf(GREEN"resultado = %.2lf\n\n"NOCOLOR, resultado);
			break;
			
		case 'f':
		case 'F':
			printf(MAGENTA"Voce esta realizando soma entre 5 numeros\n"NOCOLOR);
			resultado = somaLonga(vetor, 5);
			printf(GREEN"resultado = %.2lf\n\n"NOCOLOR, resultado);
			break;
			
		case 'g':
		case 'G':
			printf(MAGENTA"Voce esta verificando o maior valor entre 5 numeros\n"NOCOLOR);
			resultado = maior(vetor, 5);
			printf(GREEN"resultado = %.2lf\n\n"NOCOLOR, resultado);
			break;
			
		case 's':
		case 'S':
			printf(YELLOW"Um segundo..\n"NOCOLOR);
			break;
			
		default:
			printf(RED"Escolha uma opcao valida, fazendo um favor!!!\n\n"NOCOLOR);
	}
}

void leitor(void){
		printf(GREEN"Valor 1: "NOCOLOR);
		scanf(" %lf", &a);
		printf(GREEN"Valor 2: "NOCOLOR);
		scanf(" %lf", &b);
 }
