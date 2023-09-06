#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/io.h>
#include <util/delay.h>

#include "DIO.h"
#include "KPD.h"
#include "LCD.h"
u8 KPD_Au8Keys[4][4] = KPD_KEYS;
u8 KPD_ADVANCED_Au8Keys[4][4] = KPD_ADVANCED_KEYS;

u8 KPD_Au8_RowPins[4] = {KPD_R1_PIN , KPD_R2_PIN , KPD_R3_PIN , KPD_R4_PIN};
u8 KPD_Au8_ColPins[4] = {KPD_C1_PIN , KPD_C2_PIN , KPD_C3_PIN , KPD_C4_PIN};
u8 KPD_ADVANCED_Au8_RowPins[4] = {KPD_ADVANCED_R1_PIN,\
		KPD_ADVANCED_R2_PIN,KPD_ADVANCED_R3_PIN,KPD_ADVANCED_R4_PIN};
u8 KPD_ADVANCED_Au8_ColPins[4] = {KPD_ADVANCED_C1_PIN,\
		KPD_ADVANCED_C2_PIN,KPD_ADVANCED_C3_PIN,KPD_ADVANCED_C4_PIN};

void KPD_VidInit(void)
{
	DIO_VidSetPortDirection(KPD_PORT,0x0f);
	DIO_VidSetPortValue(KPD_PORT,0xff);
}
void KPD_ADVANCED_VidInit(void)
{
	DIO_VidSetPortDirection(KPD_ADVANCED_PORT,0x0f);
	DIO_VidSetPortValue(KPD_ADVANCED_PORT,0xff);
}

u8 KPD_U8PressedKey(void)
{
	u8 Local_U8CounterR,Local_U8CounterC,Local_U8Pressed,Local_U8Pressed2,Local_U8Flag=0;
	u8 Local_U8ReturnedKey=KPD_CHECK;

	for(Local_U8CounterR=0;Local_U8CounterR<4;Local_U8CounterR++)
	{
		DIO_VidSetPinValue(KPD_PORT,KPD_Au8_RowPins[Local_U8CounterR],DIO_LOW);
		DIO_VidSetPinValue(KPD_ADVANCED_PORT,KPD_ADVANCED_Au8_RowPins[Local_U8CounterR],DIO_LOW);
		for(Local_U8CounterC=0;Local_U8CounterC<4;Local_U8CounterC++)
		{
			Local_U8Pressed=DIO_GetPinValue(KPD_PORT,KPD_Au8_ColPins[Local_U8CounterC]);
			Local_U8Pressed2 = DIO_GetPinValue(KPD_ADVANCED_PORT,KPD_ADVANCED_Au8_ColPins[Local_U8CounterC]);
			if(Local_U8Pressed==DIO_LOW)
			{
				_delay_ms(20);
				while(Local_U8Pressed==DIO_LOW)
				{
					Local_U8Pressed=DIO_GetPinValue(KPD_PORT,KPD_Au8_ColPins[Local_U8CounterC]);
				}
				Local_U8ReturnedKey=KPD_Au8Keys[Local_U8CounterR][Local_U8CounterC];
				Local_U8Flag=1;
				break;
			}
			else if(Local_U8Pressed2 == DIO_LOW){
				_delay_ms(20);
				while(Local_U8Pressed2==DIO_LOW)
				{
					Local_U8Pressed=DIO_GetPinValue(KPD_ADVANCED_PORT,KPD_ADVANCED_Au8_ColPins[Local_U8CounterC]);
				}
				Local_U8ReturnedKey=KPD_ADVANCED_Au8Keys[Local_U8CounterR][Local_U8CounterC];



			}
		}
		DIO_VidSetPinValue(KPD_PORT,KPD_Au8_RowPins[Local_U8CounterR],DIO_HIGH);
		if(Local_U8Flag==1)break;
	}

	return Local_U8ReturnedKey;

}

void KPD_VidValidatePassword(void){
	u8 Local_U8Count,	Local_U8ReturnedKey=KPD_CHECK, Local_U8ValidFlag=1;
	LCD_VidSendString("Enter PIN:");

	for(Local_U8Count = 0; Local_U8Count<PASSWORD_SIZE;Local_U8Count++){
		Local_U8ReturnedKey=KPD_CHECK;
		while(Local_U8ReturnedKey == KPD_CHECK){
		Local_U8ReturnedKey = KPD_U8PressedKey();
		}
			LCD_VidSendChar(Local_U8ReturnedKey);

			if(Local_U8ReturnedKey == (PASSWORD)[Local_U8Count]){
				continue;
			}
			else{
				Local_U8ValidFlag = 0;
			}
	}
	if(Local_U8ValidFlag == 1){
	LCD_VidSendCMD(0X01);
	_delay_ms(2);
	LCD_VidSendString("Correct PIN");
	}
	else if(Local_U8ValidFlag == 0){
		LCD_VidSendCMD(0x01);/*Clear screen*/
		_delay_ms(2);
		LCD_VidSendString("Incorrect PIN");
	}
}








