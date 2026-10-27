
/*
Respostas teoricas:
O menu usa do-while porque precisa aparecer pelo menos uma vez antes de verificar
se o usuario quer encerrar. No lote, continue ignora a senha negativa, evitando
que ela seja contada como atendida ou par. Se break fosse omitido na busca
prioritaria, o laco continuaria lendo senhas mesmo depois de encontrar uma
prioritaria ou receber zero, em vez de voltar ao menu.
*/

#include <stdio.h>

int main(void) {
    int opcao;

    do {
        printf("\n===== PAINEL DE SENHAS =====\n");
        printf("1 - Registrar lote\n");
        printf("2 - Simular chamadas\n");
        printf("3 - Grade de guiches\n");
        printf("4 - Buscar senha prioritaria\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

        switch (opcao) {
            case 1: {
                int senha;
                int atendidas = 0, ignoradas = 0, pares = 0;

                printf("Digite as senhas (0 para terminar):\n");
                scanf("%d", &senha);

                while (senha != 0) {
                    if (senha < 0) {
                        ignoradas++;
                        scanf("%d", &senha);
                        continue;
                    }

                    atendidas++;
                    if (senha % 2 == 0)
                        pares++;

                    scanf("%d", &senha);
                }

                printf("Atendidas : %d\n", atendidas);
                printf("Ignoradas : %d\n", ignoradas);
                printf("Pares     : %d\n", pares);
                break;
            }

            case 2: {
                int inicio, fim, passo, i, chamadas = 0;

                printf("Inicio: ");
                scanf("%d", &inicio);
                printf("Fim: ");
                scanf("%d", &fim);
                printf("Passo: ");
                scanf("%d", &passo);

                if (passo == 0) {
                    printf("Passo invalido\n");
                    break;
                }

                printf("Chamadas: ");

                if (passo > 0) {
                    for (i = inicio; i <= fim; i += passo) {
                        printf("%d ", i);
                        chamadas++;
                    }
                } else {
                    for (i = inicio; i >= fim; i += passo) {
                        printf("%d ", i);
                        chamadas++;
                    }
                }

                if (chamadas == 0)
                    printf("Nenhuma chamada");

                printf("\n");
                break;
            }

            case 3: {
                int guiches, senhas, g, s;

                printf("Guiches (1 a 4): ");
                scanf("%d", &guiches);
                printf("Senhas por guiche (1 a 5): ");
                scanf("%d", &senhas);

                if (guiches < 1 || guiches > 4 ||
                    senhas < 1 || senhas > 5) {
                    printf("Grade invalida\n");
                    break;
                }

                for (g = 1; g <= guiches; g++) {
                    printf("Guiche %d: ", g);

                    for (s = 1; s <= senhas; s++)
                        printf("%d ", s);

                    printf("\n");
                }
                break;
            }

            case 4: {
                int senha, lidas = 0;

                for (;;) {
                    printf("Senha: ");
                    scanf("%d", &senha);

                    if (senha == 0) {
                        printf("Nao encontrada\n");
                        printf("Lidas : %d\n", lidas);
                        break;
                    }

                    if (senha > 0 && senha % 10 == 0) {
                        printf("Prioritaria : %d\n", senha);
                        printf("Lidas antes : %d\n", lidas);
                        break;
                    }

                    lidas++;
                }
                break;
            }

            case 0:
                printf("Painel encerrado.\n");
                break;

            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}