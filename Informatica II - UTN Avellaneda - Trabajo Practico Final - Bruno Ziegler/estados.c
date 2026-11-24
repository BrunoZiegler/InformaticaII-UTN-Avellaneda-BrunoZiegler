/*
 * Bruno Ziegler
 * Informatica II - UTN Avellaneda
 */

#include "mylib.h"

static unsigned char ya_abrieron = 0;


estados_t f_inicio(void)
{
	unsigned char SET = 0;

	SET = inicializar_micro();

	if(SET) return espera;
	return inicio;
}


estados_t f_espera(void)
{
	trabar_puerta();
	apagar_buzzer();
	led_espera();

	if(puerta_abierta())
		return alarma;

	if(validacion()){
		reiniciar_tiempo_puerta();
		ya_abrieron = 0;
		return acceso;
	}

	return espera;
}


estados_t f_acceso(void)
{
	liberar_puerta();
	led_acceso();

	if(puerta_abierta()){
		if(ya_abrieron == 0){
			ya_abrieron = 1;
			reiniciar_tiempo_puerta();
		}
		if(leer_tiempo_puerta() > T_MAX)
			return alarma;
		return acceso;
	}

	if(ya_abrieron)
		return espera;
	if(leer_tiempo_puerta() > T_RELE)
		return espera;

	return acceso;
}


estados_t f_alarma(void)
{
	trabar_puerta();
	led_alarma();

	if(leer_tiempo_buzzer() >= T_BUZZER){
		cambiar_buzzer();
		reiniciar_tiempo_buzzer();
	}

	if(reset_alarma() && !puerta_abierta()){
		apagar_buzzer();
		return espera;
	}

	return alarma;
}
