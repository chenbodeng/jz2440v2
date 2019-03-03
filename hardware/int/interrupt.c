#include "s3c24xx.h"

void EINT_Handle(void)
{
    unsigned long offset = INTOFFSET;
    
    // ͨ��INTOFFSET�Ĵ�������ȡ�ж�����
    switch (offset) {
        case 0:// S2������ 
            GPFDAT |= (0x7<<4);   // ����LEDϨ��
            GPFDAT &= ~(1<<4);    // LED1����
            break;
        
        case 2:// S3������
            GPFDAT |= (0x7<<4);   // ����LEDϨ��
            GPFDAT &= ~(1<<5);    // LED2����
            break;

        case 5:// K4������
            GPFDAT |= (0x7<<4);   // ����LEDϨ��
            GPFDAT &= ~(1<<6);    // LED4����                
            break;
    }

    // ���ж�
    if (offset == 5) 
        EINTPEND = (1<<11);     // EINT8_23����IRQ5
    SRCPND = 1<<offset;
    INTPND = 1<<offset;
}


