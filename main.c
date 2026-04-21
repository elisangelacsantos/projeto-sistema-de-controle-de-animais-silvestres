#include <stdio.h>
#include <stdlib.h>
#include "animal.h"

// Limpa a tela
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Exibe o menu principal
void exibirMenu() {
    printf("\n+======================================+\n");
    printf("|   CONTROLE DE ANIMAIS SILVESTRES     |\n");
    printf("+======================================+\n");
    printf("|  [1] Cadastrar Animal                |\n");
    printf("|  [2] Listar Animais                  |\n");
    printf("|  [3] Buscar Animal                   |\n");
    printf("|  [0] Sair                            |\n");
    printf("+======================================+\n");
    printf("  Escolha uma opcao: ");
}

int main() {
    int opcao;

    do {
        limparTela();
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarAnimal(); break;
            case 2: listarAnimais();   break;
            case 3: buscarAnimal();    break;
            case 0: printf("\nSaindo... Ate logo!\n"); break;
            default: printf("\nOpcao invalida!\n");
        }

        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar(); getchar();
        }

    } while (opcao != 0);

    return 0;
}