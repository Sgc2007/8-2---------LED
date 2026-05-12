#include <REGX52.H>
#include <stdio.h>

void UART_Init(void)
{
    SCON = 0x40;
    PCON |= 0x80;
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TL1 = 0xF3;
    TH1 = 0xF3;
    ET1 = 0;
    TR1 = 1;
    TI = 1;
}

char putchar(char c)
{
    SBUF = c;
    while(!TI);
    TI = 0;
    return c;
}

void Delay(unsigned int xms)
{
    unsigned char i, j;
    while(xms--)
    {
        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
    }
}

void main()
{
    unsigned char Sec = 0;
    UART_Init();
    // 加一个特殊标识，证明是新程序
    printf("UART_TEST_START\n");
    while(1)
    {
        printf("%d\n", Sec);
        Sec++;
        Delay(500);
    }
}
