#include "s3c24xx.h"

void Timer0_Handle(void)
{
    /*
     * ÿ���жϸı�LED1,2,4����LED�ı�״̬
     */
    if (INTOFFSET == 10) {
		GPFDAT = ~(GPFDAT & (0x07 << 4));
    }
    // ���ж�
    SRCPND = 1 << INTOFFSET;
    INTPND = INTPND;     
}
