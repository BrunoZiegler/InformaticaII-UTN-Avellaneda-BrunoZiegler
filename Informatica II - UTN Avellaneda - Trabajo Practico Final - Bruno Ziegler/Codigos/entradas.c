/*
 * Bruno Ziegler
 * Informatica II - UTN Avellaneda
 */

#include "mylib.h"

entradas_t leer_entradas(void)
{
	entradas_t entradas;

	entradas.validacion = !VALIDACION;
	entradas.puerta = PUERTA;
	entradas.reset = !RESET_ALARMA;

	return entradas;
}
