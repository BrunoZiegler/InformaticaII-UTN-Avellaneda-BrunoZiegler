/*
 * Bruno Ziegler
 * Informatica II - UTN Avellaneda
 */

#ifndef MYLIB_H_
#define MYLIB_H_

#define T_MAX		10000
#define T_RELE		5000
#define T_BUZZER	250

typedef enum {
	inicio = 0,
	espera = 1,
	acceso = 2,
	alarma = 3
}estados_t;

estados_t f_inicio(void);
estados_t f_espera(void);
estados_t f_acceso(void);
estados_t f_alarma(void);

unsigned char inicializar_micro(void);

unsigned char validacion(void);
unsigned char puerta_abierta(void);
unsigned char reset_alarma(void);

void trabar_puerta(void);
void liberar_puerta(void);
void apagar_buzzer(void);
void cambiar_buzzer(void);
void led_espera(void);
void led_acceso(void);
void led_alarma(void);

void mysystick_handler(void);
void reiniciar_tiempo_puerta(void);
unsigned int leer_tiempo_puerta(void);
void reiniciar_tiempo_buzzer(void);
unsigned int leer_tiempo_buzzer(void);

#endif
