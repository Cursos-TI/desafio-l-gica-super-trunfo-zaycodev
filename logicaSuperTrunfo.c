#include <stdio.h>

int main() {
    printf("Desafio Lógica Super Trunfo - Nível Mestre\n");

    /* --------------------------------------------------
       1. DECLARAÇÃO DAS VARIÁVEIS
       -------------------------------------------------- */
    char  estado1, estado2;
    char  codigo1[5], codigo2[5];
    char  nomeCidade1[50], nomeCidade2[50];

    unsigned long int populacao1, populacao2;
    float area1, area2;
    float PIB1,  PIB2;
    int   pontosTuristicos1, pontosTuristicos2;
    int   superPoder1, superPoder2;

    /* atributos derivados */
    float denspop1, denspop2, PIBpc1, PIBpc2;

    /* escolhas do usuário */
    int escolha1, escolha2;

    /* --------------------------------------------------
       2. LEITURA DAS CARTAS
       -------------------------------------------------- */
    printf("Digite os dados da carta 1:\n");
    printf("Estado (A‑H): ");
    scanf(" %c", &estado1);
    printf("Código (ex:A01): ");
    scanf(" %4s", codigo1);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f",  &area1);
    printf("PIB (bilhões): ");
    scanf("%f",  &PIB1);
    printf("Pontos Turísticos: ");
    scanf("%d",  &pontosTuristicos1);
    printf("Super Poder (0 = não, 1 = sim): ");
    scanf("%d", &superPoder1);

    printf("\nDigite os dados da carta 2:\n");
    printf("Estado (A‑H): ");
    scanf(" %c", &estado2);
    printf("Código (ex:A01): ");
    scanf(" %4s", codigo2);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f",  &area2);
    printf("PIB (bilhões): ");
    scanf("%f",  &PIB2);
    printf("Pontos Turísticos: ");
    scanf("%d",  &pontosTuristicos2);
    printf("Super Poder (0 = não, 1 = sim): ");
    scanf("%d", &superPoder2);

    /* cálculos derivados */
    denspop1 = (float)populacao1 / area1;
    denspop2 = (float)populacao2 / area2;
    PIBpc1   = (PIB1 * 1e9f) / populacao1;
    PIBpc2   = (PIB2 * 1e9f) / populacao2;

    /* --------------------------------------------------
       3. MENU – PRIMEIRO ATRIBUTO
       -------------------------------------------------- */
    printf("\n=========== MENU DE COMPARAÇÃO ===========\n");
    printf("Escolha o primeiro atributo.\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("===========================================\nDigite sua opção: ");
    scanf("%d", &escolha1);

    /* --------------------------------------------------
       4. MENU – SEGUNDO ATRIBUTO (uma única leitura)
       -------------------------------------------------- */
    printf("\n=========== MENU DE COMPARAÇÃO ===========\n");
    printf("Escolha o segundo atributo (diferente do primeiro).\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("===========================================\nDigite sua opção: ");
    scanf("%d", &escolha2);

    if (escolha2 == escolha1) {
        puts("\nVocê escolheu o mesmo atributo! Comparação encerrada.");
        return 0;
    }

    /* --------------------------------------------------
       5. MAPEAR VALORES DOS ATRIBUTOS ESCOLHIDOS
       -------------------------------------------------- */
    float valorAttr1Carta1 = 0, valorAttr1Carta2 = 0;
    float valorAttr2Carta1 = 0, valorAttr2Carta2 = 0;

    /* primeiro atributo */
    switch (escolha1) {
        case 1: valorAttr1Carta1 = populacao1;          valorAttr1Carta2 = populacao2;          break;
        case 2: valorAttr1Carta1 = area1;               valorAttr1Carta2 = area2;               break;
        case 3: valorAttr1Carta1 = PIB1;                valorAttr1Carta2 = PIB2;                break;
        case 4: valorAttr1Carta1 = pontosTuristicos1;   valorAttr1Carta2 = pontosTuristicos2;   break;
        case 5: valorAttr1Carta1 = denspop1;            valorAttr1Carta2 = denspop2;            break;
    }

    /* segundo atributo */
    switch (escolha2) {
        case 1: valorAttr2Carta1 = populacao1;          valorAttr2Carta2 = populacao2;          break;
        case 2: valorAttr2Carta1 = area1;               valorAttr2Carta2 = area2;               break;
        case 3: valorAttr2Carta1 = PIB1;                valorAttr2Carta2 = PIB2;                break;
        case 4: valorAttr2Carta1 = pontosTuristicos1;   valorAttr2Carta2 = pontosTuristicos2;   break;
        case 5: valorAttr2Carta1 = denspop1;            valorAttr2Carta2 = denspop2;            break;
    }

    /* --------------------------------------------------
       6. COMPARAÇÃO INDIVIDUAL (OPERADOR TERNÁRIO)
       -------------------------------------------------- */
    int carta1VenceAttr1 = (escolha1 == 5) ? (valorAttr1Carta1 < valorAttr1Carta2)
                                           : (valorAttr1Carta1 > valorAttr1Carta2);

    int carta1VenceAttr2 = (escolha2 == 5) ? (valorAttr2Carta1 < valorAttr2Carta2)
                                           : (valorAttr2Carta1 > valorAttr2Carta2);

    /* --------------------------------------------------
       7. SOMA DOS VALORES DOS ATRIBUTOS
       -------------------------------------------------- */
    float somaCarta1 = 0, somaCarta2 = 0;

    if (escolha1 == 5) {
        somaCarta1 += -valorAttr1Carta1;
        somaCarta2 += -valorAttr1Carta2;
    } else {
        somaCarta1 +=  valorAttr1Carta1;
        somaCarta2 +=  valorAttr1Carta2;
    }

    if (escolha2 == 5) {
        somaCarta1 += -valorAttr2Carta1;
        somaCarta2 += -valorAttr2Carta2;
    } else {
        somaCarta1 +=  valorAttr2Carta1;
        somaCarta2 +=  valorAttr2Carta2;
    }

    /* bônus do super poder */
    if (superPoder1) somaCarta1 += 1000;
    if (superPoder2) somaCarta2 += 1000;

    /* --------------------------------------------------
       8. EXIBIÇÃO DOS RESULTADOS
       -------------------------------------------------- */
    puts("\n===== RESULTADO DOS ATRIBUTOS =====");
    printf("Atributo 1 (%d): Carta %d venceu\n", escolha1, carta1VenceAttr1 ? 1 : 2);
    printf("Atributo 2 (%d): Carta %d venceu\n", escolha2, carta1VenceAttr2 ? 1 : 2);

    puts("\n===== SOMA FINAL =====");
    printf("Carta 1 (%s): %.2f\n", nomeCidade1, somaCarta1);
    printf("Carta 2 (%s): %.2f\n", nomeCidade2, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        puts("\n▶ CARTA 1 VENCEU A RODADA!\n");
    } else if (somaCarta2 > somaCarta1) {
        puts("\n▶ CARTA 2 VENCEU A RODADA!\n");
    } else {
        puts("\n▶ EMPATE!\n");
    }

    return 0;
}
