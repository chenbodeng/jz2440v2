#define GPFCON      (*(volatile unsigned long *)0x56000050)
#define GPFDAT      (*(volatile unsigned long *)0x56000054)

int main()
{
    GPFCON = 0x00000400;    // ����GPF5Ϊ�����, λ[11:10]=0b01
    GPFDAT = 0x00000000;    // GPF5���0��LED2����

    return 0;
}

