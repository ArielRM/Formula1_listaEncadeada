#ifndef FORMULA1_H_INCLUDED
#define FORMULA1_H_INCLUDED
#define TAM_BUFFER 1000
typedef struct temporada temporada_t;
temporada_t * novaTemporada(char* record);
char * obtemPais(temporada_t *temp);
char * obtemPiloto(temporada_t *temp);
char * obtemEquipe(temporada_t *temp);
char * obtemMotor(temporada_t *temp);
char * obtemPneus(temporada_t *temp);
char * obtemEncerradas(temporada_t *temp);
char * obtemCorrida(temporada_t *temp);

void printTemporada(temporada_t *temp);

#endif // FORMULA1_H_INCLUDED
