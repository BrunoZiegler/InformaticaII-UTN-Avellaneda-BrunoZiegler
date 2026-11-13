/*
 * Bruno Ziegler
 * Informatica II - UTN Avellaneda
 */

#include "avr_api/avr_api.h"
#include "mylib.h"

#define ENTRADAS_GPIO_PORT		avr_GPIO_D

#define VALIDACION_GPIO_PIN		avr_GPIO_PIN_0
#define VALIDACION				avr_GPIOD_IN_0
#define VALIDACION_PULLUP		avr_GPIOD_OUT_0

#define RESET_GPIO_PIN			avr_GPIO_PIN_1
#define RESET_ALARMA			avr_GPIOD_IN_1
#define RESET_PULLUP			avr_GPIOD_OUT_1

#define PUERTA_GPIO_PIN			avr_GPIO_PIN_2
#define PUERTA					avr_GPIOD_IN_2
#define PUERTA_PULLUP			avr_GPIOD_OUT_2

#define SALIDAS_GPIO_PORT		avr_GPIO_B

#define RELE_GPIO_PIN			avr_GPIO_PIN_0
#define RELE					avr_GPIOB_OUT_0

#define BUZZER_GPIO_PIN			avr_GPIO_PIN_1
#define BUZZER					avr_GPIOB_OUT_1

#define LED_ESPERA_GPIO_PIN		avr_GPIO_PIN_2
#define LED_ESPERA				avr_GPIOB_OUT_2

#define LED_ACCESO_GPIO_PIN		avr_GPIO_PIN_3
#define LED_ACCESO				avr_GPIOB_OUT_3

#define LED_ALARMA_GPIO_PIN		avr_GPIO_PIN_4
#define LED_ALARMA				avr_GPIOB_OUT_4

static volatile unsigned int tiempo_puerta = 0;
static volatile unsigned int tiempo_buzzer = 0;

unsigned char inicializar_micro(void)
{
	GpioInitStructure_AVR entradas, salidas;
	SystickInitStructure_AVR base_tiempo;

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

	return 1;
}


unsigned char validacion(void)
{
	return !VALIDACION;
}

unsigned char puerta_abierta(void)
{
	return PUERTA;
}

unsigned char reset_alarma(void)
{
	return !RESET_ALARMA;
}


void trabar_puerta(void)
{
	RELE = 0;
}

void liberar_puerta(void)
{
	RELE = 1;
}

void apagar_buzzer(void)
{
	BUZZER = 0;
}

void cambiar_buzzer(void)
{
	BUZZER ^= 1;
}

void led_espera(void)
{
	LED_ESPERA = 1;
	LED_ACCESO = 0;
	LED_ALARMA = 0;
}

void led_acceso(void)
{
	LED_ESPERA = 0;
	LED_ACCESO = 1;
	LED_ALARMA = 0;
}

void led_alarma(void)
{
	LED_ESPERA = 0;
	LED_ACCESO = 0;
	LED_ALARMA = 1;
}


void mysystick_handler(void)
{
	tiempo_puerta++;
	tiempo_buzzer++;
}

void reiniciar_tiempo_puerta(void)
{
	tiempo_puerta = 0;
}

unsigned int leer_tiempo_puerta(void)
{
	return tiempo_puerta;
}

void reiniciar_tiempo_buzzer(void)
{
	tiempo_buzzer = 0;
}

unsigned int leer_tiempo_buzzer(void)
{
	return tiempo_buzzer;
}
