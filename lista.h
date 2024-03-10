#ifndef __LISTA_ENC_H__
#define __LISTA_ENC_H__

#include <stdio.h>
#include <stdlib.h>

struct est_no{
    int valor;
    struct est_no *prox;

};
typedef struct est_no tipo_no;

//prototipos
tipo_no *aloca_no(int);
void insereInicio(tipo_no ** ,int);
void InsereFim(tipo_no**, int);
int InserePos (tipo_no**, int, int);
int removeInicio(tipo_no **);
int RemoveFim (tipo_no**);
int RemovePos (tipo_no **, int);
void imprimeLista(tipo_no*);


#endif