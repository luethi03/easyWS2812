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
#include <math.h>

/*** Projekt-Includes ***/
#include "WS2812b.h"


uint32_t __attribute__((optimize("O3"))) HSV_to_RGB(unsigned int uiH, unsigned char ucS, unsigned char ucV, unsigned char ucDirectSend, unsigned int uiLEDs)
{
	uint32_t uiRn = 0;
	uint32_t uiGn = 0;
	uint32_t uiBn = 0;
	unsigned int diff;
	
	/*** calculate hue ***/
	if(uiH<61)
	{
		uiRn = 255;
		uiBn = 0;
		uiGn = 4.25 * uiH;
	}
	else if(uiH < 121)
	{
		uiGn = 255;
		uiBn = 0;
		uiRn = 255 - (4.25 * (uiH-60));
	}
	else if(uiH < 181)
	{
		uiRn = 0;
		uiGn = 255;
		uiBn = 4.25 * (uiH-120);
	}
	else if(uiH < 241)
	{
		uiRn = 0;
		uiBn = 255;
		uiGn = 255 - (4.25 * (uiH-180));
	}
	else if(uiH < 301)
	{
		uiGn = 0;
		uiBn = 255;
		uiRn = 4.25 * (uiH-240);
	}
	else if(uiH < 361)
	{
		uiRn = 255;
		uiGn = 0;
		uiBn = 255 - (4.25 * (uiH-300));
	}
	
	/*** calculate saturation ***/
	ucS = 100 - ucS;
	diff = ((255 - uiRn) * ucS)/100;
	uiRn = uiRn + diff;
	diff = ((255 - uiGn) * ucS)/100;
	uiGn = uiGn + diff;
	diff = ((255 - uiBn) * ucS)/100;
	uiBn = uiBn + diff;
	
	/*** ccalculate value ***/
	ucV = pow(ucV,0.9f);
	
	if (uiRn != 0)
	{
		uiRn = (uiRn * ucV)/100;
	}
	
	if (uiGn != 0)
	{
		uiGn = (uiGn * ucV)/100;
	}
	
	if (uiBn != 0)
	{
		uiBn = (uiBn * ucV)/100;
	}
	
	if (ucDirectSend != 0)
	{
		LED_WRITE(uiLEDs, uiRn, uiGn, uiBn);
	}
	else
	{
		uint32_t uiColor;
		uiColor = ((uiRn  << 16) | (uiGn << 8) | uiBn);
		return uiColor;
	}
	return 0;
}



void  __attribute__((optimize("O0"))) LED_WRITE(unsigned int uiLEDs, unsigned char ucR, unsigned char ucG, unsigned char ucB)
{
	Start:
	uiLEDs --;
	
	if ( ucG & 0x80 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	
	if ( ucG & 0x40 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucG & 0x20 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucG & 0x10 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucG & 0x08 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucG & 0x04 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucG & 0x02 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucG & 0x01 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( (ucR & 0x80) )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucR & 0x40 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucR & 0x20 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucR & 0x10 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucR& 0x08 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucR & 0x04 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucR& 0x02 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucR & 0x01 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucB & 0x80 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucB & 0x40 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucB & 0x20 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucB & 0x10 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucB & 0x08 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucB & 0x04 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucB & 0x02 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	
	if ( ucB & 0x01 )
	{
		OUTPORT = OUTPIN;
		NOPON
		OUTPORT = 0x00;
	}
	else
	{
		OUTPORT = OUTPIN;
		NOPOFF
		OUTPORT = 0x00;
	}
	if (uiLEDs != 0)
	{
		goto Start;
	}
}
