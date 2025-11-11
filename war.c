#include <stdio.h>
#include <string.h>

// Definição da struct Territorio.
// Armazena o nome, a cor do exército e a quantidade de tropas de um território.
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Constante para o número de territórios a serem cadastrados.
#define NUM_TERRITORIOS 5

// Função para limpar o buffer de entrada.
// Essencial após usar scanf para evitar problemas com leituras subsequentes de string ou char.
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Declaração de um vetor (array) de structs para armazenar 5 territórios.
    Territorio lista_territorios[NUM_TERRITORIOS];
    int i;

    // --- CADASTRO DOS TERRITÓRIOS (Entrada de Dados) ---
    printf("==========================================\n");
    printf("         CADASTRO DE TERRITÓRIOS          \n");
    printf("==========================================\n");

    // Laço 'for' para percorrer o vetor e preencher os dados dos 5 territórios.
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\n--- Território %d de %d ---\n", i + 1, NUM_TERRITORIOS);

        // 1. Entrada do NOME (Usabilidade e Documentação)
        printf("Nome do Território (max 29 caracteres): ");
        // Usamos scanf com especificação de largura para evitar estouro de buffer.
        scanf("%29s", lista_territorios[i].nome);
        limparBufferEntrada(); // Limpa o buffer após o scanf

        // 2. Entrada da COR do Exército
        printf("Cor do Exército (max 9 caracteres): ");
        scanf("%9s", lista_territorios[i].cor);
        limparBufferEntrada(); // Limpa o buffer após o scanf

        // 3. Entrada da Quantidade de TROPAS
        printf("Quantidade de Tropas: ");
        // Usa-se %d para ler um inteiro.
        if (scanf("%d", &lista_territorios[i].tropas) != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            limparBufferEntrada();
            i--; // Decrementa 'i' para repetir a leitura deste território
            continue;
        }
        limparBufferEntrada(); // Limpa o buffer após o scanf
    }

    // --- EXIBIÇÃO DOS DADOS (Saída e Desempenho) ---
    printf("\n==========================================\n");
    printf("      DADOS DOS TERRITÓRIOS CADASTRADOS     \n");
    printf("==========================================\n");

    // Laço 'for' para percorrer o vetor e exibir os dados com formatação clara.
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("\n--- Território %d ---\n", i + 1);
        printf("  Nome: **%s**\n", lista_territorios[i].nome);
        printf("  Cor do Exército: %s\n", lista_territorios[i].cor);
        printf("  Tropas: %d\n", lista_territorios[i].tropas);
    }

    printf("\n==========================================\n");
    printf("Fim do programa.\n");

    return 0;
}