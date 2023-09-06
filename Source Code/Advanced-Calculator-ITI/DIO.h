#ifndef DIO_H_
#define DIO_H_
//Ports: Underscore to avoid conflict with PORTA,PORTB,PORTC,PORTD
#define PORT_A  0
#define PORT_B  1
#define PORT_C  2
#define PORT_D  3

void DIO_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);
void DIO_VidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8PortDirection);
void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
u8 DIO_GetPinValue (u8 Copy_u8Port,u8 Copy_u8Pin);
void DIO_Toggle(u8 Copy_u8Port,u8 Copy_u8PortValue);



#define DIO_PORT_OUTPUT			0xff
#define DIO_PORT_INPUT			0x00
#define DIO_HIGH				1
#define DIO_LOW					0

#define PIN_0					0
#define PIN_1					1
#define PIN_2					2
#define PIN_3					3
#define PIN_4					4
#define PIN_5					5
#define PIN_6					6
#define PIN_7					7


#endif
