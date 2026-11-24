/*
 * Bruno Ziegler
 * Informatica II - UTN Avellaneda
 */

#include "mylib.h"

int main(void)
{
	estados_t estado = inicio;
	estados_t (*fsm[])(void) = {f_inicio, f_espera, f_acceso, f_alarma};

	while(1){
		estado = fsm[estado]();
	}

	return 0;
}
