/*
 * Bruno Ziegler
 * Informatica II - UTN Avellaneda
 */

#include "mylib.h"

static unsigned char ya_abrieron = 0;


estados_t f_inicio(void)
{
	GpioInitStructure_AVR entradas, salidas;
	SystickInitStructure_AVR base_tiempo;
	unsigned char SET = 0;

	entradas.modo = avr_GPIO_mode_Input;
	entradas.port = ENTRADAS_GPIO_PORT;
	entradas.pines = VALIDACION_GPIO_PIN | RESET_GPIO_PIN | PUERTA_GPIO_PIN;
	init_gpio(entradas);

	VALIDACION_PULLUP = 1;
	RESET_PULLUP = 1;
	PUERTA_PULLUP = 1;

	salidas.modo = avr_GPIO_mode_Output;
	salidas.port = SALIDAS_GPIO_PORT;
	salidas.pines = RELE_GPIO_PIN | BUZZER_GPIO_PIN | LED_ESPERA_GPIO_PIN | LED_ACCESO_GPIO_PIN | LED_ALARMA_GPIO_PIN;
	init_gpio(salidas);

	RELE = 0;
	BUZZER = 0;
	LED_ESPERA = 0;
	LED_ACCESO = 0;
	LED_ALARMA = 0;

	base_tiempo.time_ms = 1;
	base_tiempo.timernumber = avr_TIM2;
	base_tiempo.avr_systick_handler = mysystick_handler;
	init_Systick_timer(base_tiempo);

	sei();

	SET = 1;

	if(SET) return espera;
	return inicio;
}


estados_t f_espera(void)
{
	entradas_t entradas = leer_entradas();

	RELE = 0;
	BUZZER = 0;
	LED_ESPERA = 1;
	LED_ACCESO = 0;
	LED_ALARMA = 0;

	if(entradas.puerta == 1)
		return alarma;

	if(entradas.validacion == 1 && entradas.puerta == 0){
		tiempo_puerta = 0;
		ya_abrieron = 0;
		return acceso;
	}

	return espera;
}


estados_t f_acceso(void)
{
	entradas_t entradas = leer_entradas();

	RELE = 1;
	LED_ESPERA = 0;
	LED_ACCESO = 1;

	if(entradas.puerta == 1){
		if(ya_abrieron == 0){
			ya_abrieron = 1;
			tiempo_puerta = 0;
		}
		if(tiempo_puerta > T_MAX)
			return alarma;
		return acceso;
	}

	if(ya_abrieron)
		return espera;
	if(tiempo_puerta > T_RELE)
		return espera;

	return acceso;
}


estados_t f_alarma(void)
{
	entradas_t entradas = leer_entradas();

	RELE = 0;
	LED_ESPERA = 0;
	LED_ACCESO = 0;
	LED_ALARMA = 1;

	if(tiempo_buzzer >= T_BUZZER){
		BUZZER ^= 1;
		tiempo_buzzer = 0;
	}

	if(entradas.reset == 1 && entradas.puerta == 0){
		BUZZER = 0;
		return espera;
	}

	return alarma;
}
