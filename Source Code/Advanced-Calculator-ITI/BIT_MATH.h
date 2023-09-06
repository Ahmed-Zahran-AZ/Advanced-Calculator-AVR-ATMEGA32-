#ifndef BIT_MATH_H    /* File Guard */
#define BIT_MATH_H

#define SET_BIT(REG,BITNO)      REG=REG|((1<<BITNO))
#define CLR_BIT(REG,BITNO)      REG=REG&(~(1<<BITNO))
#define GET_BIT(REG,BITNO)      ((REG>>BITNO)&1)
#define TOG_BIT(REG,BITNO)      REG=REG^(1<<BITNO)
#define ROT_RIGHT(REG,BITNO)    REG = (REG>>BITNO) | (VAR<<(8-BITNO))
#define ROT_LEFT(REG,BITNO)     REG = (REG<<BITNO) | (VAR>>(8-BITNO))

#endif