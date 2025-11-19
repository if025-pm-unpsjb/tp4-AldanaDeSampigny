#include "sapi.h"

#define BTN_R   TEC1
#define BTN_G   TEC2
#define BTN_B   TEC3
#define BTN_ON  TEC4

int main(void){

    boardConfig();

    bool_t antR = TRUE, antG = TRUE, antB = TRUE, antON = TRUE;
    bool_t encendido = FALSE;

    bool_t R = FALSE, G = FALSE, B = FALSE;

    while(TRUE){

        bool_t actR = gpioRead(BTN_R);
        if(actR == FALSE && antR == TRUE){
            R = !R;
            gpioWrite(LEDR, R && encendido);
        }
        antR = actR;


        bool_t actG = gpioRead(BTN_G);
        if(actG == FALSE && antG == TRUE){
            G = !G;
            gpioWrite(LEDG, G && encendido);
        }
        antG = actG;

        bool_t actB = gpioRead(BTN_B);
        if(actB == FALSE && antB == TRUE){
            B = !B;
            gpioWrite(LEDB, B && encendido);
        }
        antB = actB;


        bool_t actON = gpioRead(BTN_ON);
        if(actON == FALSE && antON == TRUE){
            encendido = !encendido;
            gpioWrite(LEDR, R && encendido);
            gpioWrite(LEDG, G && encendido);
            gpioWrite(LEDB, B && encendido);
        }
        antON = actON;

        delay(50);
    }
}
