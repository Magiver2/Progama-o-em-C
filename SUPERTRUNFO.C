#include <stdio.h>

struct Carta {
    char estado[3];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

// Funções auxiliares
float calcularDensidade(unsigned long int populacao, float area) {
    return area != 0 ? (float)populacao / area : 0;
}

float calcularPIBPerCapita(float pib, unsigned long int populacao) {
    return populacao != 0 ? pib * 1000000000 / (float)populacao : 0; // Convertendo bilhões para reais
}

float calcularSuperPoder(struct Carta c) {
    float inversoDensidade = c.densidadePopulacional != 0 ? 1.0 / c.densidadePopulacional : 0;
    return (float)c.populacao + c.area + c.pib + (float)c.pontosTuristicos + c.pibPerCapita + inversoDensidade;
}

int compararMaior(float valor1, float valor2) {
    return valor1 > valor2 ? 1 : 0;
}

int compararMenor(float valor1, float valor2) {
    return valor1 < valor2 ? 1 : 0;
}

void lerCarta(struct Carta *carta) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Digite o código: ");
    scanf(" %[^\n]", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadePopulacional = calcularDensidade(carta->populacao, carta->area);
    carta->pibPerCapita = calcularPIBPerCapita(carta->pib, carta->populacao);
    carta->superPoder = calcularSuperPoder(*carta);
}

void exibirCarta(struct Carta c, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nome);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", c.pibPerCapita);
}

int main() {
    struct Carta carta1, carta2;

    printf("=== Digite os dados da Carta 1 ===\n");
    lerCarta(&carta1);

    printf("\n=== Digite os dados da Carta 2 ===\n");
    lerCarta(&carta2);

    // Exibir cartas formatadas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparações
    printf("\nComparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", compararMaior((float)carta1.populacao, (float)carta2.populacao));
    printf("Área: Carta 1 venceu (%d)\n", compararMaior(carta1.area, carta2.area));
    printf("PIB: Carta 1 venceu (%d)\n", compararMaior(carta1.pib, carta2.pib));
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", compararMaior((float)carta1.pontosTuristicos, (float)carta2.pontosTuristicos));
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", compararMenor(carta1.densidadePopulacional, carta2.densidadePopulacional));
    printf("PIB per Capita: Carta 1 venceu (%d)\n", compararMaior(carta1.pibPerCapita, carta2.pibPerCapita));
    printf("Super Poder: Carta 1 venceu (%d)\n", compararMaior(carta1.superPoder, carta2.superPoder));

    return 0;
}