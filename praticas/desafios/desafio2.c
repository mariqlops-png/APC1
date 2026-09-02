#include <stdio.h>

int main() {
    char nome[100];
    int idade;

    printf("Digite seu nome completo: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    while (getchar() != '\n');

    printf("\n--- Dados ---\n");
    printf("Nome: %s\n", nome);
    printf("Idade: %d anos\n", idade);
    
    return 0;
}