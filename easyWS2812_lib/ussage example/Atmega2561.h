/************************************************************************************
*	Projekt:	LED_Controller_							 _.-^^---....,,--_			*
*	Autor:		Samuel Lüthi						 _--*%ç&*ç&*%&*%&*&*bb--_		*
*	Datum:		16.12.2021							<#ç``+@¬|( ´~¢|¬(%&¬|fegh>)		*
*												    |tradgrtgrt67584322423h6jp|		*
*													 \._ .;7gi&/&%hu89o99$8$_./		*
*														```--. . , ; .--'''			*
*															  | |   |				*
*														   .-=||  | |=-.			*
*														   `-=#$%&%$#=-'			*
*															  | ;  :|				*
*													 _____.,-#%&$@%#&#~,._____		*
************************************************************************************/


/***analog comparator defines ***/
#define ACSR_INIT   0x00    			//value for the AC-controlregister: ACD = true (deactivate analog comparator)

/*** portA-defines ***/
#define PORTA_IO_CONFIG          0xFF   //IO-configuration: 0 = input / 1 = output
#define PORTA_SIGNAL_CONFIG      0x00   //define default-logic level (if input: 1 = Pullup / 0 = Tri-state)

/*** portB-defines ***/
#define PORTB_IO_CONFIG          0xFF   //IO-configuration: 0 = input / 1 = output
#define PORTB_SIGNAL_CONFIG      0x00   //define default-logic level (if input: 1 = Pullup / 0 = Tri-state)

/*** portC-defines ***/
#define PORTC_IO_CONFIG          0xFF   //IO-configuration: 0 = input / 1 = output
#define PORTC_SIGNAL_CONFIG      0x00   //define default-logic level (if input: 1 = Pullup / 0 = Tri-state)

/*** portD-defines ***/
#define PORTD_IO_CONFIG          0x00   //IO-configuration: 0 = input / 1 = output
#define PORTD_SIGNAL_CONFIG      0x00   //define default-logic level (if input: 1 = Pullup / 0 = Tri-state)

/*** portE-defines ***/
// #define PORTE_IO_CONFIG			 0x00   //IO-configuration: 0 = input / 1 = output
// #define PORTE_SIGNAL_CONFIG	     0x00   //define default-logic level (if input: 1 = Pullup / 0 = Tri-state)
// /*** portF-defines ***/
// #define PORTF_IO_CONFIG          0x00   //IO-configuration: 0 = input / 1 = output
// #define PORTF_SIGNAL_CONFIG      0xFF   //define default-logic level (if input: 1 = Pullup / 0 = Tri-state)
// 
// /*** portG-defines (6-Bit) ***/
// #define PORTG_IO_CONFIG          0xFF   //IO-configuration: 0 = input / 1 = output
// #define PORTG_SIGNAL_CONFIG      0x00   //define default-logic level (if input: 1 = Pullup / 0 = Tri-state)

/*** portpin-defines ***/
#define PORTB_0                  0x01    //PortB-0 / Input/Output
#define PORTB_1					 0x02    //PortB-1 / Input/Output
#define PORTB_2					 0x04    //PortB-2 / Input/Output
#define PORTB_3                  0x08    //PortB-3 / Input/Output
#define PORTB_4                  0x10    //PortB-4 / Input/Output
#define PORTB_5					 0x20    //PortB-5 / Input/Output
#define PORTB_6					 0x40    //PortB-6 / Input/Output
#define PORTB_7	        		 0x80    //PortB-7 / Input/Output

#define PORTD_0                  0x01    //PortD-0 / Input/Output
#define PORTD_1                  0x02    //PortD-1 / Input/Output
#define PORTD_2                  0x04    //PortD-2 / Input/Output
#define PORTD_3                  0x08    //PortD-3 / Input/Output
#define PORTD_4                  0x10    //PortD-4 / Input/Output
#define PORTD_5                  0x20    //PortD-5 / Input/Output
#define PORTD_6                  0x40    //PortD-6 / Input/Output
#define PORTD_7                  0x80    //PortD-7 / Input/Output

/***interrupt-defines***/
#define TIMER0_INTERRUPT_ENABLE  0x02  	 //Timer0-Interruptinitialisierung

/***timer/counter0-defines***/
#define T0_TCCR0A_INIT          0x02   	 //initialization value for the Timer0A-controlregister
#define T0_TCCR0B_INIT          0x03     //initialization value for the Timer0B-controllregister
#define T0_TCNT0A_INIT          0x00   	 //initialization value for theTimer0A-countgister.
#define T0_OCR0A_INIT           0xFA     //initialization value for the Timer0A-Comparematch-register (on 16MHz 0xFA is reached all 1ms)
/***time-constant***/
#define TIME_CNT_MS_RESET		0		 //reset value for the millisecond counter

/*** System defines ***/
#define TRUE					1
#define FALSE					0

#define LEDs					200


/*** System Variablen ***/
unsigned char i;							// Zählvariable für For-Schleifen


unsigned int uiCircle;

	
unsigned int iADCLcash;
unsigned int iADCHcash;



/***function prototypes***/
void SystemInit( void );      							//initialize ports

