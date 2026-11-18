
#include <stdio.h>
#include <string.h>

#define MAX 30

// --------------------------------------------------
// ENUM: Status do aluno
// --------------------------------------------------

enum StatusAluno {
    REPROVADO = 0,
    RECUPERACAO = 1,
    APROVADO = 2
};

// --------------------------------------------------
// STRUCT: Dados do aluno
// --------------------------------------------------

struct Aluno {
    int matricula;
    char nome[41];
    float a1;
    float a2;
    enum StatusAluno status;
};

// --------------------------------------------------
// FUNCAO: Calcular o status do aluno
// --------------------------------------------------

enum StatusAluno calcular_status(float media) {

    if (media >= 5) {
        return APROVADO;
    }
    else if (media >= 3) {
        return RECUPERACAO;
    }
    else {
        return REPROVADO;
    }
}

// --------------------------------------------------
// FUNCAO: Calcular a media do aluno
// --------------------------------------------------

float calcular_media(struct Aluno aluno) {

    return 0.4 * aluno.a1 + 0.6 * aluno.a2;
}

// --------------------------------------------------
// FUNCAO: Retornar o nome do status
// --------------------------------------------------

const char *nome_status(enum StatusAluno status) {

    switch (status) {

        case APROVADO:
            return "Aprovado";

        case RECUPERACAO:
            return "Recuperacao";

        case REPROVADO:
            return "Reprovado";

        default:
            return "Desconhecido";
    }
}

// --------------------------------------------------
// FUNCAO: Imprimir os dados de um aluno
// --------------------------------------------------

void imprimir_aluno(struct Aluno aluno) {

    float media = calcular_media(aluno);

    printf("%d | %s | %.2f | %.2f | %.2f | %s\n",
           aluno.matricula,
           aluno.nome,
           aluno.a1,
           aluno.a2,
           media,
           nome_status(aluno.status));
}

// --------------------------------------------------
// FUNCAO: Verificar se uma matricula ja existe
// --------------------------------------------------

int matricula_existe(struct Aluno alunos[], int quantidade, int matricula) {

    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].matricula == matricula) {
            return 1;
        }
    }

    return 0;
}

// --------------------------------------------------
// FUNCAO: Cadastrar aluno
// --------------------------------------------------

void cadastrar_aluno(struct Aluno alunos[], int *quantidade) {

    if (*quantidade >= MAX) {

        printf("\nTurma cheia! Nao ha vagas disponiveis.\n");
        return;
    }

    struct Aluno novo;
    char entrada[256];
    int valido;

    printf("\n===== CADASTRO DE ALUNO =====\n");

    // Matricula
    do {

        valido = 1;

        printf("Digite a matricula: ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return;
        }

        char extra;
        if (sscanf(entrada, "%d %c", &novo.matricula, &extra) != 1 ||
            novo.matricula <= 0) {

            printf("Matricula invalida. Digite um numero positivo.\n");
            valido = 0;
        }
        else if (matricula_existe(alunos, *quantidade, novo.matricula)) {

            printf("Essa matricula ja esta cadastrada.\n");
            valido = 0;
        }

    } while (!valido);

    // Nome
    do {

        printf("Digite o nome: ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return;
        }

        entrada[strcspn(entrada, "\n")] = '\0';

        if (strlen(entrada) == 0) {

            printf("O nome nao pode ficar vazio.\n");
        }
        else if (strlen(entrada) > 40) {

            printf("O nome deve ter no maximo 40 caracteres.\n");
        }
        else {

            strcpy(novo.nome, entrada);
            break;
        }

    } while (1);

    // Nota A1
    do {

        valido = 1;

        printf("Digite a nota A1 (0 a 10): ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return;
        }

        char extra;
        if (sscanf(entrada, "%f %c", &novo.a1, &extra) != 1 ||
            novo.a1 < 0 || novo.a1 > 10) {

            printf("Nota invalida. Digite um valor entre 0 e 10.\n");
            valido = 0;
        }

    } while (!valido);

    // Nota A2
    do {

        valido = 1;

        printf("Digite a nota A2 (0 a 10): ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            return;
        }

        char extra;
        if (sscanf(entrada, "%f %c", &novo.a2, &extra) != 1 ||
            novo.a2 < 0 || novo.a2 > 10) {

            printf("Nota invalida. Digite um valor entre 0 e 10.\n");
            valido = 0;
        }

    } while (!valido);

    // Calcular status
    novo.status = calcular_status(calcular_media(novo));

    // Adicionar aluno ao vetor
    alunos[*quantidade] = novo;

    (*quantidade)++;

    printf("\nAluno cadastrado com sucesso!\n");
}

