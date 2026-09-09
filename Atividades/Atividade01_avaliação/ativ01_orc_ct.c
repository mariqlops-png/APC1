
#include <stdio.h>

#define Valor_refeicoes 12.50 
#define Valor_cafes 4.00

int main() {

    int refeicoes;
    int cafes;
    float disponivel;
    float gasto_refeicoes;
    float gasto_cafes;
    float gasto_total;
    float saldo;

    printf("\nQuantidade de refeições: ");
    scanf("%d", &refeicoes);

    printf("\nQuantidade de cafés: ");
    scanf("%d", &cafes);

    printf("\nValor disponível no cartçao: ");
    scanf("%f" , &disponivel);
    
    printf("%f", disponivel);

    gasto_refeicoes = refeicoes*Valor_refeicoes;
    gasto_cafes = cafes*Valor_cafes;
    gasto_total = gasto_refeicoes+gasto_cafes;
    saldo = disponivel-gasto_total;

    printf("\nGasto refeições: R$ %.2f\n", gasto_refeicoes);
    printf("Gasto cafes: R$ %.2f\n", gasto_cafes);
    printf("Gasto total: R$ %.2f\n", gasto_total);
    printf("Saldo final disponível: R$ %.2f\n", saldo);


    return 0;
}