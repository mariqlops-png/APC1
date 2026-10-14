
/*
O fall-through foi mais vantajoso nos grupos de serviços e prioridades,
pois permitiu compartilhar ações sem repetir os mesmos comandos.
No agrupamento dos serviços, os códigos 1, 2 e 3 compartilham
categoria, prazo e taxa; os códigos 4 e 5 também compartilham esses dados.
O switch compara valores específicos, como códigos inteiros e caracteres.
Por isso, ele não substitui diretamente o if-else-if usado na classificação
por faixas de renda, que depende de comparações relacionais.
*/

#include <stdio.h>

int main(void) {
    int codigo_servico;
    int dia;
    int guiche = 0;

    char prioridade;
    char nome_prioridade[20] = "Invalida";

    const char *servicos[] = {
        "Codigo invalido",
        "Historico escolar",
        "Declaracao de matricula",
        "Declaracao de vinculo",
        "Trancamento",
        "Cancelamento",
        "Colacao de grau"
    };

    const char *servico;
    const char *categoria = "—";
    const char *prazo = "0";
    const char *status = "ACEITO";
    const char *nome_dia;
    const char *expediente = "Dia invalido";

    float taxa_base = 0.0f;
    float acrescimo = 0.0f;
    float taxa_final;

    printf("\nCodigo do servico:\n");
    printf("1 - Historico escolar\n");
    printf("2 - Declaracao de matricula\n");
    printf("3 - Declaracao de vinculo\n");
    printf("4 - Trancamento\n");
    printf("5 - Cancelamento\n");
    printf("6 - Colacao de grau\n");
    printf("Digite o codigo desejado: ");
    scanf("%d", &codigo_servico);
    

    printf("\nPrioridade (U/u, N/n ou B/b): ");
    scanf(" %c", &prioridade);

    printf("\nDia da semana (1 a 7): ");
    scanf("%d", &dia);

    /* 1. Servico */
    switch (codigo_servico) {
        case 1:
        case 2:
            /* fall-through */
        case 3:
            categoria = "Documento simples";
            prazo = "2 dias uteis";
            taxa_base = 15.00f;
            break;

        case 4:
            /* fall-through */
        case 5:
            categoria = "Interrupcao de vinculo";
            prazo = "10 dias uteis";
            taxa_base = 0.00f;
            break;

        case 6:
            categoria = "Ato solene";
            prazo = "15 dias uteis";
            taxa_base = 80.00f;
            break;

        default:
            codigo_servico = 0;
            categoria = "—";
            prazo = "0";
            taxa_base = 0.00f;
            status = "RECUSADO";
            break;
    }

    servico = servicos[codigo_servico];

    /* 2. Prioridade */
    switch (prioridade) {
        case 'U':
            /* fall-through */
        case 'u':
            snprintf(nome_prioridade, sizeof(nome_prioridade), "Urgente");
            guiche = 1;
            acrescimo = 10.00f;
            break;

        case 'N':
            /* fall-through */
        case 'n':
            snprintf(nome_prioridade, sizeof(nome_prioridade), "Normal");
            guiche = 2;
            acrescimo = 0.00f;
            break;

        case 'B':
            /* fall-through */
        case 'b':
            snprintf(nome_prioridade, sizeof(nome_prioridade), "Balcao");
            guiche = 3;
            acrescimo = 0.00f;
            break;

        default:
            snprintf(nome_prioridade, sizeof(nome_prioridade), "Invalida");
            guiche = 0;
            acrescimo = 0.00f;
            break;
    }

    /* 3. Nome do dia */
    switch (dia) {
        case 1:
            nome_dia = "Domingo";
            break;
        case 2:
            nome_dia = "Segunda-feira";
            break;
        case 3:
            nome_dia = "Terca-feira";
            break;
        case 4:
            nome_dia = "Quarta-feira";
            break;
        case 5:
            nome_dia = "Quinta-feira";
            break;
        case 6:
            nome_dia = "Sexta-feira";
            break;
        case 7:
            nome_dia = "Sabado";
            break;
        default:
            nome_dia = "Dia invalido";
            break;
    }

    /* 4. Expediente */
    switch (dia) {
        case 2:
        case 3:
        case 4:
            /* fall-through */
        case 5:
            expediente = "Pleno";
            break;

        case 6:
            expediente = "Reduzido";
            break;

        case 1:
            /* fall-through */
        case 7:
            expediente = "Fechado";
            break;

        default:
            expediente = "Dia invalido";
            break;
    }

    /* Calculo final */
    taxa_final = taxa_base + acrescimo;

    printf("\n========================================\n");
    printf("      TRIAGEM DE PROTOCOLO ACADEMICO\n");
    printf("========================================\n");
    printf("Servico                              : %s\n", servico);
    printf("Categoria                            : %s\n", categoria);
    printf("Prazo                                : %s\n", prazo);
    printf("Taxa base                            : R$ %.2f\n", taxa_base);
    printf("Prioridade                           : %s\n", nome_prioridade);
    printf("Guiche                               : %d\n", guiche);
    printf("Acrescimo                            : R$ %.2f\n", acrescimo);
    printf("Dia                                  : %s\n", nome_dia);
    printf("Expediente                           : %s\n", expediente);
    printf("-----------------------------------------------------------------------\n");
    printf("Taxa final                           : R$ %.2f\n", taxa_final);
    printf("Status do servico                    : %s\n", status);
    printf("========================================\n");

    return 0;
}