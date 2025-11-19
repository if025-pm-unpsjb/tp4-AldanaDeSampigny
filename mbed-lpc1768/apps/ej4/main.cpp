#include "mbed.h"

Serial pc(USBTX, USBRX);

DigitalOut leds[] = { LED1, LED2, LED3, LED4 };

int main() {
    pc.printf("Ingrese un numero del entre 1 y 4:\r\n");

    int ledSeleccionado = -1;

    while(1) {
        if (pc.readable()) {
            char c = pc.getc();

            if (c >= '1' && c <= '4') {
                ledSeleccionado = c - '1';
                pc.printf("Parpadeando LED %c\r\n", c);
            } else {
                pc.printf("Caracter invalido. Ingrese 1 a 4.\r\n");
            }
        }

        if (ledSeleccionado != -1) {
            for (int i = 0; i < 4; i++)
                leds[i] = 0;

            leds[ledSeleccionado] = 1;
            wait(0.25);

            leds[ledSeleccionado] = 0;
            wait(0.25);
        }
    }
}
