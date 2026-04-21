#ifndef ANIMAL_H
#define ANIMAL_H

// Estrutura que representa um Animal Silvestre
typedef struct {
    int  id;
    char especie[50];   // Ex: "Panthera onca"
    char sexo[20];      // "Macho", "Femea" ou "Nao identificado"
} Animal;

// Declaração das funções
void cadastrarAnimal();
void listarAnimais();
void buscarAnimal();

#endif