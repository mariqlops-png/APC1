/*
Por que char nome[50] armazena no maximo 49 caracteres uteis?
O vetor possui 50 posicoes, mas uma delas e reservada para '\0'.
Esse caractere indica o final de uma string em linguagem C.
Em int M[3][4], o primeiro indice representa a linha.
O segundo indice representa a coluna da matriz.
A linguagem C organiza os elementos em memoria contigua.
A organizacao ocorre por linhas, da primeira ate a ultima.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int opcao;
    int i, j;
    int quantidade;
    int maior_indice;

    char alunos[5][50];

    float notas_finais[5];
    float boletim[3][4];

    float soma;
    float media;
    float maior;

    do {
        printf("\n===== SISTEMA DE GESTAO ACADEMICA =====\n");
        printf("1 - Cadastrar Lista de Alunos\n");
        printf("2 - Estatisticas de Desempenho\n");
        printf("3 - Matriz de Notas da Turma\n");
        printf("4 - Consultar Aluno em Destaque\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");

        scanf("%d", &opcao);
        while (getchar() != '\n');

        switch (opcao) {

            case 1:
                printf("\n=== CADASTRO DE ALUNOS ===\n");

                for (i = 0; i < 5; i++) {
                    printf("Digite o nome do aluno %d: ", i + 1);

                    fgets(alunos[i], sizeof(alunos[i]), stdin);

                    alunos[i][strcspn(alunos[i], "\n")] = '\0';
                }

                printf("\n=== LISTA DE ALUNOS ===\n");

                for (i = 0; i < 5; i++) {
                    printf("%d - %s\n", i + 1, alunos[i]);
                }

                break;

            case 2:
                printf("\n=== ESTATISTICAS DE DESEMPENHO ===\n");

                soma = 0;
                quantidade = 0;

                for (i = 0; i < 5; i++) {
                    printf("Digite a nota do aluno %d: ", i + 1);
                    scanf("%f", &notas_finais[i]);

                    soma = soma + notas_finais[i];
                }

                media = soma / 5;

                for (i = 0; i < 5; i++) {
                    if (notas_finais[i] >= media) {
                        quantidade++;
                    }
                }

                printf("\nMedia geral: %.2f\n", media);
                printf("Alunos com nota maior ou igual a media: %d\n",
                       quantidade);

                break;

            case 3:
                printf("\n=== MATRIZ DE NOTAS DA TURMA ===\n");

                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 4; j++) {
                        printf("Aluno %d - Bimestre %d: ",
                               i + 1, j + 1);

                        scanf("%f", &boletim[i][j]);
                    }
                }

                printf("\n=== BOLETIM DA TURMA ===\n");

                printf("Aluno\tB1\tB2\tB3\tB4\tMedia\n");

                for (i = 0; i < 3; i++) {
                    soma = 0;

                    printf("%d\t", i + 1);

                    for (j = 0; j < 4; j++) {
                        printf("%.1f\t", boletim[i][j]);

                        soma = soma + boletim[i][j];
                    }

                    media = soma / 4;

                    printf("%.2f\n", media);
                }

                break;

            case 4:
                printf("\n=== CONSULTAR ALUNO EM DESTAQUE ===\n");

                for (i = 0; i < 5; i++) {
                    printf("Digite a nota do aluno %d: ", i + 1);
                    scanf("%f", &notas_finais[i]);
                }

                maior = notas_finais[0];
                maior_indice = 0;

                for (i = 1; i < 5; i++) {
                    if (notas_finais[i] > maior) {
                        maior = notas_finais[i];
                        maior_indice = i;
                    }
                }

                printf("\nMaior nota: %.2f\n", maior);

                printf("Posicao no vetor: %d\n", maior_indice);

                printf("Aluno em destaque: %d\n", maior_indice + 1);

                break;

            case 0:
                printf("\nSistema encerrado.\n");

                break;

            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}