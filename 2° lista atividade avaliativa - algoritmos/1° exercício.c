#include <stdio.h>
#include <string.h>

int validaQuantidade(int quantidade);
float calculaSalario(int quantidade);
void mostraFinal(int quantidade);

int main() {
    int quantidade;
    char continuar;
    int funcionarios = 1;

    do {
        printf("Informe a quantidade de pecas fabricadas neste mes: ");
        scanf("%d", &quantidade);

        while (validaQuantidade(quantidade) == 0) {
            printf("\n Quantidade invalida :( tente novamente:");
            scanf("%d", &quantidade);
        }

        mostraFinal(quantidade);

        printf("\nDeseja processar outra quantidade? (S/N): ");
        scanf("%c", &continuar);

        funcionarios++;

    } while (continuar == 'S' || continuar == 's');

    return 0;
}

int validaQuantidade(int quantidade) {
    return quantidade >= 0;
}

float calculaSalario(int quantidade) {
    const float salarioInicial = 600.0;
    const int meta1 = 50;
    const int meta2 = 80;
    const float adicional1 = 0.50;
    const float adicional2 = 0.75;

    float salarioTotal = salarioInicial;

    if (quantidade > meta1) {
        salarioTotal += (quantidade - meta1) * adicional1;

        if (quantidade > meta2) {
            salarioTotal += (quantidade - meta2) * (adicional2 - adicional1);
        }
    }

    return salarioTotal;
}

void mostraFinal(int quantidade) {
    float salario = calculaSalario(quantidade);
    printf("\n Seu salario eh: R$%.2f \n", salario);
}