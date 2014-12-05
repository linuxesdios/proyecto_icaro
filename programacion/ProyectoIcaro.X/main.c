#include <xc.h>
#include "main.h"
#define MY_FRC                  0xF9E3

// FUSES
// -----------------------------------------------------------

_FOSC(MY_FRC & CSW_FSCM_ON) //   0xF9E3 & 0x3FFF --> Arranca sin PLL (8MHz) y se habilita el Init_Pll_AUX
_FGS(GWRP_OFF & CODE_PROT_OFF)
_FICD(ICS_PGD1)
_FWDT(WDT_OFF)
_FBORPOR(PWRT_OFF & BORV27 & PBOR_OFF & MCLR_DIS)
// FIN FUSES

/////////////////////////////////////////////////////////
//                             _                       //
//         _ __ ___     __ _  (_)  _ __                //
//        | '_ ` _ \   / _` | | | | '_ \               //
//        | | | | | | | (_| | | | | | | |              //
//        |_| |_| |_|  \__,_| |_| |_| |_|              //
//                                                     //
/////////////////////////////////////////////////////////
int main(void)
{
//********INICIALIZACIONES***********
    Init_Hw();
    Init_Inter();
    Init_Pll();DelayXmsT5(1);
    Init_PWM();
    Init_Bluetooh();DelayXmsT5(1);

//*********PROGRAMA************
    while(BOTON_IZQ==1);
    DelayXmsT5(50);
    while(BOTON_IZQ==0);
    DelayXmsT5(50);
    
    LED_ALL_ON
    DelayXmsT5(980);
    LED4 = 0;



//    PonMotores(4100,4100);
    START_PID;
    while(1)
    {
        
    }
}
