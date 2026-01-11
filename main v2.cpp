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

//buttons
DigitalIn userButton(PC_13, PullUp); //Button1
DigitalIn extButton(PA_0, PullUp);   //Button2

//pattern for each 7-segment display
void showPattern(uint8_t p)
{
    segA = p & 0b00000001;
    segB = p & 0b00000010;
    segC = p & 0b00000100;
    segD = p & 0b00001000;
    segE = p & 0b00010000;
    segF = p & 0b00100000;
    segG = p & 0b01000000;
    segDP = p & 0b10000000;
}

//turns everything off
void clearDisplay()
{
    segA = 0; //where 0 = false
    segB = 0;
    segC = 0;
    segD = 0;
    segE = 0;
    segF = 0;
    segG = 0;
    segDP = 0;
}

//displays each letter with 1 second in between each
void showLetter(uint8_t p)
{
    showPattern(p);
    thread_sleep_for(1000);
    clearDisplay();
    thread_sleep_for(150);
}

int main() 
{
    //first name letter patters
    uint8_t C = 0x61; // a + f + g
    uint8_t O = 0x63; // a + b + f + g
    uint8_t R = 0x50; // e + g
    uint8_t I = 0x90; // e + dp
    uint8_t N = 0x44; // c + g

    //last name
    uint8_t J = 0x8C; // c + d + dp
    uint8_t E = 0x49; // a + d + g
    uint8_t M = 0x15; // a + c + e
    uint8_t A = 0x23; // a + b + f
    uint8_t NN = 0x44; // c + g

    while (1)
    {
        //if Button1 pressed  then display first name on the 7-segment display
        if (userButton == 0)
        {
            showLetter(C);
            showLetter(O);
            showLetter(R);
            showLetter(I);
            showLetter(N);
            
            while (userButton == 0); //wait for release
        }

        //if Button2 pressed then display last name
        if (extButton == 0)
        {
            showLetter(J);
            showLetter(E);
            showLetter(M);
            showLetter(A);
            showLetter(NN);

             while (extButton == 0); //wait for release
        }
    }
}