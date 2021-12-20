/************************************************************************************
*	Project:	LED_Controller_							 _.-^^---....,,--_			*
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


/*** AVR-Includes ***/
#define F_CPU 16000000
#define OUTPORT PORTB
#include <avr/io.h>
#include <util/delay.h>

/*** Projekt-Includes ***/
#include "Atmega2561.h"
#include "WS/WS2812b.c"

int main (void)
{
    SystemInit();																	//call System_Init
	
	
    /***Loop o' infinity***/
    while ( TRUE )																	//endless loop
    {
		if (PIND & 0x01)
		{
			LED_WRITE(20, 0x05, 0x00, 0x00);
			_delay_ms(100);
		}
		
		if (PIND & 0x02)
		{
			HSV_to_RGB(300, 100, 5, 1, 20);
			_delay_ms(100);
		}
		
		if (PIND & 0x04)
		{
			uint32_t uiColor = HSV_to_RGB(180, 100, 5, 0, 0);
			LED_WRITE(20, ((uiColor >> 16) & 0xFF), ((uiColor >> 8) & 0xFF), (uiColor & 0xFF));
			_delay_ms(100);
		}
		if (PIND & 0x08)
		{
			LED_WRITE(20, 0, 0, 0);
			_delay_ms(100);
		}
    }
}


void SystemInit (void)
{
    /***initialize analog comparator***/
    ACSR = ACSR_INIT;                           //deactivate comparator to reduce power         
	   
    /***initialize portB***/
    DDRB = PORTB_IO_CONFIG;                     //set IO-config
    PORTB = PORTB_SIGNAL_CONFIG;                //set start value and Pullup configuration                
	
    /***initialize portC***/
    DDRC = PORTC_IO_CONFIG;                     //set IO-config
    PORTC = PORTC_SIGNAL_CONFIG;                //set start value and Pullup configuration
	       
    /***initialize portD***/
    DDRD = PORTD_IO_CONFIG;                     //set IO-config
    PORTD = PORTD_SIGNAL_CONFIG;                //set start value and Pullup configuration	
}

