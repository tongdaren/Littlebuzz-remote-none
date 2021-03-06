
#include <uart.h>   

/***************************************************************
** 函数名称: Uart1Init
** 功能描述: UART1初始化函数
** 输　入:   
** 输　出:   
** 全局变量: 
** 作　者:   喵呜实验室
** 淘  宝：  Http://miaowlabs.taobao.com
** 日　期:   2014年08月01日
***************************************************************/
void Uart1Init(void)		//115200bps@20.000MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
//	T2L = 0xF7;			//设定定时初值
//	T2H = 0xFD;			//设定定时初值
	T2L = 0xD5;			//设定定时初值
	T2H = 0xFF;			//设定定时初值
	AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR |= 0x10;		//启动定时器2
//	TI = 1;
}
/***************************************************************
** 函数名称: UART1ReceiveByte
** 功能描述: UART1接收函数
** 输　入:   
** 输　出:   
** 全局变量: 
** 作　者:   喵呜实验室
** 淘  宝：  Http://miaowlabs.taobao.com
** 日　期:   2014年08月01日
***************************************************************/
unsigned char UART1ReceiveByte(void)
{
    unsigned char xdata ucRxd1; 

	while(RI==0);
	RI = 0;
	ucRxd1 = SBUF;
	return(ucRxd1);
}

/***************************************************************
** 函数名称: UART1SendByte
** 功能描述: UART1发送函数
** 输　入:   
** 输　出:   
** 全局变量: 
** 作　者:   喵呜实验室
** 淘  宝：  Http://miaowlabs.taobao.com
** 日　期:   2014年08月01日
***************************************************************/
void UART1SendByte(unsigned char TxD1)  
{   
    SBUF=TxD1;  
    while(TI == 0);//等待发送完成 
    //while(!TI);//等待发送完成 
    TI=0;   
}  

