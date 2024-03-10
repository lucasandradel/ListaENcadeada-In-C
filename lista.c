#include "lista.h"

//alocação dinâmica de um novo no na memória
tipo_no *aloca_no(int vl){ //passando vl como parâmentro 
    tipo_no *novo_no;//declanrando um ponteiro novo_no
    novo_no = (tipo_no*) malloc(sizeof(tipo_no));//fazendo alocação para inserção de um novo_no na lista
    novo_no -> valor = vl;// parâmetro vl está sendo usado para inserir um valor no novo_no
    novo_no -> prox = NULL;// ponteiro próximo de novo_no está apontando para Nulo
    return novo_no;//retorno do novo_no
}

//inserção de um novo_no no inicio da lista
void insereInicio(tipo_no ** list,int vl ){
    tipo_no * novo_no;
    novo_no = aloca_no(vl);
    if((*list) != NULL){// se minha lista tiver mais de um valor
        novo_no -> prox = (*list);//ponteiro próximo do novo_no alocado na memória passa apontar para o ponteiro que indica a cabeça da lista 
        (*list) = novo_no;// ponteiro que indica a cabeça da lista passa a apontar para novo_no e nono_no é inserido no ínicio da lista
        
    }else{
        (*list) = novo_no;//se lista está vazia, então apenas inserir novo_no na cabeça da lista 
    }
}

//inserção de um novo no no final da lista
void InsereFim(tipo_no** list, int vl){

    tipo_no *novo_no, *aux; //declaração de um ponteiro para ponteiro "aux" para percorrer a lista e inserir no final e de um ponteiro para ponteiro "novo_no" para alocação na memória
    novo_no = aloca_no(vl);

    if ((*list) != NULL){ //se lista tiver mais de um valor, executar os seguintes passos:
        aux = (*list); //ponteiro aux passa apontar para inicio da lista (cabeça)
        while (aux -> prox != NULL){ //enquanto o ponteiro próximo de auxiliar for differente de nulo (ou seja) : enquanto não chegou ao final da lista 

            aux = aux -> prox; // auxlilar recebe auxiliar próximo -> percorre a lista

        }//chegou no final da lista
        aux -> prox = novo_no; // ponteiro próximo de auxiliar aponta para novo_no, o que faz com o que ocorra a inserção no final da lista
    }else{
        novo_no -> prox = (*list);
        (*list) = novo_no;
    }
}

//inserção de um novo no em uma determinada posição da minha lista
int InserePos (tipo_no** list, int valor, int pos){
    tipo_no *novo_no;
    tipo_no *aux , * auxS; //declaraão de dois ponteiros auxiliares, os dois percorrem a lista, porém o "auxS" fica um pouco atrá para quando houver a inserção, poder atualizar 
    int contador = 0;// contador para nos dizer em qual posição estamos
    
    if( pos != 0){// se posição for diferente de 0

        aux = (*list);// ponteiro auxiliar aponta para onde o ponteiro "(*list)" está apontando, ou seja para o ínicio/cabeça da lista
        while ((aux != NULL) && ( contador < pos ))// enquanto aux for diferente de nulo E contador for diferente da posição que quero inserir
        {
            auxS = aux; // auxiliar sentinela aponta para onde auxiliar está apontando 
            aux = aux -> prox;//auxiliar recebe auxiliar próximo, ou seja, estou percorrendo minha lista 
            contador ++;//incremento do contador até a posição
        }
        //fim do lop

        if ((aux != NULL) && (contador == pos)){ // se após o loop, auxiliar ainda for diferente de nulo e o contador for igual a posição que quero inserir o valor faça:
            novo_no = aloca_no(valor); // aloco valor para meu novo_no
            novo_no -> prox = aux; // ponteiro próximo de novo no aponta para auxiliar e faz a inserçaõ na posição 
            auxS -> prox = novo_no;//ponteiro próximo de auxiliar sentinela, que está uma casa atrá do auxiliar passa a apontar para o novo valor inserido na posição de auxiliar, que está na sua frente
        }
        else if (( aux == NULL) && (contador == pos)){ // se após o loop, auxiiar for nulo e contador for igual a posição, emtão cheguei ao final da lista e aposição que irei inserir é a última
            InsereFim(list, valor);// inserção no final da lista

        } 
        
        
    }else{
        insereInicio(list, valor);//se a posição for igual a zero, apenas fazer uma inserção no ínicio da lista  
    }
}

