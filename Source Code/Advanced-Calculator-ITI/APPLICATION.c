/*
 * APPLICATION.c
 *
 *
 * Author: Ahmed Zahran
 */

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO.h"
#include "LCD.h"
#include "KPD.h"



void APP_VidInit(void){
	KPD_VidInit();
	LCD_VidInit();

}

