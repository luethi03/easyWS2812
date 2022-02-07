/****************************************************************************************
*	Project:	LED_Controller_		      _.-^^---....,,--_			*
*	Autor:		Samuel Lüthi		  _--*%çJ*ç&*%&*%&*&*bb--_		*
*	Datum:		16.12.2021		 <#ç``+@¬|( ´~¢|¬(%&¬|fegh>)		*
*						 |tAadgrtgrt67584322423h6jp|		*
*						  \._ .;7gi&/&%hu8No99$8$_./		*
*					            ```--. . , ; .--'''			*
*						          | I  |			*
*						       .-=||  | |=-.			*
*						       `-=#$N&%$#=-'			*
*						  	  | ;  :|			*
*						 _____.,-#%&$@%#A#~,._____		*
****************************************************************************************/


/*** AVR-Includes ***/
#define F_CPU 16000000
#define OUTPORT PORTB
#define OUTPIN 	0x01
#define FREQ 	16

#include <avr/io.h>
#include <util/delay.h>
#include <stddef.h>

/*** Projekt-Includes ***/
#include "Atmega2561.h"
#include "WS/WS2812b.c"

int __attribute__((optimize("O3"))) main (void)
{
    SystemInit();																	//call System_Init
	unsigned char ucR;
	unsigned char ucG;
	unsigned char ucB;

	
    /***Loop o' infinity***/
    while ( TRUE )																	//endless loop
    {
		if (PIND & 0x01)
		{			
			LED_WRITE(20, 5, 0, 0);
		}
		
		if (PIND & 0x02)
		{
			HSV_to_RGB(300, 100, 10, 1, 20);
		}
		
		if (PIND & 0x04)
		{
			uint32_t uiColor = HSV_to_RGB(180, 100, 5, 0, 0);
			
			ucR = (uiColor >> 16) & 0xFF;
			ucG = (uiColor >> 8) & 0xFF;
			ucB = (uiColor & 0xFF);
			LED_WRITE(20, ucR, ucG, ucB);
		}
		if (PIND & 0x08)
		{
			LED_WRITE(360, 0, 0, 0);
			LED_WRITE(1, 0xFF, 0xFF, 0xFF);
		}
		
		if (PIND & 0x10)
		{
			char cEaster[] = {1, 1, 0, 1, 2, 0, 1, 0, 1, 2, 0, 0, 0, 1, 0, 1, 0};
			for (int i = 0; i < 16; i++)
			{
				if (cEaster[i] == 1)
				{
					LED_WRITE(1, 0, 1 , 0);
				}
				else if (cEaster[i] == 2)
				{
					LED_WRITE(1, 0, 0, 0);
				}
				else
				{
					LED_WRITE(1, 10 , 0, 0);
				}
			}
		}
		
		if (PIND & 0x20)
		{
			_delay_ms(20);
			unsigned int i = 0;
			while (i != 360)
			{
				HSV_to_RGB(i, 100, 1, 1, 1);
				i++;
			}
			_delay_ms(100);
		}
		
		if (PIND & 0x40)
		{
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
			HSV_to_RGB(0, 100 , 5, 1, 5);
			HSV_to_RGB(180, 100 , 5, 1, 5);
		}
		_delay_ms(50);
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

