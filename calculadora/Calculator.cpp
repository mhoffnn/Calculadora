#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

double a;
double b;
double vetor[5];
char operacao;

int main(void) {
	while(operacao != 's' && operacao != 'S'){
	menu();
	scanf(" %c", &operacao);
	calculator();
	}
	printf("Saindo, foi bom trabalhar com voce!\n");
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
			printf("Favor insira valores validos\n");
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
		printf("valor %i: ", i + 1);
		scanf(" %lf", &vetor[i]);
		result += vetor[i];
	}
	return result / 5;
}

double somaLonga(double* vetor, int tam){
	int i;
	double result = 0;
	for(i = 0; i < tam; i++){
		printf("valor %i: ", i + 1);
		scanf(" %lf", &vetor[i]);
		result += vetor[i];
	}
	return result;
}

double maior(double* vetor, int tam){
	int i;
	double result = -10001;
	printf("Insira valores entre 10.000 e -10.000\n");
	for(i = 0; i < tam; i++){
		printf("valor %i: ", i + 1);
		scanf(" %lf", &vetor[i]);
		if(vetor[i] >= result)
		result = vetor[i];
	}
	return result;
}

void menu(void){
	printf("Escolha a operacao a ser realizada:\n");
	printf("A - Soma entre 2 numeros\n");
	printf("B - Subtracao entre 2 numeros\n");
	printf("C - Divisao entre 2 numeros\n");
	printf("D - Multiplicacao entre 2 numeros\n");
	printf("E - Media entre 5 numeros\n");
	printf("F - Soma entre 5 numeros\n");
	printf("G - Maior numero decimal entre 5 numeros\n");
	printf("Para sair digite 's'\n");
}

void calculator(void){
	double resultado;
	switch(operacao){
		case 'a':
		case 'A':
			leitor();
			resultado = soma(&a, &b);
			printf("resultado = %.2lf\n\n", resultado);
			break;
			
		case 'b':
		case 'B':
			leitor();
			resultado = subtracao(&a, &b);
			printf("resultado = %.2lf\n\n", resultado);
			break;
			
		case 'c':
		case 'C':
			leitor();
			resultado = divisao(&a, &b);
			printf("resultado = %.2lf\n\n", resultado);
			break;
			
		case 'd':
		case 'D':
			leitor();
			resultado = multiplicacao(&a, &b);
			printf("resultado = %.2lf\n\n", resultado);
			break;
			
		case 'e':
		case 'E':
			resultado = media(vetor, 5);
			printf("resultado = %.2lf\n\n", resultado);
			break;
			
		case 'f':
		case 'F':
			resultado = somaLonga(vetor, 5);
			printf("resultado = %.2lf\n\n", resultado);
			break;
			
		case 'g':
		case 'G':
			resultado = maior(vetor, 5);
			printf("resultado = %.2lf\n\n", resultado);
			break;
			
		case 's':
		case 'S':
			printf("Um segundo..\n");
			break;
			
		default:
			printf("Escolha uma opcao valida, fazendo um favor!!!\n\n");
	}
}

void leitor(void){
		printf("valor 1: ");
		scanf("%lf", &a);
		printf("valor 2: ");
		scanf("%lf", &b);
 }
 
