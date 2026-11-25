/*
 * Bruno Ziegler
 * Informatica II - UTN Avellaneda
 */

#ifndef HARDWARE_H_
#define HARDWARE_H_

#include "avr_api/avr_api.h"

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

#define LED_ACCESO_GPIO_PIN		avr_GPIO_PIN_4
#define LED_ACCESO				avr_GPIOB_OUT_4

#define LED_ALARMA_GPIO_PIN		avr_GPIO_PIN_3
#define LED_ALARMA				avr_GPIOB_OUT_3

#endif
