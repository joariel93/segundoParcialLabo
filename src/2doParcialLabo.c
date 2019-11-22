/*
 ============================================================================
 Name        : 2doParcialLabo.c		\
 Author      : Joaquin Calero
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "Cachorros.h"
#include "LinkedList.h"
#include "Extras.h"


int main(void) {
	LinkedList* lista;
	LinkedList* filtrada45Dias;
	LinkedList* filtradaMachos;
	LinkedList* filtradaCallejeros;

	int choice;
	int flag = 0;

	lista=ll_newLinkedList();
	do {
extras_menuPrincipal();
		__fpurge(stdin);
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			extras_iniciar(lista);
			flag = 1;
			break;
		case 2:
			if (flag == 1) {
				controller_listarCachorros(lista);
			} else {
				printf("Primero debe cargar el archivo");
			}
			break;
		case 3:
			if (flag == 1) {
				filtrada45Dias = ll_newLinkedList();
				filtrada45Dias = ll_filter(lista, funCritDias);
				controller_saveAsText("mayores.csv",filtrada45Dias);
			} else {
				printf("Primero debe cargar el archivo");
			}
			break;
		case 4:
			if (flag == 1) {
				filtradaMachos = ll_newLinkedList();
				filtradaMachos = ll_filter(lista,
						funCritMacho);
				controller_saveAsText("machos.csv",filtradaMachos);
			} else {
				printf("Primero debe cargar el archivo");
			}
			break;
		case 5:
			if (flag == 1) {
				filtradaCallejeros = ll_newLinkedList();
				filtradaCallejeros = ll_filter(lista,
						funCritRaza);
				controller_saveAsText("callejeros.csv",filtradaCallejeros);
			} else {
				printf("Primero debe cargar el archivo");
			}
			break;
		default:
			break;

		}

	} while (choice >=0 && choice <= 5);

	return 0;
}
