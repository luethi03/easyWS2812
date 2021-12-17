/************************************************************************************
*	Project:	LED_Controller    	__.-^^---....,,--_		    *
*	Autor:		Samuel Lüthi	      _--*%ç&*ç&*%&*%&*&*bb--_		    *
*	Datum:		16.12.2021	     <#ç``+@¬|( ´~¢|¬(%&¬|fegh>)	    *
*				             |tradgrtgrt67584322423h6jp|	    *
*					      \._ .;7gi&/&%hu89o99$8$_./	    *
*						```--. . , ; .--'''		    *
*						       | |   |			    *
*					 	    .-=||  | |=-.		    *
*						    `-=#$%&%$#=-'		    *
*						       | ;  :|			    *
*					      _____.,-#%&$@%#&#~,._____	   	    *
************************************************************************************/


/*** AVR-Includes ***/
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h> 
#include <util/delay.h>
#include <math.h>

/*** Projekt-Includes ***/
#include "Atmega2561.h"


int main (void)
{
    SystemInit();																	//call System_Init
	
	iS = 100;
	iV = 100;
	
	/*** Initializing sequence ***/
	for (int i = 0; i <= 180; i++)
	{
		iH = 2*i;
		HSV_to_RGB();
		uiR = uiRn;
		uiG = uiGn;
		uiB = uiBn;
		LED_WRITE(i);
		uiR = 0;
		uiG = 0;
		uiB = 0;
		LED_WRITE(360 - i * 2);
		uiR = uiRn;
		uiG = uiGn;
		uiB = uiBn;
		LED_WRITE(i)
		_delay_ms(10);
	}
	
    /***Loop o' infinity***/
    while ( TRUE )
    {
		/*** WRITE CODE HERE ***/
		
		char cPinD;
		cPinD = PIND;
		
		switch (cPinD)
		{
		case 0b00000000 :
			/***analog signal to rgb***/
			break;
		}
		
		/*** decide when to send the data and call the function that sends it ***/
		if((uiR != uiR) | (uiG != uiGn) | (uiB != uiBn))
		{
			uiR = uiRn;
			uiG = uiGn;
			uiB = uiBn;
			
			LED_WRITE(1000);
		}
		_delay_ms(10);	
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


void LED_WRITE(unsigned int uiLEDs)
{
    /* EasyCODE < */
    for ( int i = 0; i < uiLEDs; i ++ )
	{
	
		if ( uiG & 0x80 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
	
		if ( uiG & 0x40 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiG & 0x20 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiG & 0x10 )
		{
			PORTB = 0xFF;
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiG & 0x08 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiG & 0x04 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiG & 0x02 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiG & 0x01 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( (uiR & 0x80) )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiR & 0x40 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiR & 0x20 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiR & 0x10 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiR& 0x08 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiR & 0x04 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiR& 0x02 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiR & 0x01 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiB & 0x80 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiB & 0x40 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiB & 0x20 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiB & 0x10 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiB & 0x08 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiB & 0x04 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiB & 0x02 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		
		if ( uiB & 0x01 )
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
		else
		{
			PORTB = 0xFF;
			asm("nop;");
			asm("nop;");
			PORTB = 0x00;
		}
	}
}


void HSV_to_RGB()
{
	
    if(iH<61)
    {
    	uiRn = 255;
    	uiBn = 0;
    	uiGn = 4.25 * iH;
    }
    else if(iH < 121)
    {
		uiGn = 255;
    	uiBn = 0;
    	uiRn = 255 - (4.25 * (iH-60));
    }
    else if(iH < 181)
    {
    	uiRn = 0;
    	uiGn = 255;
    	uiBn = 4.25 * (iH-120);
    }
    else if(iH < 241)
    {
    	uiRn = 0;
    	uiBn = 255;
    	uiGn = 255 - (4.25 * (iH-180));
    }
    else if(iH < 301)
    {
    	uiGn = 0;
    	uiBn = 255;
    	uiRn = 4.25 * (iH-240);
    }
    else if(iH< 360)
    {
    	uiRn = 255;
    	uiGn = 0;
    	uiBn = 255 - (4.25 * (iH-300));
    }
	
    iS = 100 - iS; //Kehrwert berechnen
    diff = ((255 - uiRn) * iS)/100;
    uiR = uiR + diff;
    diff = ((255 - uiGn) * iS)/100;
    uiG = uiG + diff;
    diff = ((255 - uiBn) * iS)/100;
    uiB = uiB + diff;
	
	
	iV = pow(iV,1.0f/1.1f);
	
    if (uiRn != 0) 
    {
    	uiRn = (uiRn * iV)/100;
    }
    	
    if (uiGn != 0)
    {
    	uiGn = (uiGn * iV)/100;
    }
    
    if (uiBn != 0)
    {
    	uiBn = (uiBn * iV)/100;
    }
	
	
	
	
}
