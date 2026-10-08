/*
================================================================================
RESPOSTA SOBRE O OPERADOR TERNÁRIO E IF ANINHADO:
O operador ternário (?:) foi mais vantajoso no cálculo do bônus de pontualidade 
por se tratar de uma atribuição direta de valor baseada em uma condição binária 
simples ('S' ou 'N'), mantendo o código conciso em apenas uma linha. Já o if 
aninhado tornou-se indispensável na análise do desconto acadêmico, pois foi 
necessário avaliar a média do aluno somente após determinar a sua faixa social, 
criando uma dependência hierárquica entre duas variáveis distintas.
================================================================================
*/

#include <stdio.h>
#include <string.h>

int main() {
    char nome[100];
    int idade;
    float renda;
    float media;
    char pontualidade;

    char faixa_social[20];
    float desconto_base = 0.0;
    float bonus_pontualidade = 0.0;
    float desconto_total = 0.0;

    // Leitura dos dados de entrada
    printf("Digite o nome completo do aluno: ");
    fgets(nome, sizeof(nome), stdin);
    // Remove a quebra de linha tratada pelo fgets
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite a idade do aluno: ");
    scanf("%d", &idade);

    printf("Digite a renda familiar mensal (R$): ");
    scanf("%f", &renda);

    // 1. Validação de Entrada
    if (idade < 16 || renda <= 0) {
        printf("\n[ERRO] Dados invalidos! Idade deve ser >= 16 e renda > 0.\n");
        return 1;
    }

    printf("Digite a media academica (0.0 a 10.0): ");
    scanf("%f", &media);

    printf("Status de pontualidade no pagamento (S/N): ");
    scanf(" %c", &pontualidade);

    // 2. Classificação da Faixa Social e 3. Análise de Desconto (if aninhado)
    if (renda <= 2000.0) {
        strcpy(faixa_social, "Faixa A");
        if (media >= 8.5) {
            desconto_base = 50.0;
        } else {
            desconto_base = 30.0;
        }
    } else if (renda <= 5000.0) {
        strcpy(faixa_social, "Faixa B");
        if (media >= 9.0) {
            desconto_base = 25.0;
        } else {
            desconto_base = 10.0;
        }
    } else {
        strcpy(faixa_social, "Faixa C");
        if (media >= 9.5) {
            desconto_base = 10.0;
        } else {
            desconto_base = 0.0;
        }
    }

    // 4. Bônus de Pontualidade utilizando obrigatoriamente Operador Ternário
    bonus_pontualidade = (pontualidade == 'S' || pontualidade == 's') ? 5.0 : 0.0;

    // 5. Cálculo Final
    desconto_total = desconto_base + bonus_pontualidade;

    // Exibição da Saída Formatada
    printf("\n========================================\n");
    printf("   SISTEMA DE AVALIACAO DE DESCONTO\n");
    printf("========================================\n");
    printf("Aluno         : %s\n", nome);
    printf("Faixa Social  : %s\n", faixa_social);
    printf("Média         : %.2f\n", media);
    printf("Desconto Base : %.1f%%\n", desconto_base);
    printf("Bônus Pontual : %.1f%%\n", bonus_pontualidade);
    printf("----------------------------------------\n");
    printf("Desconto Total: %.1f%%\n", desconto_total);
    printf("Status        : %s\n", (desconto_total > 0) ? "APROVADO PARA BOLSA" : "SEM DESCONTO");
    printf("========================================\n");

    return 0;
}