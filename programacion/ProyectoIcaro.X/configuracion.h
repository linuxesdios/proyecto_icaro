/* 
Funciones a crear, pero no se modifican a lo largo de la vida del proyecto.
 */

#ifndef CONF_H
#define	CONF_H
#include <string.h>
#include <stdlib.h>
#include "define.h"



// Funciones de temporizacion
void Delay_Nop(unsigned int _contador)
{
    while(_contador>0)
    {
        Nop();
        _contador--;
    }
}

void Config_T1(void)
{
    T1CON = 0b0000000000010000; // Preescala 1:8
    PR1 = 0x1CC0;       // 2 msg
    TMR1 = 0;
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 1;
    _T1IE = 1;
}

void Delay1msT5(void)
{
    T5CON = 0b0000000000010000; // Preescala 1:8
    PR5 = 0x0E60;       // 0x0E30 segun excel
    TMR5 = 0;
    IFS1bits.T5IF = 0;
    T5CONbits.TON = 1;
    _T5IE = 0;
    while(IFS1bits.T5IF == 0);
    T5CONbits.TON = 0;
}

void DelayXmsT5(int _msg)
{
    do
    {
        Delay1msT5();
        _msg--;
    }while(_msg >0);

}

void StartTimer3(unsigned int _milisegundos)
{
    IPC1bits.T3IP = 0b111;
    IFS0bits.T3IF = 0;          // Timer 3
    T2CONbits.T32 = 0;
    T3CONbits.TON   = 0;
    T3CONbits.TSIDL = 0;
    T3CONbits.TGATE = 0;
    T3CONbits.TCKPS = 0b01; //Preescaler 1:8
    T3CONbits.TCS = 0;
    PR3 = 0x0990;       // 0x0E30 segun excel
    TMR3 = 0;
    IFS0bits.T3IF = 0;
    T3CONbits.TON = 1;
    IEC0bits.T3IE = 1;    
}


// Funciones de inicializacion
void Init_Hw(void)
{
    OSCTUN = 0b0000;        Delay_Nop(10);  // 118 MHz

    // ANSELx
    ADPCFG = 0xFFFF;        Delay_Nop(10);  // Digital

    TRISA = 	0xFFFF;     Delay_Nop(10);
    TRISB = 	0xFFFF;     Delay_Nop(10);
    TRISC = 	0xFFFF;     Delay_Nop(10);
    TRISD = 	0xFFFF;     Delay_Nop(10);
    TRISF = 	0xFFFF;     Delay_Nop(10);

//    DelayXmsT5(100);
    Init_Pll();
    DelayXmsT5(10);

    // TRISx
    TRISA = 	0xFFFF;     Delay_Nop(10);
    TRISB = 	0xFFFF;     Delay_Nop(10);
    TRISC = 	0x1FFF;     Delay_Nop(10);
    TRISD = 	0xF2F0;     Delay_Nop(10);
    TRISF = 	0xFF92;     Delay_Nop(10);



    // PORTx
    PORTA = 0;      Delay_Nop(10);
    PORTB = 0;      Delay_Nop(10);
    PORTC = 0;      Delay_Nop(10);
    PORTD = 0;      Delay_Nop(10);
    PORTF = 0;      Delay_Nop(10);

    T1CONbits.TSIDL = 0;
    T1CONbits.TGATE = 0;
    
    // Interrupciones
    T2CONbits.T32 = 0;
    T4CONbits.T32 = 0;
    
    IPC1bits.T3IP = 0b100;
    IFS0bits.T3IF = 0;          // Timer 3
    IEC0bits.T3IE = 0;

    IPC0bits.T1IP = 0b111;	// Prioridad de la interrupcion: 7 = MAXIMA.
    IFS0bits.T1IF = 0;          // Timer 1
    IEC0bits.T1IE = 0;          // Se activa al arrancar el robot

    IPC5bits.INT2IP = 0b100;    // Encoder
    INTCON2bits.INT2EP = 0;	//  flanco 0->1
    IFS1bits.INT2IF = 0;
    IEC1bits.INT2IE = 0;
}



