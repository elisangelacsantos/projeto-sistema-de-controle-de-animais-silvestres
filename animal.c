#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"

#define ARQUIVO "dados.txt"

// ─────────────────────────────────────────────
// CADASTRAR ANIMAL
// ─────────────────────────────────────────────
void cadastrarAnimal() {
    FILE *arquivo;
    Animal a;
    Animal temp;
    char linha[150];
    int idRepetido;
    int opcaoSexo;

    printf("\n--- CADASTRAR ANIMAL -------------------\n");

    // ID deve ser inteiro maior que zero E unico
    do {
        do {
            printf("ID (numero inteiro maior que zero): ");
            scanf("%d", &a.id);
            if (a.id <= 0) {
                printf("ID invalido! Digite um numero maior que zero.\n");
            }
        } while (a.id <= 0);

      // Verifica se o ID ja existe no arquivo
        idRepetido = 0;
        arquivo = fopen(ARQUIVO, "r");
        if (arquivo != NULL) {
            int idLido;
            char resto[150];
            while (fscanf(arquivo, "%d;", &idLido) == 1) {
                fgets(resto, 150, arquivo); // descarta o resto da linha
                if (idLido == a.id) {
                    idRepetido = 1;
                    break;
                }
            }
            fclose(arquivo);
        }

        if (idRepetido) {
            printf("ID %d ja cadastrado! Digite um ID diferente.\n", a.id);
        }

    } while (idRepetido);

    getchar(); // limpa o buffer

    printf("Especie: ");
    fgets(a.especie, 50, stdin);
    a.especie[strcspn(a.especie, "\n")] = 0;

    printf("Sexo:\n");
    printf("  [1] Macho\n");
    printf("  [2] Femea\n");
    printf("  [3] Nao identificado\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcaoSexo);

    switch (opcaoSexo) {
        case 1:  strcpy(a.sexo, "Macho");            break;
        case 2:  strcpy(a.sexo, "Femea");            break;
        case 3:  strcpy(a.sexo, "Nao identificado"); break;
        default: strcpy(a.sexo, "Nao identificado"); break;
    }

    arquivo = fopen(ARQUIVO, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arquivo, "%d;%s;%s\n", a.id, a.especie, a.sexo);
    fclose(arquivo);

    printf("\nAnimal cadastrado com sucesso!\n");
}