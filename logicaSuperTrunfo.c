#include <stdio.h>
#include <string.h>

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer até encontrar uma nova linha ou fim de arquivo
}

// Definição da estrutura para representar uma cidade
typedef struct {
    char estado;           // Letra do estado (A a H)
    char codigo[4];        // Código da carta (ex: A01, B02, etc.)
    char nome[50];         // Nome da cidade
    int populacao;         // População da cidade
    float area;            // Área da cidade (em km²)
    float pib;             // PIB da cidade (em bilhões)
    int pontos_turisticos; // Número de pontos turísticos
} Cidade;

// Função para cadastrar uma cidade
void cadastrarCidade(Cidade *cidade) {
    printf("\nCadastro de Carta:\n");

    // Solicita e armazena o estado
    printf("Digite a letra do estado (A a H): ");
    scanf(" %c", &cidade->estado);
    limparBuffer(); // Limpa o buffer após a leitura do estado

    // Solicita e armazena o código da carta
    printf("Digite o código da carta (ex: %c01, %c02, etc.): ", cidade->estado, cidade->estado);
    scanf("%s", cidade->codigo);
    limparBuffer(); // Limpa o buffer após a leitura do código

    // Solicita e armazena o nome da cidade
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade->nome); // Lê uma string com espaços
    limparBuffer(); // Limpa o buffer após a leitura do nome

    // Solicita e armazena a população da cidade
    printf("Digite a população da cidade: ");
    while (scanf("%d", &cidade->populacao) != 1) { // Valida a entrada para garantir que seja um número inteiro
        printf("Entrada inválida! Digite um número inteiro para a população: ");
        limparBuffer(); // Limpa o buffer em caso de entrada inválida
    }
    limparBuffer(); // Limpa o buffer após a leitura da população

    // Solicita e armazena a área da cidade
    printf("Digite a área da cidade (em km²): ");
    while (scanf("%f", &cidade->area) != 1) { // Valida a entrada para garantir que seja um número
        printf("Entrada inválida! Digite um número para a área: ");
        limparBuffer(); // Limpa o buffer em caso de entrada inválida
    }
    limparBuffer(); // Limpa o buffer após a leitura da área

    // Solicita e armazena o PIB da cidade
    printf("Digite o PIB da cidade (em bilhões): ");
    while (scanf("%f", &cidade->pib) != 1) { // Valida a entrada para garantir que seja um número
        printf("Entrada inválida! Digite um número para o PIB: ");
        limparBuffer(); // Limpa o buffer em caso de entrada inválida
    }
    limparBuffer(); // Limpa o buffer após a leitura do PIB

    // Solicita e armazena o número de pontos turísticos
    printf("Digite o número de pontos turísticos da cidade: ");
    while (scanf("%d", &cidade->pontos_turisticos) != 1) { // Valida a entrada para garantir que seja um número inteiro
        printf("Entrada inválida! Digite um número inteiro para os pontos turísticos: ");
        limparBuffer(); // Limpa o buffer em caso de entrada inválida
    }
    limparBuffer(); // Limpa o buffer após a leitura dos pontos turísticos
}

// Função para exibir os dados de uma cidade
void exibirCidade(Cidade cidade) {
    printf("\nDados da Carta %s:\n", cidade.codigo);
    printf("Estado: %c\n", cidade.estado);
    printf("Nome: %s\n", cidade.nome);
    printf("População: %d habitantes\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: %.2f bilhões\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("--------------------------\n");
}

// Função para comparar duas cidades com base em um atributo escolhido
void compararCidades(Cidade cidade1, Cidade cidade2, int atributo) {
    switch (atributo) {
        case 1: // Comparar população
            if (cidade1.populacao > cidade2.populacao) {
                printf("\n%s tem maior população que %s.\n", cidade1.nome, cidade2.nome);
            } else if (cidade1.populacao < cidade2.populacao) {
                printf("\n%s tem maior população que %s.\n", cidade2.nome, cidade1.nome);
            } else {
                printf("\n%s e %s têm a mesma população.\n", cidade1.nome, cidade2.nome);
            }
            break;

        case 2: // Comparar área
            if (cidade1.area > cidade2.area) {
                printf("\n%s tem maior área que %s.\n", cidade1.nome, cidade2.nome);
            } else if (cidade1.area < cidade2.area) {
                printf("\n%s tem maior área que %s.\n", cidade2.nome, cidade1.nome);
            } else {
                printf("\n%s e %s têm a mesma área.\n", cidade1.nome, cidade2.nome);
            }
            break;

        case 3: // Comparar PIB
            if (cidade1.pib > cidade2.pib) {
                printf("\n%s tem maior PIB que %s.\n", cidade1.nome, cidade2.nome);
            } else if (cidade1.pib < cidade2.pib) {
                printf("\n%s tem maior PIB que %s.\n", cidade2.nome, cidade1.nome);
            } else {
                printf("\n%s e %s têm o mesmo PIB.\n", cidade1.nome, cidade2.nome);
            }
            break;

        case 4: // Comparar pontos turísticos
            if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
                printf("\n%s tem mais pontos turísticos que %s.\n", cidade1.nome, cidade2.nome);
            } else if (cidade1.pontos_turisticos < cidade2.pontos_turisticos) {
                printf("\n%s tem mais pontos turísticos que %s.\n", cidade2.nome, cidade1.nome);
            } else {
                printf("\n%s e %s têm o mesmo número de pontos turísticos.\n", cidade1.nome, cidade2.nome);
            }
            break;

        default:
            printf("\nAtributo inválido!\n");
            break;
    }
}

int main() {
    printf("Bem-vindo ao Super Trunfo - Países!\n");

    // Cadastro das cartas
    Cidade cidade1, cidade2;
    printf("\nCadastro da Carta 1:\n");
    cadastrarCidade(&cidade1);
    printf("\nCadastro da Carta 2:\n");
    cadastrarCidade(&cidade2);

    // Exibição dos dados das cartas cadastradas
    printf("\nCartas Cadastradas:\n");
    exibirCidade(cidade1);
    exibirCidade(cidade2);

    // Menu de comparação
    int atributo;
    printf("\nEscolha o atributo para comparar as cidades:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    // Comparação das cidades
    compararCidades(cidade1, cidade2, atributo);

    return 0;
}