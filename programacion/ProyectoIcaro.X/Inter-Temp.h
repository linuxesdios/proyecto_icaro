/* 
 * File:   Interrupciones.h
 * Author: pablo
 *
 * Created on 1 de diciembre de 2014, 12:51
 */

#ifndef INTERRUPCIONES_H
#define	INTERRUPCIONES_H


#include "funciones.h"
#include "main.h"
#include "bluetooth.h"



void interrupcion _T1Interrupt(void);
void interrupcion _T3Interrupt(void);
void Delay_Nop(unsigned int _contador);
void Config_PID_T1(void);
void StartTimer3(unsigned int _milisegundos);
void DelayXmsT5(int _msg);

//          _                                               _                     _
//         | |_    ___   _ __ ___    _ __     ___    _ __  (_)  ____   __ _    __| |   ___    _ __    ___   ___            //
//         | __|  / _ \ | '_ ` _ \  | '_ \   / _ \  | '__| | | |_  /  / _` |  / _` |  / _ \  | '__|  / _ \ / __|            //
//         | |_  |  __/ | | | | | | | |_) | | (_) | | |    | |  / /  | (_| | | (_| | | (_) | | |    |  __/ \__ \            //
//          \__|  \___| |_| |_| |_| | .__/   \___/  |_|    |_| /___|  \__,_|  \__,_|  \___/  |_|     \___| |___/            //
//                                  |_|                                                                                     //

void Delay_Nop(unsigned int _contador) {
    while (_contador > 0) {
        Nop();
        _contador--;
    }
}

void Config_PID_T1(void) {
    T1CON = 0b0000000000010000; // Preescala 1:8
    PR1 = 0x1CC0; // 2 msg
    TMR1 = 0;
    IFS0bits.T1IF = 0;
    T1CONbits.TON = 1;
    _T1IE = 1;
}

void Delay1msT5(void) {
    T5CON = 0b0000000000010000; // Preescala 1:8
    PR5 = 0x0E60; // 0x0E30 segun excel
    TMR5 = 0;
    IFS1bits.T5IF = 0;
    T5CONbits.TON = 1;
    _T5IE = 0;
    while (IFS1bits.T5IF == 0);
    T5CONbits.TON = 0;
}

void DelayXmsT5(int _msg) {
    do {
        Delay1msT5();
        _msg--;
    } while (_msg > 0);

}

void StartTimer3(unsigned int _milisegundos) {
    IPC1bits.T3IP = 0b111;
    IFS0bits.T3IF = 0; // Timer 3
    T2CONbits.T32 = 0;
    T3CONbits.TON = 0;
    T3CONbits.TSIDL = 0;
    T3CONbits.TGATE = 0;
    T3CONbits.TCKPS = 0b01; //Preescaler 1:2
    T3CONbits.TCS = 0;
    PR3 = 0x0990; // 0x0E30 segun excel
    TMR3 = 0;
    IFS0bits.T3IF = 0;
    T3CONbits.TON = 1;
    IEC0bits.T3IE = 1;
}


//           _           _                                                 _
//          (_)  _ __   | |_    ___   _ __   _ __   _   _   _ __     ___  (_)   ___    _ __     ___   ___            //
//          | | | '_ \  | __|  / _ \ | '__| | '__| | | | | | '_ \   / __| | |  / _ \  | '_ \   / _ \ / __|            //
//          | | | | | | | |_  |  __/ | |    | |    | |_| | | |_) | | (__  | | | (_) | | | | | |  __/ \__ \            //
//          |_| |_| |_|  \__|  \___| |_|    |_|     \__,_| | .__/   \___| |_|  \___/  |_| |_|  \___| |___/            //
//                                                         |_|                                                          //



void interrupcion _T1Interrupt(void)        // Se ejecuta cada 2msg
{
    _T1IF = 0;
    controladora();
   //pid
}
void interrupcion _T3Interrupt(void)
{

    _T3IF = 0;

}
void interrupcion _INT2Interrupt(void)
{
_INT2IF = 0;
}


#endif	/* INTERRUPCIONES_H */