// --------------------------------------------------
// FUNCAO: Listar todos os alunos
// --------------------------------------------------

void listar_alunos(struct Aluno alunos[], int quantidade) {

    printf("\n===== LISTA DE ALUNOS =====\n");

    if (quantidade == 0) {

        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("Matricula | Nome | A1 | A2 | Media | Status\n");

    for (int i = 0; i < quantidade; i++) {

        imprimir_aluno(alunos[i]);
    }
}

// --------------------------------------------------
// FUNCAO: Buscar aluno pela matricula
// --------------------------------------------------

void buscar_matricula(struct Aluno alunos[], int quantidade) {

    int matricula;
    char entrada[256];
    char extra;

    printf("\n===== BUSCAR POR MATRICULA =====\n");

    printf("Digite a matricula: ");

    if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
        return;
    }

    if (sscanf(entrada, "%d %c", &matricula, &extra) != 1) {

        printf("Matricula invalida.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].matricula == matricula) {

            printf("\nAluno encontrado:\n");
            printf("Matricula | Nome | A1 | A2 | Media | Status\n");

            imprimir_aluno(alunos[i]);
            return;
        }
    }

    printf("Aluno nao encontrado.\n");
}

// --------------------------------------------------
// FUNCAO: Buscar aluno por trecho do nome
// --------------------------------------------------

void buscar_nome(struct Aluno alunos[], int quantidade) {

    char trecho[41];
    int encontrados = 0;

    printf("\n===== BUSCAR POR NOME =====\n");

    printf("Digite um trecho do nome: ");

    if (fgets(trecho, sizeof(trecho), stdin) == NULL) {
        return;
    }

    trecho[strcspn(trecho, "\n")] = '\0';

    printf("\nResultados da busca:\n");

    for (int i = 0; i < quantidade; i++) {

        if (strstr(alunos[i].nome, trecho) != NULL) {

            if (encontrados == 0) {
                printf("Matricula | Nome | A1 | A2 | Media | Status\n");
            }

            imprimir_aluno(alunos[i]);

            encontrados++;
        }
    }

    if (encontrados == 0) {

        printf("Nenhum aluno encontrado.\n");
    }
}

// --------------------------------------------------
// FUNCAO: Exibir estatisticas da turma
// --------------------------------------------------

void estatisticas(struct Aluno alunos[], int quantidade) {

    int aprovados = 0;
    int recuperacao = 0;
    int reprovados = 0;

    float soma_medias = 0;
    float media_geral = 0;

    printf("\n===== ESTATISTICAS DA TURMA =====\n");

    if (quantidade == 0) {

        printf("Nenhum aluno cadastrado para calcular estatisticas.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {

        soma_medias += calcular_media(alunos[i]);

        switch (alunos[i].status) {

            case APROVADO:
                aprovados++;
                break;

            case RECUPERACAO:
                recuperacao++;
                break;

            case REPROVADO:
                reprovados++;
                break;
        }
    }

    media_geral = soma_medias / quantidade;

    printf("Total de alunos: %d\n", quantidade);
    printf("Aprovados: %d\n", aprovados);
    printf("Em recuperacao: %d\n", recuperacao);
    printf("Reprovados: %d\n", reprovados);
    printf("Media geral da turma: %.2f\n", media_geral);
}

// --------------------------------------------------
// FUNCAO PRINCIPAL
// --------------------------------------------------

int main() {

    struct Aluno alunos[MAX];

    int quantidade = 0;
    int opcao;

    do {

        printf("\n=================================\n");
        printf("       CADASTRO DE TURMAS\n");
        printf("=================================\n");

        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar por matricula\n");
        printf("4 - Buscar por trecho do nome\n");
        printf("5 - Estatisticas da turma\n");
        printf("0 - Sair\n");

        printf("=================================\n");
        printf("Escolha uma opcao: ");

        char entrada[256];
        char extra;

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;
        }

        if (sscanf(entrada, "%d %c", &opcao, &extra) != 1) {

            printf("\nOpcao invalida!\n");
            continue;
        }

        switch (opcao) {

            case 1:
                cadastrar_aluno(alunos, &quantidade);
                break;

            case 2:
                listar_alunos(alunos, quantidade);
                break;

            case 3:
                buscar_matricula(alunos, quantidade);
                break;

            case 4:
                buscar_nome(alunos, quantidade);
                break;

            case 5:
                estatisticas(alunos, quantidade);
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}