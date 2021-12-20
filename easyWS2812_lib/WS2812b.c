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
#include <avr/io.h>
#include <math.h>

/*** Projekt-Includes ***/
#include "WS2812b.h"


uint32_t HSV_to_RGB(unsigned int uiH, unsigned char ucS, unsigned char ucV, unsigned char ucDirectSend, unsigned int uiLEDs)
{
	unsigned char ucRn;
	unsigned char ucGn;
	unsigned char ucBn;
	unsigned int diff;
	
	if(uiH<61)
	{
		ucRn = 255;
		ucBn = 0;
		ucGn = 4.25 * uiH;
	}
	else if(uiH < 121)
	{
		ucGn = 255;
		ucBn = 0;
		ucRn = 255 - (4.25 * (uiH-60));
	}
	else if(uiH < 181)
	{
		ucRn = 0;
		ucGn = 255;
		ucBn = 4.25 * (uiH-120);
	}
	else if(uiH < 241)
	{
		ucRn = 0;
		ucBn = 255;
		ucGn = 255 - (4.25 * (uiH-180));
	}
	else if(uiH < 301)
	{
		ucGn = 0;
		ucBn = 255;
		ucRn = 4.25 * (uiH-240);
	}
	else if(uiH< 360)
	{
		ucRn = 255;
		ucGn = 0;
		ucBn = 255 - (4.25 * (uiH-300));
	}
	
	ucS = 100 - ucS; //Kehrwert berechnen
	diff = ((255 - ucRn) * ucS)/100;
	ucRn = ucRn + diff;
	diff = ((255 - ucGn) * ucS)/100;
	ucGn = ucGn + diff;
	diff = ((255 - ucBn) * ucS)/100;
	ucBn = ucBn + diff;
	
	
	ucV = pow(ucV,1.0f/1.1f);
	
	if (ucRn != 0)
	{
		ucRn = (ucRn * ucV)/100;
	}
	
	if (ucGn != 0)
	{
		ucGn = (ucGn * ucV)/100;
	}
	
	if (ucBn != 0)
	{
		ucBn = (ucBn * ucV)/100;
	}
	
	
	if (ucDirectSend  == 1)
	{
		LED_WRITE(uiLEDs, ucRn, ucGn, ucBn);
		return 0;
	}
	else
	{
		uint32_t uiColor;
		uiColor = ((ucRn  << 16) | (ucGn << 8) | ucBn);
		return uiColor;
	}
	
}

void LED_WRITE(unsigned int uiLEDs, unsigned char ucR, unsigned char ucG, unsigned char ucB)
{
    /* EasyCODE < */
    for ( int i = 0; i < uiLEDs; i ++ )
	{
	
		if ( ucG & 0x80 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
	
		if ( ucG & 0x40 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucG & 0x20 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucG & 0x10 )
		{
			OUTPORT = 0xFF;
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
		   asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucG & 0x08 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucG & 0x04 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucG & 0x02 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucG & 0x01 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( (ucR & 0x80) )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucR & 0x40 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucR & 0x20 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucR & 0x10 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucR& 0x08 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucR & 0x04 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucR& 0x02 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucR & 0x01 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucB & 0x80 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucB & 0x40 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucB & 0x20 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucB & 0x10 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucB & 0x08 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucB & 0x04 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucB & 0x02 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		
		if ( ucB & 0x01 )
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
		else
		{
			OUTPORT = 0xFF;
			asm("nop;");
			asm("nop;");
			OUTPORT = 0x00;
		}
	}
}
