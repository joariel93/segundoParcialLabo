/*
 * Cachorros.h
 *
 *  Created on: 21 nov. 2019
 *      Author: alumno
 */

#ifndef CACHORROS_H_
#define CACHORROS_H_

typedef struct
{
	int id;
	char nombre[30];
	int dias;
	char raza[30];
	char condicion[5];
	char sexo[5];

}Cachorros;

Cachorros* cachorros_new();
Cachorros* cachorros_newParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* condicionStr,char* sexoStr);

int cachorros_setId(Cachorros* this,int id);
int cachorros_getId(Cachorros* this,int* id);

int cachorros_setNombre(Cachorros* this,char* nombre);
int cachorros_getNombre(Cachorros* this,char* nombre);

int cachorros_setDias(Cachorros* this,int dias);
int cachorros_getDias(Cachorros* this,int* dias);

int cachorros_setRaza(Cachorros* this,char* raza);
int cachorros_getRaza(Cachorros* this,char* raza);

int cachorros_setCondicion(Cachorros* this,char* condicion);
int cachorros_getCondicion(Cachorros* this,char* condicion);

int cachorros_setSexo(Cachorros* this,char* sexo);
int cachorros_getSexo(Cachorros* this,char* sexo);

int funCritDias(void* pElement);
int funCritMacho(void* pElement);
int funCritRaza(void* pElement);

int cachorros_usarGets(int *id, char nombre[], int *dias,char raza[],char condicion[],char sexo[], Cachorros *aux);

#endif /* CACHORROS_H_ */
