#include <avr/io.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"

void DIO_VidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {
if(Copy_u8Direction==1) {
	switch(Copy_u8Port) {
		case PORT_A : SET_BIT(DDRA,Copy_u8Pin);break;
		case PORT_B : SET_BIT(DDRB,Copy_u8Pin);break;
		case PORT_C : SET_BIT(DDRC,Copy_u8Pin);break;
		case PORT_D : SET_BIT(DDRD,Copy_u8Pin);break;
	}

}
else if(Copy_u8Direction == 0) {
	switch(Copy_u8Port) {
		case PORT_A : CLR_BIT(DDRA,Copy_u8Pin);break;
		case PORT_B : CLR_BIT(DDRB,Copy_u8Pin);break;
		case PORT_C : CLR_BIT(DDRC,Copy_u8Pin);break;
		case PORT_D : CLR_BIT(DDRD,Copy_u8Pin);break;

	}

}
}
void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
	if(Copy_u8Value==1) {
		switch(Copy_u8Port) {
			case PORT_A : SET_BIT(PORTA,Copy_u8Pin);break;
			case PORT_B : SET_BIT(PORTB,Copy_u8Pin);break;
			case PORT_C : SET_BIT(PORTC,Copy_u8Pin);break;
			case PORT_D : SET_BIT(PORTD,Copy_u8Pin);break;
		}

	}
	else if(Copy_u8Value== 0) {
		switch(Copy_u8Port) {
			case PORT_A : CLR_BIT(PORTA,Copy_u8Pin);break;
			case PORT_B : CLR_BIT(PORTB,Copy_u8Pin);break;
			case PORT_C : CLR_BIT(PORTC,Copy_u8Pin);break;
			case PORT_D : CLR_BIT(PORTD,Copy_u8Pin);break;

		}

	}

}
void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8PortDirection){
	switch (Copy_u8Port){
	case PORT_A: DDRA = Copy_u8PortDirection;break;
	case PORT_B: DDRB = Copy_u8PortDirection;break;
	case PORT_C: DDRC = Copy_u8PortDirection;break;
	case PORT_D: DDRD = Copy_u8PortDirection;break;
	}
}
void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value){
	switch (Copy_u8Port){
	case PORT_A: PORTA = Copy_u8Value;break;
	case PORT_B: PORTB = Copy_u8Value;break;
	case PORT_C: PORTC = Copy_u8Value;break;
	case PORT_D: PORTD = Copy_u8Value;break;
	}
}

u8 DIO_GetPinValue (u8 Copy_u8Port,u8 Copy_u8Pin){
	u8 return_value;
	switch (Copy_u8Port){
	case PORT_A: return_value= GET_BIT(PINA,Copy_u8Pin);break;
	case PORT_B: return_value= GET_BIT(PINB,Copy_u8Pin);break;
	case PORT_C: return_value= GET_BIT(PINC,Copy_u8Pin);break;
	case PORT_D: return_value= GET_BIT(PIND,Copy_u8Pin);break;
	}
	return return_value;

}
void DIO_Toggle(u8 Copy_u8Port,u8 Copy_u8PortValue){
	switch (Copy_u8Port){
	case PORT_A: PORTA ^= Copy_u8PortValue;break;
	case PORT_B: PORTB ^= Copy_u8PortValue;break;
	case PORT_C: PORTC ^= Copy_u8PortValue;break;
	case PORT_D: PORTD ^= Copy_u8PortValue;break;
	}
}


