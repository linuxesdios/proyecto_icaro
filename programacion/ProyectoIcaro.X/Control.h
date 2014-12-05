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

int leer_iz_der(){
    if(S0=1)return 0;
    if(S1=1)return 1;
    if(S2=1)return 2;
    if(S3=1)return 3;
    if(S4=1)return 4;
    if(S5=1)return 5;
    if(S6=1)return 6;
    if(S7=1)return 7;
    if(S8=1)return 8;
    if(S9=1)return 9;
    if(S10=1)return 10;
    if(S11=1)return 11;
}
int leer_der_iz(){
    if(S11=1)return 11;
    if(S10=1)return 10;
    if(S9=1)return 9;
    if(S8=1)return 8;
    if(S7=1)return 7;
    if(S6=1)return 6;
    if(S5=1)return 5;
    if(S4=1)return 4;
    if(S3=1)return 3;
    if(S2=1)return 2;
    if(S1=1)return 1;
    if(S0=1)return 0;
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

int leer(){
    return leer_iz_der()+leer_der_iz()-REFERENCIA;
}
int pid(int lectura) {
   if(lectura==0){LED1=0;}else{LED1=1;}
  signed int errorLeido =0;
  signed int resultado=0;
  errorLeido = lectura;
  resultado = errorLeido*kp;  //Parte proporcional;
  resultado = resultado + (errorLeido - errorAnt)*kd;    //Anadido parte derivativa
  errorAnt=errorLeido;
  return resultado;
}
void controladora(){
    int _controlador=pid(leer());
    PonMotores((Bias+_controlador), (Bias-_controlador));
}
#endif	/* PID_H */

