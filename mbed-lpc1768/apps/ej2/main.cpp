#include "mbed.h"

PwmOut leds[] = { PwmOut(LED1), PwmOut(LED2), PwmOut(LED3), PwmOut(LED4) };

int main() {
    while (1) {
        for (int i = 0; i < 4; i++) {
            for (float brillo = 0.0f; brillo <= 1.0f; brillo += 0.05f) {
                leds[i] = brillo;
                wait(0.03);
            }

            for (float brillo = 1.0f; brillo >= 0.0f; brillo -= 0.05f) {
                leds[i] = brillo;
                wait(0.03);
            }

            leds[i] = 0.0f;
        }
    }
}
