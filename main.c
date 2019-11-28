#include <stdio.h>
#include <math.h>
#include <locale.h>
/*
Função                          Descrição do comando
sqrt( )                         Calcula raiz quadrada
pow(variável, expoente)         potenciação
sin( )                          seno
cos( )                          cosseno
tan( )                          Tangente
log( )                          logaritmo natural
log10( )                        logaritmo base 10

Número de Euler                 M_E
Logaritmo de e na base 2        M_LOG2E
Logaritmo de e na base 10       M_LOG10E
Logaritmo neperiano ou natural  M_LN10
Pi                               M_PI
*/

float f(float x) {
   return pow(x,2)-5*x+6;
}

float fdx(float x) {
   return 2*x-5; // derivada de f(x).
}

int main() {

    setlocale(LC_ALL,"");

    double erro, valorInicial, *interacoes;
    int i=0, numeroInteracoes;

    printf("DIGITE O ERRO: \n");
    scanf("%lf",&erro);

    printf("DIGITE O NUMERO MAXIMO DE INTERACOES\n");
    scanf("%d", &numeroInteracoes);

    printf("DIGITE O VALOR INICIAL: ");
    scanf("%lf", &valorInicial);

    interacoes = malloc(sizeof(float) * numeroInteracoes);
    interacoes[0] = valorInicial;

    while(f(interacoes[i]) > erro) {
        if(i > numeroInteracoes) {
            printf("NUMERO DE INTERACOES = %d\n NAO CONVERGE \n", numeroInteracoes);
        }
        interacoes[i+1] = interacoes[i] - f(interacoes[i])/fdx(interacoes[i]);
        i++;
    }

    printf("X ~= %lf ", interacoes[i]);
    printf("\n %d INTERACOESn",i);
}
