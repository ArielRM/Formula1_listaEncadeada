#include <stdio.h>
#include <stdlib.h>

#include "../include/lista_enc.h"
#include "../include/no.h"

//#define DEBUG

struct listas_enc {
    no_t *cabeca;
    no_t *cauda;
    int tamanho;
};

//cria uma lista vazia
lista_enc_t *cria_lista_enc (void) {
    lista_enc_t *p = malloc(sizeof(lista_enc_t));

    if (p == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    p->cabeca = NULL;
    p->cauda = NULL;
    p->tamanho = 0;

    return p;
}

void add_cauda(lista_enc_t *lista, no_t* elemento)
{
    if (lista == NULL || elemento == NULL){
        fprintf(stderr,"add_cauda: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

   #ifdef DEBUG
   printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
   #endif // DEBUG

   //lista vazia
   if (lista->tamanho == 0)
   {
        #ifdef DEBUG
        printf("add_cauda: add primeiro elemento: %p\n", elemento);
        #endif // DEBUG

        lista->cauda = elemento;
        lista->cabeca = elemento;
        lista->tamanho++;

        desliga_no(elemento);
   }
   else {
        // Remove qualquer ligacao antiga
        desliga_no(elemento);
        // Liga cauda da lista com novo elemento
        liga_nos(lista->cauda, elemento);

        lista->cauda = elemento;
        lista->tamanho++;
   }
}

///Parte nova

no_t * obtem_cabeca(lista_enc_t *lista)
{
	if(lista == NULL) {
		fprintf(stderr,"obtem_cabeca: ponteiro invalido");
		exit(EXIT_FAILURE);
	}
	return(lista->cabeca);
}

no_t * remove_elem(lista_enc_t *lista, int index) {
	if(lista == NULL) {
		fprintf(stderr,"remove_elem: ponteiro invalido");
		exit(EXIT_FAILURE);
	}
	if(index >= lista->tamanho || index < 0) {
		fprintf(stderr,"remove_elem: index invalido");
		exit(EXIT_FAILURE);
	}
	if(index == 0) //Cabeca
		return remove_cabeca(lista);
	no_t *elem_ant = lista->cabeca;
	no_t *elemento = obtem_proximo(elem_ant);
	for(int i = 1; i < index; i++) {
		elem_ant = elemento;
		elemento = obtem_proximo(elemento);
	}
	no_t *elem_pro = obtem_proximo(elemento);
	if(elem_pro == NULL) {
		desliga_no(elem_ant);
		lista->cauda = elem_ant;
	}
	else
		liga_nos(elem_ant,elem_pro);
	lista->tamanho--;
	return elemento;
}

void add_cabeca(lista_enc_t *lista, no_t* elemento)
{
	if(lista == NULL || elemento == NULL) {
		fprintf(stderr,"add_cabeca: ponteiros invalidos");
		exit(EXIT_FAILURE);
	}

	#ifdef DEBUG
	printf("Adicionando %p --- tamanho: %d\n", elemento, lista->tamanho);
	#endif // DEBUG

	//lista vazia
	if(lista->tamanho == 0) {
		#ifdef DEBUG
		printf("add_cabeca: add primeiro elemento: %p\n",elemento);
		#endif // DEBUG

		lista->cabeca = elemento;
		lista->cauda = elemento;
		lista->tamanho++;

		desliga_no(elemento);
	}
	else {
		liga_nos(elemento,lista->cabeca);
		lista->cabeca = elemento;
		lista->tamanho++;
	}
}

no_t * remove_cabeca(lista_enc_t *lista)
{
	if(lista == NULL) {
		fprintf(stderr,"remove_cabeca: ponteiro invalido");
		exit(EXIT_FAILURE);
	}
	#ifdef DEBUG
	printf("Removendo %p --- tamanho: %d\n", lista->cabeca, lista->tamanho);
	#endif
	no_t *elemento = lista->cabeca;
	lista->cabeca = obtem_proximo(elemento);
	if(lista->cabeca == NULL)
		lista->cauda = NULL;
	lista->tamanho--;
	return elemento;
}

int tamanho(lista_enc_t *lista)
{
	if(lista == NULL) {
		fprintf(stderr,"tamanho: ponteiro invalido");
		exit(EXIT_FAILURE);
	}
	return(lista->tamanho);
}

int vazia(lista_enc_t *lista)
{
	if(lista == NULL) {
		fprintf(stderr,"vazia: ponteiro invalido");
		exit(EXIT_FAILURE);
	}
	return lista->tamanho == 0;
}
