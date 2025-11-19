#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main() {
    while (1) {
        for (int indice= 0; indice < 16; indice++) {
            int temp = indice;
            int bits[4] = {0, 0, 0, 0};

            int i = 0;
            while (temp > 0 && i < 4) {
                bits[i] = temp % 2;
                temp = temp / 2;
                i++;
            }

            led1 = bits[0];
            led2 = bits[1];
            led3 = bits[2];
            led4 = bits[3];

            wait(1);
        }
    }
}
