#ifndef KPD_H_
#define  KPD_H_
#include "DIO.h"
#define KPD_PORT			PORT_C
#define KPD_ADVANCED_PORT 	PORT_D


#define    KPD_R1_PIN        PIN_0
#define    KPD_R2_PIN        PIN_1
#define    KPD_R3_PIN        PIN_2
#define    KPD_R4_PIN        PIN_3

#define    KPD_C1_PIN        PIN_4
#define    KPD_C2_PIN        PIN_5
#define    KPD_C3_PIN        PIN_6
#define    KPD_C4_PIN        PIN_7

#define    KPD_ADVANCED_R1_PIN        PIN_0
#define    KPD_ADVANCED_R2_PIN        PIN_1
#define    KPD_ADVANCED_R3_PIN        PIN_2
#define    KPD_ADVANCED_R4_PIN        PIN_3

#define    KPD_ADVANCED_C1_PIN        PIN_4
#define    KPD_ADVANCED_C2_PIN        PIN_5
#define    KPD_ADVANCED_C3_PIN        PIN_6
#define    KPD_ADVANCED_C4_PIN        PIN_7



#define KPD_CHECK		0xff


#define    KPD_KEYS    	 {{'7','8','9','/'},  \
						  {'4','5','6','x'},  \
						  {'1','2','3','-'},  \
						  {'*','0','=','+'}}

/********************Advanced Keypad*************************/

#define	   KPD_ADVANCED_KEYS		{{'s','c','t','D'},\
									 {'S','C','T','A'},\
									 {'L','l','q','N'},\
									 {'R','(',')','^'}}
#define	SIN						's'
#define	COS 					'c'
#define	TAN						't'
#define DEL						'D'
#define SINH					'S'
#define COSH					'C'
#define TANH					'T'
#define AC						'A'
#define LOG10					'L'
#define LN						'l'
#define SQRT					'q'
#define ANS						'N'
#define CONTRAST 				'R'
#define L_BRACKET				'('
#define R_BRACKET				')'
#define POWER					'^'
/********************Advanced Keypad*************************/



#define 	PASSWORD_SIZE			4
#define 	PASSWORD				"1234"
void KPD_VidInit(void);
u8 KPD_U8PressedKey(void);
void KPD_VidValidatePassword(void);
#endif
