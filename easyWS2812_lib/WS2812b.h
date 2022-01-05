/************************************************************************************
*	Projekt:	LED_Controller_			                        	 _.-^^---....,,--_	  		*
*	Autor:		Samuel Lüthi	          			              _--*%ç&*ç&*%&*%&*&*bb--_		*
*	Datum:		16.12.2021					                  		<#ç``+@¬|( ´~¢|¬(%&¬|fegh>)		*
*												                              |tradgrtgrt67584322423h6jp|		*
*													                             \._ .;7gi&/&%hu89o99$8$_./		*
*														                               ```--. . , ; .--'''			*
*															                                   | |   |	    			*
*														                                  .-=||  | |=-.		    	*
*														                                  `-=#$%&%$#=-'			    *
*															                                   | ;  :|				    *
*													                              _____.,-#%&$@%#&#~,._____		*
************************************************************************************/
#ifdef SIXTEEN

	#define NOPON asm("nop\n\tnop\n\t");
	#define NOPOFF asm("nop\n\t");
#endif

#ifdef EIGHT

#define NOPON asm("nop\n\t");
#define NOPOFF 

#endif

/*** System Variablen ***/
unsigned char i;							// Zählvariable für For-Schleifen

/***function prototypes***/
void LED_WRITE( unsigned int, unsigned char, unsigned char, unsigned char );							//write color to stripe
uint32_t HSV_to_RGB(unsigned int, unsigned char, unsigned char, unsigned char, unsigned int );				//convert HSV to RGB