//função que remove no inicio da lista 
int removeInicio(tipo_no ** list){
    tipo_no * aux;
    int valor;

    if ((*list) != NULL){ // se lista tiver um valor ou mais 
        aux =(*list); //auxiliar passa apontar para o inicio da lista
        valor = aux -> valor; //variavel valor recebe valor do ponteiro auxiliar que está apontando para o inicio da lista
        (*list) = (*list) -> prox;//atualização do inicio da lista, para o próximo valor da lista
        free (aux);//liberação do ponteiro auxiliar, que está apontando para o inicio da lista, que foi removido 
        return valor;
        
    }else{
        printf("[ERRO], LISTA VAZIA, IMPOSSÍVEL A REMOÇÃO");
    }

}

//função que faz remoção do último elemeento
int RemoveFim (tipo_no** list){
    tipo_no *aux, *auxS;
    int vl;

    
    if ((*list) != NULL){
        aux = (*list);
        // Percorre até o último nó
        while (aux -> prox != NULL)
        {
            auxS = aux;
            aux = aux -> prox;
        }
        vl = aux -> valor;// Obtém o valor do último nó
        free(aux);// Libera a memória do último nó
        auxS->prox = NULL;// Define o próximo do novo último nó como NULL
        return vl;
    }
    else{
        printf ("[ERRO], LISTA VAZIA, IMPOSSÍVEL A REMOÇÃO\n ");
        return -1;
    }
}

//função que faz a remoção de uma posição determinada
int RemovePos (tipo_no **list, int pos){
    tipo_no *aux, *auxS;//auxiliar para percorrer a lista e liberar o elemento que quero remover e auxiliar Sentinela para atualizar o valor anterior do elemento que irá ser excluido da lista 
    int valor;
    int contador = 0;//declaração de um contador para indicar a posição que estamos 

    if (*list != NULL){//se minha lista tiver um ou mais elementos  
        aux = (*list);//auxiliar passa apontar para o inicio da lista
        if(pos != 0){//se posição for diferente de 0 faça:
            
            while ((aux != NULL) && (contador < pos))//lopp: enquanto aux for diferente de nulo e contador menos que a posição que quero excluir faça:
            {
                auxS = aux;//auxiliar sentinela aponta para auxiliar 
                aux = aux -> prox;//auxiliar recebe auxiliar proximo -> percorrendo a lista
                contador ++;// incremento do contador a cada passada 
            }
            //fim do loop

            if (aux != NULL && contador == pos){ //se auxiliar for diferente de nulo ao fim do loop e contador igual a posição que irá ser removida
                valor = aux ->valor;//guardo o valor do elemento que irá ser removido na varável valor
                auxS -> prox = aux -> prox;// jump do ponteiro próximo de auxiliar sentinela para o elemento que o ponteiro próximo de auiliar estar apontando, ou seja o próximo elemento do elemento que irá ser removido
                free (aux); //liberação do auxiliar da lista
                return valor;
            }
            
        }else{
            //remove incio
            aux =(*list);
            valor = aux ->valor;
            (*list) = (*list) -> prox;
            free (aux);
            return valor;
            
        }

    }else{
        printf ("Erro, Lista está vazia\n");
    }

}

void imprimeLista(tipo_no*list){
    printf("Lista:\n\tTOPO->");
    while (list!=NULL)
    {
        printf("[%d]->",list->valor);
        list = list->prox;
    }
    printf("[NULL]\n");
}