void Init_PWM()
{
    OC3CON = 0;
    OC4CON = 0;

    T2CONbits.TON = 0;      Nop();
    T2CONbits.TSIDL = 0;    Nop();
    T2CONbits.TGATE = 0;    Nop();
    T2CONbits.TCS = 0;      Nop();
    T2CONbits.T32 = 0;      Nop();      // TIMER2 --> 16 Bits
    T2CONbits.TCKPS = 0;    Nop();//preeccala
    IFS0bits.T2IF = 0;      Nop();
    T2CONbits.TON = 1;


    OC3CONbits.OCM = 0b110;
    OC4CONbits.OCM = 0b110;

    PR2 = 0x0FFF;   Nop();  // V_maxima = 4095
    PR3 = 0x0FFF;   Nop();
    OC3RS = 0;      Nop();

    PR4 = 0x0FFF;   Nop();
    OC4RS = 0;      Nop();

}

void Init_Bluetooh(void)
{

//#define RECEP
        U2MODEbits.UARTEN = 1;  Nop();  Nop();  Nop();
        U2STAbits.UTXISEL = 0;  Nop();
        U2STAbits.URXISEL = 0;  Nop();
        U2MODEbits.PDSEL = 0;   Nop();
        U2MODEbits.STSEL = 0;   Nop();
        U2MODEbits.ABAUD = 0;   Nop();

        U2BRG = 15;              Nop();

        U2STAbits.UTXEN = 1;    Nop();
        IFS1bits.U2RXIF = 0;    Nop();
        IFS1bits.U2TXIF = 0;    Nop();
#ifdef  RECEP
    IEC1bits.U2RXIE = 1;    Nop();
#else
        IEC1bits.U2RXIE = 0;    Nop();
#endif
        IEC1bits.U2TXIE = 0;    Nop();
    // FIN - Init_Bluetooh();
}

void clockSwitch (unsigned int newNOSCCode)
{
        int current_cpu_ipl;                            /* Declare temp variable for storing CPU IPL */
        int newOSCCONHCode;
        char a, b, c, *p;

        newOSCCONHCode = OSCCON;
        newOSCCONHCode = newOSCCONHCode & ZERO_MASK_FOR_NOSC_IN_OSCCON;
        newOSCCONHCode = newOSCCONHCode >> 8;

        switch (newNOSCCode)
        {
                case NOSC_LP: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                        	  break;
                case NOSC_FRC: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                          	   break;
                case NOSC_LPRC: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                        	    break;
                case NOSC_EXTOSC: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                        	      break;
                case NOSC_PLLOSC: newOSCCONHCode = newOSCCONHCode | newNOSCCode ;
                        	  	  break;
                default: return;
        }

        b = OSCCONH_UNLOCK_CODE1;                       /* Load OSCCONH unlock sequence parameters */
        c = OSCCONH_UNLOCK_CODE2;
        p = (char *)&OSCCON + 1;

        SET_AND_SAVE_CPU_IPL(current_cpu_ipl, 7);       /* Disable interrupts for unlock sequence below */

        /* Perform OSCCONH unlock sequence and write the new oscillator value to the NOSC bits */
        asm volatile ("mov.b %1,[%0] \n"
                  "mov.b %2,[%0] \n"
                  "mov.b %3,[%0] \n" : /* no outputs */ : "r"(p), "r"(b), "r"(c),
                                                          "r"(newOSCCONHCode));

        b = OSCCONL_UNLOCK_CODE1;                       /* Load OSCCONL unlock sequence parameters */
        c = OSCCONL_UNLOCK_CODE2;
        p = (char *)&OSCCON;
        a = OSCCON | 0x01;

        /* Perform OSCCONL unlock sequence and request an Oscillator switch by setting OSWEN bit */
        asm volatile ("mov.b %1,[%0] \n"
                  "mov.b %2,[%0] \n"
                  "mov.b %3,[%0] \n" : /* no outputs */ : "r"(p), "r"(b), "r"(c),
                                                          "r"(a));
        while (OSCCONbits.OSWEN);                       /* Wait until OSWEN has been cleared by hardware */

        RESTORE_CPU_IPL(current_cpu_ipl);               /* Restore CPU IPL value after executing unlock sequence */
}


void Init_Pll(void)
{
    int i;
    //    char mycadena[50];

    for (i = 0; i < 2; i++)
        Delay1msT5();

    clockSwitch(NOSC_PLLOSC);
    Delay_Nop(1500);
}


#endif	/* CONF_H */

