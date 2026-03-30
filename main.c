#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//char func1[] = "e^x - x�";

float recebeerro() {
    float erro;
    printf("Digite o valor do erro: ");
    scanf("%f", &erro);
    return erro;
}

float recebeA() {
    float a;
    printf("Digite o valor de A: ");
    scanf("%f", &a);
    return a;
}
/*
float recebeB() {
    float b;
    printf("Digite o valor de B: ");
    scanf("%f", &b);
    return b;
}*/

float calcularFX(float x) {
    return (pow(2.7182818284590452353602874713527, x) - (x * x));
}
float calcularFXDerivada(float x) {
    return (pow(2.7182818284590452353602874713527, x) - (2*x));
}

float calcularNovoXK(float x) {
	float r1 = calcularFX(x);
	float r2 = calcularFXDerivada(x);
	
    float resultado = x - ( r1 / r2 );
    return resultado;
}

void execucao(float x0, float erro) {
	int k=1;
	float i = x0;
	float x, novoX, fx, fxderiv;
	do
	{
		x = calcularNovoXK(i);
		fx = calcularFX(x);
		fxderiv = calcularFXDerivada(x);
		
		novoX = calcularNovoXK(x);
		i = novoX;
		
		k++;
	}while(fabs(fx) > erro && k <10000);
	
	float resultado = calcularFX(x);
	if(resultado < 0 + erro){
			printf("Raiz encontrada: %.4f com %d intera��es.\n", x, k);
	}

}

void menu() {
    float a, b, erro;
    int opcao;
    while (1) {
        printf("Escolha uma opção:\n");
        printf("\n1. Escolher chute inicial.");
        //printf("\n\n2. Escolher B.");
        printf("\n2. Rodar.");
        printf("\n3. Limpar.");
        printf("\n4. Sair.");
        scanf("%d", &opcao);		
        switch (opcao) {
            case 1:
                a = recebeA();
                break;
            case 2:
                erro = recebeerro();
                printf("Execução iniciando...");
                execucao(a, erro);
                printf("Execução finalizada.");
                break;
            case 3:
            	system("cls");
            	break;
            case 4:
                printf("\nSaindo.");
                exit(0);
                break;
            default:
            	printf("Escolh entre 1 e 4!\n");
            	break;                
        }
    }
}

int main() {
    menu();
    return 0;
}
