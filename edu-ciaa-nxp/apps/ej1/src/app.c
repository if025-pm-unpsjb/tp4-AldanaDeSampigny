#include "sapi.h"

#define UART_USED   UART_USB
#define BAUD_RATE   9600
#define BUFFER_SIZE 32

int main(void) {

    boardConfig();
    uartConfig(UART_USED, BAUD_RATE);

    uint8_t bufferEntrada[BUFFER_SIZE];
    uint8_t data;
    uint8_t contador = 0;

    uartWriteString(UART_USED, "ECHO: Listo.\r\n");

    while(true) {
        if(uartReadByte(UART_USED, &data)) {
            if (data == '\n' || data == '\r') {
                if (contador > 0) {
                    bufferEntrada[contador] = '\0';
                    uartWriteString(UART_USED, "ECHO: ");
                    uartWriteString(UART_USED, (const char*)bufferEntrada);
                    uartWriteString(UART_USED, "\r\n");
                }

                contador = 0;

            }
            else if (contador < (BUFFER_SIZE - 1)) {
            	bufferEntrada[contador] = data;
                contador++;
            }
        }
    }
    return 0;
}
