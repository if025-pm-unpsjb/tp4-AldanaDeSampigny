#include "mbed.h"
#include <cstdio> // Necesario para snprintf

// Definiciones de los LEDs
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

Serial pc(USBTX, USBRX);

volatile int increment_interval_ms = 1000;

void check_serial() {
    if (pc.readable()) {
        char buffer[20];
        int i = 0;

        while (pc.readable() && i < 19) {
            buffer[i++] = pc.getc()
            if (buffer[i-1] == '\n' || buffer[i-1] == '\r') {
                break;
            }
        }

        buffer[i] = '\0';

        long new_interval = strtol(buffer, NULL, 10);

        if (new_interval > 0) {
            increment_interval_ms = (int)new_interval;
            pc.printf("Nuevo intervalo: %d ms\n", increment_interval_ms);
        } else if (i > 1) {
            pc.printf("Intervalo invalido. Use un numero positivo. \n");
        }
    }
}

int main() {
    pc.baud(9600);


    while (1) {
        for (int indice = 0; indice < 16; indice++) {
            led1 = (indice >> 0) & 0x1; // Bit 0 (LSB)
            led2 = (indice >> 1) & 0x1; // Bit 1
            led3 = (indice >> 2) & 0x1; // Bit 2
            led4 = (indice >> 3) & 0x1; // Bit 3 (MSB)


            check_serial();


            wait_ms(increment_interval_ms);
        }
    }
}
