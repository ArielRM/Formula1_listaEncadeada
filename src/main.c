#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/formula1.h"
#include "../include/lista_enc.h"
#include "../include/no.h"

#ifndef TAM_BUFFER
#define TAM_BUFFER 1000
#endif // TAM_BUFFER

int main()
{
    char buffer[TAM_BUFFER];
    /// Abrindo o arquivo
    FILE* entrada = fopen("doc/formula1.csv","r");
    if(entrada == NULL) {
        perror("main: erro ao abrir formula1.csv");
        exit(EXIT_FAILURE);
    }
    /// IGNORA CABEÇALHO
    fgets(buffer,TAM_BUFFER,entrada);

    /// Cria e preenche a lista
    lista_enc_t* lista = cria_lista_enc();
    while(fgets(buffer,TAM_BUFFER,entrada)) {
        temporada_t* temp = novaTemporada(buffer);
        no_t* no = cria_no(temp);
        add_cauda(lista,no);
    }
    /// Realiza operações com os dados



    /// Liberando o espaço alocado
    for(int len = tamanho(lista); len > 0; len = tamanho(lista)) {
        no_t* n = remove_cabeca(lista);
        temporada_t* t = obtem_dado(n);
        free(obtemPais(t));
        free(obtemPiloto(t));
        free(obtemEquipe(t));
        free(obtemMotor(t));
        free(obtemPneus(t));
        free(obtemEncerradas(t));
        free(n);
        free(t);
    }
    free(lista);
    fclose(entrada);
    return 0;
}
