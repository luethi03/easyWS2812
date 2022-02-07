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


/***function prototypes***/
uint32_t HSV_to_RGB(unsigned int, unsigned char, unsigned char, unsigned char, unsigned int );				//convert HSV to RGB
void LED_WRITE( unsigned int, unsigned char, unsigned char, unsigned char );						//write color to stripe
