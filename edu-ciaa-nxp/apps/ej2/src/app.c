#include "sapi.h"

#define BOTON1 TEC1
#define LED_BOTON1 LEDR

#define BOTON2 TEC2
#define LED_BOTON2 LEDG

#define BOTON3 TEC3
#define LED_BOTON3 LEDB

#define BOTON4 TEC4
#define LED_BOTON4 LED3

int main(void) {

    boardConfig();
    uartConfig(UART_USB, 115200);

    bool_t ant1 = TRUE, ant2 = TRUE, ant3 = TRUE, ant4 = TRUE;

    while(TRUE){

        bool_t act1 = gpioRead(BOTON1);
        if(act1 == FALSE && ant1 == TRUE){
            gpioToggle(LED_BOTON1);
            uartWriteString(UART_USB, "BOTON1\r\n");
        }
        ant1 = act1;

        bool_t act2 = gpioRead(BOTON2);
        if(act2 == FALSE && ant2 == TRUE){
            gpioToggle(LED_BOTON2);
            uartWriteString(UART_USB, "BOTON2\r\n");
        }
        ant2 = act2;

        bool_t act3 = gpioRead(BOTON3);
        if(act3 == FALSE && ant3 == TRUE){
            gpioToggle(LED_BOTON3);
            uartWriteString(UART_USB, "BOTON3\r\n");
        }
        ant3 = act3;

        bool_t act4 = gpioRead(BOTON4);
        if(act4 == FALSE && ant4 == TRUE){
            gpioToggle(LED_BOTON4);
            uartWriteString(UART_USB, "BOTON4\r\n");
        }
        ant4 = act4;

        delay(50);
    }
}
