#include "s3c24xx.h"

void Timer0_Handle(void)
{
    /*
     * 每次中断改变LED1,2,4三个LED改变状态
     */
    if (INTOFFSET == 10) {
		GPFDAT = ~(GPFDAT & (0x07 << 4));
    }
    // 清中断
    SRCPND = 1 << INTOFFSET;
    INTPND = INTPND;     
}
