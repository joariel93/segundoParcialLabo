#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorros.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_cachorrosFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	Cachorros *pAux;
	char bufId[20];
	char bufNombre[20];
	char bufDias[20];
	char bufRaza[20];
	char bufCondicion[20];
	char bufSexo[20];
	fscanf(pFile, "%[^_]_%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufId, bufNombre,
			bufDias, bufRaza, bufCondicion, bufSexo);
	while (!feof(pFile)) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufId, bufNombre, bufDias,
				bufRaza, bufCondicion, bufSexo);
		pAux = cachorros_newParametros(bufId, bufNombre, bufDias, bufRaza,
				bufCondicion, bufSexo);

		if (pAux != NULL) {

			ll_add(pArrayListEmployee, pAux);
		}
	}

	return 1;
}
