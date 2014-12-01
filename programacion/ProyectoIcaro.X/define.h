/***************************************************************
        Definiciones basicas del funcionamiento del robot.
	
        NO TOCAR O MORIRAS ENTRE TERRIBLES SUFRIMIENTOS
 ****************************************************************/
#ifndef DEFINE_H
#define DEFINE_H

#define OSCCONH_UNLOCK_CODE1    0x78    //First byte in OSCCONH unlock sequence
#define OSCCONH_UNLOCK_CODE2    0x9A    //Second byte in OSCCONH unlock sequence
#define OSCCONL_UNLOCK_CODE1    0x46    //First byte in OSCCONL unlock sequence
#define OSCCONL_UNLOCK_CODE2    0x57    //Second byte in OSCCONL unlock sequence

#define NOSC_PLLOSC     0x07            //PLL source selected by FOSC fuse - FPR bits
#define NOSC_EXTOSC     0x03            //External Oscillator source selected by FOSC fuse - FPR bits
#define NOSC_LPRC       0x02            //Intenal LPRC oscillator
#define NOSC_FRC        0x01            //Internal Fast RC oscillator
#define NOSC_LP         0x00            //Secondary Low-Power 32KHz oscillator on SOSC pins
#define ZERO_MASK_FOR_NOSC_IN_OSCCON 0xF8FF     //NOSC2:NOSC0 mask

#define interrupcion	__attribute__((interrupt,no_auto_psv))

//////////////////////////////////////////////////////////////////////
//         ____    _   _   _____   ____    _____    ___    ____     //
//        |  _ \  | | | | | ____| |  _ \  |_   _|  / _ \  / ___|    //
//        | |_) | | | | | |  _|   | |_) |   | |   | | | | \___ \    //
//        |  __/  | |_| | | |___  |  _ <    | |   | |_| |  ___) |   //
//        |_|      \___/  |_____| |_| \_\   |_|    \___/  |____/    //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#define BOTON_IZQ   	_RB8		// Pulsado = 0;
#define motizq 		OC4RS
#define motder 		OC3RS
#define DIR_MD1 	_LATD8
#define DIR_MD2 	_LATF6
#define DIR_MI1 	_LATC13
#define DIR_MI2 	_LATC14

#define ENC_D   	_RD9
#define ENC_I   	_RA11

#define LED1            _LATC15
#define LED2            _LATD0
#define LED3            _LATF0
#define LED4            _LATD1

#define LED_AZUL        _LATF0
#define LED_AMARILLO    _LATC15
#define LED_VERDE       _LATD0

#define S0 		_RB7
#define S1 		_RB6
#define S2 		_RB5
#define S3 		_RB4
#define S4 		_RB3
#define S5 		_RB2
#define S6 		_RB1
#define S7 		_RB0
#define S8 		_RB9
#define S9 		_RB10
#define S10 		_RB11
#define S11		_RB12


#define ATRAS		0
#define ADELANTE	1
#define STOP		2

#define N           0
#define B           1

//////////////////////////////////////////////////////////////////////////////////////////
//       .___  ___.      ___        ______ .______        ______        _______.        //
//       |   \/   |     /   \      /      ||   _  \      /  __  \      /       |        //
//       |  \  /  |    /  ^  \    |  ,----'|  |_)  |    |  |  |  |    |   (----`        //
//       |  |\/|  |   /  /_\  \   |  |     |      /     |  |  |  |     \   \            //
//       |  |  |  |  /  _____  \  |  `----.|  |\  \----.|  `--'  | .----)   |           //
//       |__|  |__| /__/     \__\  \______|| _| `._____| \______/  |_______/            //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

#define LED_ALL_OFF	LED1 = 0;	 LED2 = 0;	 LED3 = 0;	 LED4 = 0;
#define LED_ALL_ON	LED1 = 1;	 LED2 = 1;	 LED3 = 1;	 LED4 = 1;

#define START_PID   Config_PID_T1();   Nop();   _T1IE = 1;

#define MOT_IZQ_ADEL     DIR_MI1 = 1;Nop();            DIR_MI2 = 0;Nop();
#define MOT_IZQ_ATRAS    DIR_MI1 = 0;Nop();            DIR_MI2 = 1;Nop();
#define MOT_IZQ_STOP     DIR_MI1 = 1;Nop();            DIR_MI2 = 1;Nop();

#define MOT_DER_ADEL     DIR_MD1 = 1;Nop();            DIR_MD2 = 0;Nop();
#define MOT_DER_ATRAS    DIR_MD1 = 0;Nop();            DIR_MD2 = 1;Nop();
#define MOT_DER_STOP     DIR_MD1 = 1;Nop();            DIR_MD2 = 1;Nop();
#define PARAR_ROBOT     MOT_IZQ_STOP;   MOT_DER_STOP; _T1IF = 0;  Nop();   _T1IE = 0; Nop();

//////////////////////////////////////////////////////////////////////////////////////////
//       __     __     _      ____    ___      _      ____    _       _____   ____      //
//       \ \   / /    / \    |  _ \  |_ _|    / \    | __ )  | |     | ____| / ___|     //
//        \ \ / /    / _ \   | |_) |  | |    / _ \   |  _ \  | |     |  _|   \___ \     //
//         \ V /    / ___ \  |  _ <   | |   / ___ \  | |_) | | |___  | |___   ___) |    //
//          \_/    /_/   \_\ |_| \_\ |___| /_/   \_\ |____/  |_____| |_____| |____/     //
//                                                                                      //
//////////////////////////////////////////////////////////////////////////////////////////

int PosicionActual = 0;
int Tmuestreo = 0;
int kp = 0;
int ki = 0;
int kd = 0;
int Maximo = 0;
int Minimo = 0;
int MaximoI = 0;
int MinimoI = 0;
int Bias = 0;

int REFERENCIA;
long V_MAXIMA;

char str_blue[40];
char str_aux[40];


#endif
