
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]) {

    tipo_no *minha_lista;
    minha_lista = NULL;

    // Inserindo elementos no final da lista
    InsereFim(&minha_lista, 4);  
    InsereFim(&minha_lista, 2);  
    InsereFim(&minha_lista, 1); 

    printf("Lista após Inserçôes no final:\n");
    imprimeLista(minha_lista);

    //inserção de elementos no inicio da lista  
    insereInicio (&minha_lista, 0);
    insereInicio (&minha_lista, 9);
    insereInicio (&minha_lista, 10);

    printf("Lista após inserções no incio:\n");
    imprimeLista(minha_lista);
    
    // Inserindo um elemento na posição 2
    int inseridoPos = InserePos(&minha_lista, 7, 2); // 7 = valor inserido; 2 = posição que irá inserir o valor 7

    // Imprimindo a lista após a inserção na posição 2
    printf("\nLista Após Inserção na Posição 2:\n");
    imprimeLista(minha_lista);

    //Removendo o elemento da posição 4
    int valorRemovidoPos = RemovePos(&minha_lista, 4);

    // Imprimindo a lista após a remoção na posição 4
    printf("\nLista Após Remoção na Posição 4 (Valor Removido: %d):\n", valorRemovidoPos);
    imprimeLista(minha_lista);

    // Removendo do início da lista
    int valorRemovidoInicio = removeInicio(&minha_lista);
    printf("\nLista Após Remoção do Início (Valor Removido: %d):\n", valorRemovidoInicio);

    imprimeLista(minha_lista);


    // Removendo do final da lista
    int valorRemovidofim = RemoveFim(&minha_lista);
    printf("\nLista Após Remoção do Final (Valor Removido: %d):\n", valorRemovidofim);
    imprimeLista(minha_lista);
    

    return EXIT_SUCCESS;
}
