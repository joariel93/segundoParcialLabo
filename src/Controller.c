#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Cachorros.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {

	FILE *pArchivo;
	int retorno = 0;


	if ((pArchivo = fopen(path, "r")) == NULL) {

		printf("El archivo no puede ser abierto");
		retorno = -1;
	} else {

		parser_cachorrosFromText(pArchivo, pArrayListEmployee);
		fclose(pArchivo);
	}
	//UNA VEZ LEIDO LLAMAR A LA FUNCION NEW_EMPLOYEE PARA QUE GUARDE UNA POSICION EN LA STRUCT DE EMPLOYEE

	return retorno;
}

/** \brief Listar
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_listarCachorros(LinkedList *pArrayListEmployee) {
	Cachorros *aux;
	int i;
	int id, dias;
	char nombre[50];
	char raza[50];
	char condicion[50];
	char sexo[5];
	printf("Id\tNombre\tDias\tRaza\tReservado?\tSexo\n");
	for (i = 0; i < ll_len(pArrayListEmployee); i++) {

		aux = ll_get(pArrayListEmployee, i);

		cachorros_usarGets(&id, nombre, &dias, raza,condicion,sexo, aux);
		printf("%d\t%s\t%d\t%s\t%s\t%s\n", id, nombre, dias, raza,condicion,sexo);
	}
	return 1;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pFile;
	Cachorros *aux;
	int id, dias;
	char archivo[50];
	char nombre[50];
	char raza[50];
	char condicion[3];
	char sexo[3];
	int retorno = -1;
	int i;



	pFile = fopen(archivo, "w+");
	fprintf(pFile, "ID,Nombre,Dias,Raza,Reservado,Genero\n");
	for (i = 0; i < ll_len(pArrayListEmployee); i++) {
		aux = (Cachorros*) ll_get(pArrayListEmployee, i);
		cachorros_usarGets(&id, nombre, &dias,raza,condicion,sexo , aux);
		fprintf(pFile, "%d,%s,%d,%s,%s,%s\n", id, nombre, dias, raza,condicion,sexo);
		retorno = 0;
	}

	fclose(pFile);

	return retorno;
	return 1;
}
