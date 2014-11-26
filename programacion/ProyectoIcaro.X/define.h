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

    // -----------------------------------------------------------
    // DEFINE
    // -----------------------------------------------------------
	#define interrupcion	__attribute__((interrupt,no_auto_psv))


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
	



#endif
