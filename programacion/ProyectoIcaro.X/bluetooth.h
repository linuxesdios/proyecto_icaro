
#ifndef BLUETOOTH_H
#define	BLUETOOTH_H

extern char str_blue[40];
extern char str_aux[40];
#define MAX_BLUE    50
#define DEF_BLUE    1

void EnviarCR()
{
#ifdef DEF_BLUE
    U2TXREG = '\r';
    while (!U2STAbits.TRMT);
    U2TXREG = '\n';
    while (!U2STAbits.TRMT);
#endif
}

void enviar_datos_NOCR(char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    for (index = 0; index < longitud; index++)
    {
        U2TXREG = cadena[index];
        while (!U2STAbits.TRMT);
    }
#endif
}

void enviar_datos(char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    enviar_datos_NOCR(cadena, longitud);
    EnviarCR();
#endif
}

void enviar_Udatos_NOCR(unsigned char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    for (index = 0; index < longitud; index++)
    {
        U2TXREG = cadena[index];
        while (!U2STAbits.TRMT);
    }
#endif
}

void enviar_Udatos(unsigned char cadena[50], int longitud)
{
#ifdef DEF_BLUE
    enviar_Udatos_NOCR(cadena, longitud);
    EnviarCR();
#endif
}


void enviar_valor(char nombre[], int valor)
{

    enviar_datos_NOCR(nombre, strlen(nombre));
    itoa(str_blue, valor, 10);
    enviar_datos(str_blue, strlen(str_blue));

}

void enviar_valor_NOCR(char nombre[], int valor)
{

    enviar_datos_NOCR(nombre, strlen(nombre));
    itoa(str_blue, valor, 10);
    enviar_datos_NOCR(str_blue, strlen(str_blue));

}

void enviar_mensaje(char nombre[])
{
    enviar_datos(nombre, strlen(nombre));
}

void enviar_mensaje_NOCR(char nombre[])
{
    enviar_datos_NOCR(nombre, strlen(nombre));
}

// Variables globales
char DatoRecibido[50];
int IndiceBluetooth;

// Funcion de interrupcion de recepcion de datos

// Funcion para procear los datos recibidos


void enviar_datos_int_NOCR(int cadena[50], int _longitud)
{
#ifdef DEF_BLUE
    unsigned char index;
    char aux[1];
    //    itoa(str_blue,_longitud,10);
    //    enviar_datos(str_blue,strlen(str_blue));

    for (index = 0; index < _longitud >> 1; index++)
    {
        aux[0] = cadena[index];
        U2TXREG = aux[0];
        while (!U2STAbits.TRMT);

        aux[0] = cadena[index] >> 8;

        U2TXREG = aux[0];
        while (!U2STAbits.TRMT);
    }
#endif
}
void plot1(int valor1)
{
        int encabezado[3];
        encabezado[0]=0xCDAB;
        encabezado[1]= 2*sizeof(int);
        encabezado[2]=valor1;
        int pktSize = 2 + 2 + (1*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot2(int valor1, int valor2)
{
        int encabezado[4];
        encabezado[0]=0xCDAB;
        encabezado[1]= 2*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        int pktSize = 2 + 2 + (2*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot3(int valor1, int valor2,int valor3)
{
        int encabezado[5];
        encabezado[0]=0xCDAB;
        encabezado[1]= 3*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        encabezado[4]=valor3;
        int pktSize = 2 + 2 + (3*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}
void plot4(int valor1, int valor2,int valor3,int valor4)
{
        int encabezado[6];
        encabezado[0]=0xCDAB;
        encabezado[1]= 4*sizeof(int);
        encabezado[2]=valor1;
        encabezado[3]=valor2;
        encabezado[4]=valor3;
        encabezado[5]=valor4;
        int pktSize = 2 + 2 + (4*sizeof(int));
        enviar_datos_NOCR((int * )encabezado, pktSize);

}


#endif	/* BLUETOOTH_H */

