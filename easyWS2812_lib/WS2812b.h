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

#ifndef OUTPORT																								//
	# error "OUTPUT PORT (OUTPORT) IS NOT DEFINED LED_WRITE WON'T WORK!"
	#define OUTPORT _SFR_IO8(0x05)
#endif

#ifndef OUTPIN																								//
	# error "OUTPUT PIN (OUTPIN) IS NOT DEFINED LED_WRITE WON'T WORK!"
	#define OUTPIN 0x00
#endif

#ifndef FREQ																								//
	# error "CPU FREQUENCY (FREQ) IS NOT DEFINED LED_WRITE WON'T WORK!"
	#define NOPON
	#define NOPOFF
#elif FREQ == 16	

	#define NOPON	asm("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
	#define NOPOFF	asm("nop\n\tnop\n\t");
	
#elif FREQ == 10																							//

	#define NOPON	asm("nop\n\tnop\n\tnop\n\tnop\n\t");
	#define NOPOFF	asm("nop\n\t");
	
#endif

/*** defines ***/
#define PIN0 0x01
#define PIN1 0x02
#define PIN2 0x04
#define PIN3 0x08
#define PIN4 0x10
#define PIN5 0x20
#define PIN6 0x40
#define PIN7 0x80


/*** function prototypes ***/
uint32_t HSV_to_RGB(unsigned int uiH, unsigned char ucS, unsigned char ucV, unsigned char ucDirectSend, unsigned int uiLEDs);			//convert HSV to RGB
void LED_WRITE(unsigned int uiLEDs, unsigned char ucR, unsigned char ucG, unsigned char ucB, ucOUTPIN);						//write color to stripe
