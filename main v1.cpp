#include "mbed.h"

//all 8 segment outputs on the microcontroller
DigitalOut segA(D15);
DigitalOut segB(D14);
DigitalOut segC(D12);
DigitalOut segD(D11);
DigitalOut segE(D10);
DigitalOut segF(D8);
DigitalOut segG(D9);
DigitalOut segDP(D13);

//button1
DigitalIn userButton(PC_13, PullUp);

int main() 
{
    while (true)
    {
        if (userButton == true) //if userButton is pressed letter C lights up
        {
            segA = false;
            segF = false;
            segG = false;
            
        }

        else { //the segments displaying C turn off
            segA = false;
            segF = false;
            segG = false;

            thread_sleep_for(1000); //turns off after 1s of display
        }
    }
}