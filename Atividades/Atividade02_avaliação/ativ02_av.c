#include <stdio.h>
#include <string.h>

int main() {

    char cliente[100];
    char produto[100];
    char categoria;
    int codigo;
    int qtd;
    float preco_unitario;
    float total;

    printf("Nome completo do cliente: ");
    fgets(cliente, sizeof(cliente), stdin);
    cliente[strlen(cliente) - 1] = '\0';

    printf("Codigo do produto: ");
    scanf("%d", &codigo);

    while (getchar() != '\n');

    printf("Nome do produto: ");
    fgets(produto, sizeof(produto), stdin);
    produto[strlen(produto) - 1] = '\0';

    printf("Quantidade: ");
    scanf("%d", &qtd);

    printf("Preço unitário: ");
    scanf("%f", &preco_unitario);

    while (getchar() != '\n');

    printf("Categoria (A, B, C ou D): ");
    scanf("%c", &categoria);

    total = qtd*preco_unitario;

    printf("\n========================================\n");
    printf("           RECIBO DE COMPRA\n");
    printf("========================================\n");
    printf("%-12s: %s\n", "Cliente", cliente);
    printf("%-12s: %s\n", "Produto", produto);
    printf("%-12s: %d\n", "Codigo", codigo);
    printf("%-12s: %c\n", "Categoria", categoria);
    printf("%-12s: %d\n", "Qtd", qtd);
    printf("%-12s: R$ %.2f\n", "Unitario", preco_unitario);
    printf("%-12s: R$ %.2f\n", "Total", total);
    printf("========================================\n");

    return 0;

    /*
O scanf("%s") lê apenas uma palavra e para quando encontra um espaço.
Por isso, ele não lê corretamente nomes compostos.
Por exemplo, "Maria Souza" seria lido só como "Maria".
Para evitar esse problema, o programa utiliza fgets().
O fgets() permite ler uma string contendo espaços.
Depois da leitura, o programa remove o \n deixado pelo fgets().
Assim, o nome completo pode ser armazenado e exibido corretamente.
*/



}
