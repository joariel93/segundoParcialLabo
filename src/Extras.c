/*
 * Extras.c
 *
 *  Created on: 21 nov. 2019
 *      Author: alumno
 */
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Extras.h"

void extras_menuPrincipal() {
	printf("Bienvenido que desea hacer?\n");
	printf("[1] Cargar archivo\n");
	printf("[2] Imprimir lista\n");
	printf("[3] Filtrar menores de 45 días\n");
	printf("[4] Filtrar machos\n");
	printf("[5] Generar listado de ''callejeros''\n");
	printf("[6] Salir\n");
}
void extras_iniciar(LinkedList *this) {
	char archivo[50];
extras_getStringChar(archivo,
			"Ingrese el nombre del archivo sin su extension",
			"Error el archivo no existe", 50, 50);


	controller_loadFromText(archivo, this);

}

int extras_getStringChar(char *pResultado, char *pMensaje, char *pMensajeError,
		int maximo, int limite) {
	int flagError = -1;
	int i;
	int retorno = -1;
	char text[limite];
	if (pResultado != NULL && pMensaje != NULL && 0 < maximo) {
		while (flagError == -1) {
			flagError = 0;
			printf("%s", pMensaje);
			__fpurge(stdin);
			fgets(text, sizeof(text), stdin);
			text[strlen(text) - 1] = '\0';
			if (strlen(text) <= maximo) {
				strcpy(pResultado,text);
				retorno = 0;
			} else {
				printf("%s", pMensajeError);
				flagError = -1;
			}

		}

	}
	return retorno;
}
