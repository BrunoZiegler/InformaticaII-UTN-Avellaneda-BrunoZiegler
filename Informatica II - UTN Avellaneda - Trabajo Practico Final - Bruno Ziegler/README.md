# Trabajo Práctico Integrador - Informática II - UTN Avellaneda 2026
> **Alumno:** Bruno Ziegler

## Memoria Descriptiva

Este repositorio contiene el Trabajo Práctico Integrador de la materia. Para este proyecto, elegí desarrollar un **sistema de control de acceso**. 

Se trata de un sistema de validación de entrada que gestiona una cerradura electromagnética. La máquina de estados validará el ingreso y liberará el relé de la puerta por un tiempo determinado. Fundamentalmente, monitoreará que la puerta no quede abierta por descuido. Si el contacto magnético detecta una apertura forzada (sin validación previa) o un tiempo de puerta abierta superior al permitido, el sistema pasará a un estado de alarma con indicadores sonoros, requiriendo un reinicio manual (*reset*) por parte del operador una vez normalizada la situación.

## Diagrama de la Máquina de Estados



## Variables y Condiciones

* **SET:** Bandera de fin de inicialización.
* **v:** Señal de validación de acceso (0 = No validado, 1 = Validado).
* **p:** Estado del sensor magnético de la puerta (0 = Cerrada, 1 = Abierta).
* **t:** Tiempo transcurrido desde la apertura de la puerta.
* **t_max:** Tiempo máximo permitido con la puerta abierta.
* **r:** Señal de reset manual de alarma (0 = Reposo, 1 = Reiniciar).