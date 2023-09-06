/*
 * LCD.h
 *
 *  Created on: Aug 18, 2023
 *      Author: LordKuro4Life
 */
#ifndef LCD_H
#define LCD_H


#include <avr/io.h>
#include "STD_TYPES.h"
#include "DIO.h"


#define LCD_DATA_PORT 		PORT_A
#define LCD_CMD_PORT		PORT_B
#define RS					PB0
#define RW					PB1
#define EN					PB2

#define FUN_SET				0b00111000
/*Last 3 bits -> DB2:ON -> Display ON , DB1:ON -> CURSOR ON, DB0: ON -> BLINK ON*/

#define C_ON_OFF			0b00001111

#define LCD_CLR				0x01




void LCD_VidSendSpecialChar(u8 Copy_U8CharNum,u8* Copy_U8PTR);
void LCD_Vid_Select_Line_Column(u8 Copy_U8Line,u8 Copy_U8Column);
void LCD_VidSendString(u8* Copy_PTR);
void LCD_VidSendChar(u8 Copy_U8Char);
void LCD_VidSendCMD(u8 Copy_U8CMD);
void LCD_VidInit(void);
void LCD_VidSendNum(u32 Copy_U32Num);

#endif
