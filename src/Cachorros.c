/*
 * Cachorros.c
 *
 *  Created on: 21 nov. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cachorros.h"


Cachorros* cachorros_new() {
	Cachorros *puppi = (Cachorros*) malloc(sizeof(Cachorros));

	if (puppi != NULL) {
		puppi->id = 0;
		strcpy(puppi->nombre, " ");
		puppi->dias = 0;
		strcpy(puppi->raza, " ");
		strcpy(puppi->condicion, " ");
		strcpy(puppi->sexo, " ");
	}
	return puppi;
}
Cachorros* cachorros_newParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* condicionStr,char* sexoStr) {
	int auxId, auxDias;
	char auxNombre[30];
	char auxRaza[30];
	char auxCondicion [30];
	char auxSexo[5];
	Cachorros *puppi = (Cachorros*) malloc(sizeof(Cachorros));

	if (puppi != NULL) {
		auxId = atoi(idStr);
		strncpy(auxNombre, nombreStr,30);
		auxDias = atoi(diasStr);
		strncpy(auxRaza, razaStr,30);
		strncpy(auxCondicion, condicionStr,30);
		strncpy(auxSexo, sexoStr,3);

		cachorros_setId(puppi, auxId);
		cachorros_setNombre(puppi, auxNombre);
		cachorros_setDias(puppi, auxDias);
		cachorros_setRaza(puppi, auxRaza);
		cachorros_setCondicion(puppi, auxCondicion);
		cachorros_setSexo(puppi, auxSexo);
	}

	return puppi;
}
int cachorros_setId(Cachorros *this, int id) {
	int retorno = -1;
	if (this != NULL && id >= 0) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int cachorros_getId(Cachorros *this, int *id) {
	int retorno = -1;
	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int cachorros_setNombre(Cachorros *this, char *nombre) {
	int retorno = -1;
	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}
int cachorros_getNombre(Cachorros *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int cachorros_setDias(Cachorros *this, int dias) {
	int retorno = -1;

	if (this != NULL && dias >= 0) {
		this->dias = dias;
		retorno = 0;
	}

	return retorno;
}
int cachorros_getDias(Cachorros *this, int *dias) {
	int retorno = -1;
	if (this != NULL && dias != NULL) {
		*dias = this->dias;
		retorno = 0;
	}

	return retorno;
}

int cachorros_setRaza(Cachorros *this, char *raza) {
	int retorno = -1;
	if (this != NULL && raza != NULL) {
		strcpy(this->raza, raza);
		retorno = 0;
	}

	return retorno;
}
int cachorros_getRaza(Cachorros *this, char *raza) {
	int retorno = -1;

	if (this != NULL && raza != NULL) {
		strcpy(raza, this->raza);
		retorno = 0;
	}

	return retorno;
}
int cachorros_setCondicion(Cachorros *this, char *condicion) {
	int retorno = -1;
	if (this != NULL && condicion != NULL) {
		strcpy(this->condicion, condicion);
		retorno = 0;
	}

	return retorno;
}
int cachorros_getCondicion(Cachorros *this, char *condicion) {
	int retorno = -1;

	if (this != NULL && condicion != NULL) {
		strcpy(condicion, this->condicion);
		retorno = 0;
	}

	return retorno;
}
int cachorros_setSexo(Cachorros *this, char* sexo) {
	int retorno = -1;
	if (this != NULL && sexo != NULL) {
		strcpy(this->sexo, sexo);
		retorno = 0;
	}

	return retorno;
}
int cachorros_getSexo(Cachorros *this, char *sexo) {
	int retorno = -1;

	if (this != NULL && sexo != NULL) {
		strcpy(sexo, this->sexo);
		retorno = 0;
	}

	return retorno;
}
int funCritDias(void *pElement) {
	Cachorros *arg1 = (Cachorros*) pElement;

	int dias;
	int retorno;

	cachorros_getDias(arg1, &dias);

	if (dias > 45) {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}
int funCritMacho(void *pElement) {
Cachorros* aux;

aux=(Cachorros*)pElement;

	int retorno;
	if (strcmp(aux->sexo, "M") == 0) {
		retorno = 1;
	} else {
		retorno = 0;
	}

	return retorno;
}
int funCritRaza(void *pElement) {
	Cachorros* aux;

	aux=(Cachorros*)pElement;

	int retorno;

	if (strcmp(aux->raza,"Callejero") == 0) {

		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}

int cachorros_usarGets(int *id, char nombre[], int *dias,char raza[],char condicion[],char sexo[], Cachorros *aux) {
	int retorno = 0;
	cachorros_getId(aux, id);
	cachorros_getNombre(aux, nombre);
	cachorros_getDias(aux, dias);
	cachorros_getRaza(aux, raza);
	cachorros_getCondicion(aux, condicion);
	cachorros_getSexo(aux, sexo);

	return retorno;
}
