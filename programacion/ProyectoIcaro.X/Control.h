/* 
 * File:   PID.h
 * Author: Raul
 *
 * Created on 22 de abril de 2014, 3:39
 */

#ifndef PID_H
#define	PID_H

#include "funciones.h"
#include "main.h"
#include "bluetooth.h"

int leer_iz_der() {
    if (S0 == 0)return 1;
    if (S1 == 0)return 2;
    if (S2 == 0)return 3;
    if (S3 == 0)return 4;
    if (S4 == 0)return 5;
    if (S5 == 0)return 6;
    if (S6 == 0)return 6;
    if (S7 == 0)return 7;
    if (S8 == 0)return 9;
    if (S9 == 0)return 10;
    if (S10 == 0)return 11;
    if (S11 == 0)return 12;
    return (0);
}

int leer_der_iz() {
    if (S11 == 0)return 12;
    if (S10 == 0)return 11;
    if (S9 == 0)return 10;
    if (S8 == 0)return 9;
    if (S7 == 0)return 8;
    if (S6 == 0)return 7;
    if (S5 == 0)return 6;
    if (S4 == 0)return 5;
    if (S3 == 0)return 4;
    if (S2 == 0)return 3;
    if (S1 == 0)return 2;
    if (S0 == 0)return 1;
    return (0);
}

//int leer_iz_der(){
//    if(S0=0)return 0;
//    if(S1=0)return 1;
//    if(S2=0)return 2;
//    if(S3=0)return 3;
//    if(S4=0)return 4;
//    if(S5=0)return 5;
//    if(S6=0)return 6;
//    if(S7=0)return 7;
//    if(S8=0)return 8;
//    if(S9=0)return 9;
//    if(S10=0)return 10;
//    if(S11=0)return 11;
//}
//int leer_der_iz(){
//    if(S11=0)return 11;
//    if(S10=0)return 10;
//    if(S9=0)return 9;
//    if(S8=0)return 8;
//    if(S7=0)return 7;
//    if(S6=0)return 6;
//    if(S5=0)return 5;
//    if(S4=0)return 4;
//    if(S3=0)return 3;
//    if(S2=0)return 2;
//    if(S1=0)return 1;
//    if(S0=0)return 0;
//}

int leer() {
    return leer_iz_der() + leer_der_iz() - REFERENCIA;
}

int pid(int lectura) {
    signed int resultado = 0;
    if (lectura !=0)
        errorLeido = lectura;
    ei_acu = ei_acu + errorLeido;
    resultado = errorLeido*kp; //Parte proporcional;
    resultado = resultado + (errorLeido - errorAnt) * kd; //Anadido parte derivativa

//    resultado = resultado + ei_acu    //a�adido parte integral
    errorAnt = errorLeido;
    return resultado;
}

void controladora() {
    int _controlador = pid(leer());
    PonMotores((Bias + _controlador), (Bias - _controlador));
}
#endif	/* PID_H */

