#include <stdio.h>

char validarSexo() {
    char sexo;
    do {
        printf("Informe o sexo (m/f): ");
        scanf("%c", &sexo);
    } while (sexo != 'm' && sexo != 'f');
    return sexo;
}

float validarSalario() {
    float salario;
    do {
        printf("Informe o salario: R$ ");
        scanf("%f", &salario);
    } while (salario <= 1.0);
    return salario;
}

char* classificaSalario(float salario, float salarioMinimo) {
    if (salario > salarioMinimo) {
        return "Acima do salario minimo!";
    } else if (salario < salarioMinimo) {
        return "Abaixo do salario minimo!";
    } else {
        return "Igual ao salario minimo!";
    }
}

void mostraClassifica(char sexo, float salario, float salarioMinimo) {
    printf("\n Sexo: %s", (sexo == 'm') ? "Masculino" : "Feminino");
    printf("\n Salario: R$ %.2f", salario);
    printf("\n Classificação: %s", classificaSalario(salario, salarioMinimo));
}

int main() {
    float salarioMinimo = 1400.00;
    int abaixoSalarioMinimo = 0, acimaSalarioMinimo = 0;
    char continuar;

    do {
        printf("\n Assalariado: \n");

        char sexo = validarSexo();
        float salario = validarSalario();

        mostraClassifica(sexo, salario, salarioMinimo);

        if (salario < salarioMinimo) {
            abaixoSalarioMinimo++;
        } else {
            acimaSalarioMinimo++;
        }

        printf("\n Deseja cadastrar outro assalariado? (s/n): ");
        scanf("%c", &continuar);

    } while (continuar == 's');


    printf("\n Assalariados com salario abaixo minimo: %d", abaixoSalarioMinimo);
    printf("\n Assalariados com salario acima do minimo: %d \n", acimaSalarioMinimo);

    return 0;
}