#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/formula1.h"

#define TAM_BUFFER 1000

struct temporada {
	short ano;
	char* pais;
	char* piloto;
	short idade;
	int numero;
	char* equipe;
	char* motor; //?
	char* pneus;
	int poles;
	int voltas_mais_rapidas;
	int pontos;
	char* encerradas;
	float PM;
};

temporada_t * novaTemporada(char* record) {
    temporada_t* temp = (temporada_t*) malloc(sizeof(temporada_t));
    if(temp == NULL) {
        perror("novaTemp: Erro ao alocar mem�ria para temp");
        exit(EXIT_FAILURE);
    }

    char pais[TAM_BUFFER];
	char piloto[TAM_BUFFER];
	char equipe[TAM_BUFFER];
	char motor[TAM_BUFFER];
	char pneus[TAM_BUFFER];
    char encerradas[TAM_BUFFER];

    int hold = sscanf(record,"%hd;%1000[^;];%1000[^;];%hd;%d;%1000[^;];%1000[^;];%1000[^;];%d;%d;%d;%1000[^;];%f",
           &temp->ano,pais,piloto,&temp->idade,&temp->numero,equipe,motor,pneus,&temp->poles,&temp->voltas_mais_rapidas,
           &temp->pontos,encerradas,&temp->PM);
    if(hold != 13){
        fprintf(stderr,"Arquivo inv�lido em:\n>>%s<<",record);
        exit(EXIT_FAILURE);
    }

    temp->pais = (char*) malloc(strlen(pais) + 1);
    if(temp->pais == NULL) {
        perror("novaTemp: Erro ao alocar mem�ria para temp->pais");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->pais,pais,strlen(pais)+1);

    temp->piloto = (char*) malloc(strlen(piloto) + 1);
    if(temp->piloto == NULL) {
        perror("novaTemp: Erro ao alocar mem�ria para temp->piloto");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->piloto,piloto,strlen(piloto)+1);

    temp->equipe = (char*) malloc(strlen(equipe) + 1);
    if(temp->equipe == NULL) {
        perror("novaTemp: Erro ao alocar mem�ria para temp->equipe");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->equipe,equipe,strlen(equipe)+1);

    temp->motor = (char*) malloc(strlen(motor) + 1);
    if(temp->motor == NULL) {
        perror("novaTemp: Erro ao alocar mem�ria para temp->motor");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->motor,motor,strlen(motor)+1);

    temp->pneus = (char*) malloc(strlen(pneus) + 1);
    if(temp->pneus == NULL) {
        perror("novaTemp: Erro ao alocar mem�ria para temp->pneus");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->pneus,pneus,strlen(pneus)+1);

    temp->encerradas= (char*) malloc(strlen(encerradas) + 1);
    if(temp->encerradas == NULL) {
        perror("novaTemp: Erro ao alocar mem�ria para temp->encerradas");
        exit(EXIT_FAILURE);
    }
    strncpy(temp->encerradas,encerradas,strlen(encerradas)+1);

    return temp;
}

char * obtemPais(temporada_t *temp) {
    return temp->pais;
}
char * obtemPiloto(temporada_t *temp) {
    return temp->piloto;
}
char * obtemEquipe(temporada_t *temp) {
    return temp->equipe;
}
char * obtemMotor(temporada_t *temp) {
    return temp->motor;
}
char * obtemPneus(temporada_t *temp) {
    return temp->pneus;
}
char * obtemEncerradas(temporada_t *temp) {
    return temp->encerradas;
}
