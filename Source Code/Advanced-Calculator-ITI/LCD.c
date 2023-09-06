#include <avr/delay.h>
#include "STD_TYPES.h"
#include "DIO.h"
#include "LCD.h"

void LCD_VidInit(void) {

	DIO_VidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	DIO_VidSetPinDirection(LCD_CMD_PORT, RS, DIO_HIGH);
	DIO_VidSetPinDirection(LCD_CMD_PORT, RW, DIO_HIGH);
	DIO_VidSetPinDirection(LCD_CMD_PORT, EN, DIO_HIGH);

	_delay_ms(35);
	/*FUNCTION SET*/
	LCD_VidSendCMD(FUN_SET);
	_delay_ms(1);
	/*DISPLAY ON/OFF Control*/
	LCD_VidSendCMD(C_ON_OFF);
	_delay_ms(1);
	/*Display Clear*/
	LCD_VidSendCMD(LCD_CLR);
	_delay_ms(2);

	/*Entry Mode Set*/

}

void LCD_VidSendCMD(u8 Copy_U8CMD) {
	DIO_VidSetPinValue(LCD_CMD_PORT, RS, DIO_LOW);
	DIO_VidSetPinValue(LCD_CMD_PORT, RW, DIO_LOW);
	DIO_VidSetPortValue(LCD_DATA_PORT, Copy_U8CMD);
	DIO_VidSetPinValue(LCD_CMD_PORT, EN, DIO_HIGH);
	_delay_ms(1);

	DIO_VidSetPinValue(LCD_CMD_PORT, EN, DIO_LOW);
	/*at least 450 ns wide high-to-low pulse is required after this*/
}

void LCD_VidSendChar(u8 Copy_U8Char) {
	DIO_VidSetPinValue(LCD_CMD_PORT, RS, DIO_HIGH);
	DIO_VidSetPinValue(LCD_CMD_PORT, RW, DIO_LOW);
	DIO_VidSetPortValue(LCD_DATA_PORT, Copy_U8Char);
	DIO_VidSetPinValue(LCD_CMD_PORT, EN, DIO_HIGH);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_CMD_PORT, EN, DIO_LOW);
	/*at least 450 ns wide high-to-low pulse is required after this*/
}

void LCD_VidSendString(u8* Copy_PTR) {
	for (u8 Local_U8Index = 0; Copy_PTR[Local_U8Index] != '\0';
			Local_U8Index++) {
		LCD_VidSendChar(Copy_PTR[Local_U8Index]);
	}
}

void LCD_Vid_Select_Line_Column(u8 Copy_U8Line, u8 Copy_U8Column) {
	switch (Copy_U8Line) {
	case 1:
		LCD_VidSendCMD(0X80 + Copy_U8Column);
		break;
	case 2:
		LCD_VidSendCMD(0xc0 + Copy_U8Column);
		break;
	}

}

void LCD_VidSendSpecialChar(u8 Copy_U8CharNum, u8* Copy_U8PTR) {
	u8 Local_U8Counter;
	LCD_VidSendCMD(0x40 + (Copy_U8CharNum * 8));
	for (Local_U8Counter = 0; Local_U8Counter < 8; Local_U8Counter++)
		LCD_VidSendChar(Copy_U8PTR[Local_U8Counter]);
}

void LCD_VidSendNum(u32 Copy_U32Num) {
	u32 Local_U32Count=1;
	if (Copy_U32Num == 0)
		LCD_VidSendChar('0');
	else{
		while (Copy_U32Num / Local_U32Count != 0) {
					Local_U32Count *= 10;
				}
		Local_U32Count/=10;

	while (Local_U32Count != 0) {
		LCD_VidSendChar((Copy_U32Num/Local_U32Count) + '0');
		Copy_U32Num = Copy_U32Num % Local_U32Count;
		Local_U32Count /= 10;


	}
	}
}


