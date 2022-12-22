#include "App_LedCtrl_Interface.h"

int main (void)
{
    LedCtrl_Init();
    while(1)
    {
        /*
         * The input for the fuction is number of counts
         * used in the timer to stay ON or OFF.
         * Ex. As we use a 16bit timer (65536 counts)
         * The ON counts is 32768 equivalent to 0.5 second
         * The OFF counts is 16384 equivalent to 0.25 second
         */
        LedCtrl_PwmBlink(5, 10);
    }
}