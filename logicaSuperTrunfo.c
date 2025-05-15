#include <stdio.h>


int main() {
    printf("Desafio Lógica Super Trunfo - Nível Novato\n"); 

    // Variáveis para carta 1
    char estado1;
    char codigo1[5];
    char nomeCidade1[50];
    float area1, PIB1, denspop1, PIBpc1, superPoder1;
    int pontosturisticos1;
    unsigned long int populacao1;

    // Variáveis para carta 2
    char estado2;
    char codigo2[5];
    char nomeCidade2[50];
    int  pontosturisticos2;
    unsigned long int populacao2;
    float area2, PIB2, denspop2, PIBpc2, superPoder2;
    
    int resultadoA, resultadoB;

    // Leitura de dados da carta 1

    printf("Digite os dados da carta 1: \n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Código (ex:A01): ");
    scanf("%s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf(" %f", &area1);
    printf("PIB: ");
    scanf(" %f", &PIB1);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontosturisticos1);

    // Leitura de dados da carta 2

    printf("Digite os dados da carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código (ex:A01): ");
    scanf("%s", codigo2);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf(" %f", &area2);
    printf("PIB: ");
    scanf(" %f", &PIB2);
    printf("Pontos Turisticos: ");
    scanf("%d", &pontosturisticos2);

    // Impressão dos dados da carta 1

    printf("\nDados da carta 1:\n");
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código da carta: %s\n", codigo1);
    printf("Nome da cidade: %s\n", nomeCidade1);
    printf("População: %lu mil habitantes\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", PIB1);
    printf("Pontos Turísticos: %d\n", pontosturisticos1);

    
    denspop1 = (float) populacao1 / area1; // calculo da densidade populacional da carta 1
    PIBpc1 = (PIB1 * 1000000000.0f) / populacao1; // calculo do PIB per capita da carta 1
    superPoder1 = (populacao1 + area1 + PIB1 + PIBpc1 + pontosturisticos1) + denspop1 / 1; 

    printf("Densidade Populacional: %.2f hab/km²\n", denspop1);
    printf("PIB per Capita: %.3f reais\n", PIBpc1);
    printf("Super Poder Carta 1: %.3f\n", superPoder1);

    // Impressão dos dados da carta 2

    printf("\nDados da carta 2:\n");
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código da carta: %s\n", codigo2);
    printf("Nome da cidade: %s\n", nomeCidade2);
    printf("População: %lu mil habitantes\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", PIB2);
    printf("Pontos Turísticos: %d\n", pontosturisticos2);

    // Cálculos da carta 2 

    denspop2 = (float) populacao2 / area2; // Calculo da densidade populacional da carta 2
    PIBpc2 = (PIB2 * 1000000000.0f) / populacao2; // calculo do PIB per capita da carta 2
    superPoder2 = (populacao2 + area2 + PIB2 + PIBpc2 + pontosturisticos2) + denspop2 / 1;
    

    printf("Densidade Populacional: %.2f hab/km²\n", denspop2);
    printf("PIB per Capita: %.3f reais\n", PIBpc2);
    printf("Super Poder Carta 2: %.3f\n", superPoder2);

    // Vamos agora comparar duas propriedades das cartas usando operadores relacionais
    // Vamos comparar População e área


    // Comparação de População (maior vence)

    if (populacao1 > populacao2) {
        printf("-------------RESULTADO-------------\n");
        printf("População: Carta 1 - %s venceu com %lu habitantes!\n", nomeCidade1, populacao1);
    } else if (populacao2 > populacao1) {
        printf("-------------RESULTADO-------------\n");
        printf("População: Carta 2 - %s venceu com %lu habitantes!\n", nomeCidade2, populacao2);
    } else {
        printf("-------------RESULTADO-------------\n");
        printf("População: Empate entre as cartas com %lu habitantes!\n", populacao1);
    }

    // Comparação de Área (maior vence)

    if (area1 > area2) {
        printf("-------------RESULTADO-------------\n");
        printf("Área: Carta 1 - %s venceu com %.2f km²!\n", nomeCidade1, area1);
    } else if (area2 > area1) {
        printf("-------------RESULTADO-------------\n");
        printf("Área: Carta 2 - %s venceu com %.2f km²!\n", nomeCidade2, area2);
    } else {
        printf("-------------RESULTADO-------------\n");
        printf("Área: Empate entre as cartas com %.2f km²!\n", area1);
    }
    return 0;
}
