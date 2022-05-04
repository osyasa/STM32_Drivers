#ifndef __UART_H
#define __UART_H

#define SET_BIT_0 (1 << 0)
#define SET_BIT_1 (1 << 1)
#define SET_BIT_2 (1 << 2)
#define SET_BIT_3 (1 << 3)
#define SET_BIT_4 (1 << 4)
#define SET_BIT_5 (1 << 5)
#define SET_BIT_6 (1 << 6)
#define SET_BIT_7 (1 << 7)
#define SET_BIT_8 (1 << 8)
#define SET_BIT_9 (1 << 9)
#define SET_BIT_10 (1 << 10)
#define SET_BIT_11 (1 << 11)
#define SET_BIT_12 (1 << 12)
#define SET_BIT_13 (1 << 13)
#define SET_BIT_14 (1 << 14)
#define SET_BIT_15 (1 << 15)
#define SET_BIT_16 (1 << 16)
#define SET_BIT_17 (1 << 17)

#define RESET_BIT_0 ~(1 << 0)
#define RESET_BIT_1 ~(1 << 1)
#define RESET_BIT_2 ~(1 << 2)
#define RESET_BIT_3 ~(1 << 3)
#define RESET_BIT_4 ~(1 << 4)
#define RESET_BIT_5 ~(1 << 5)
#define RESET_BIT_6 ~(1 << 6)
#define RESET_BIT_7 ~(1 << 7)
#define RESET_BIT_8 ~(1 << 8)
#define RESET_BIT_9 ~(1 << 9)
#define RESET_BIT_10 ~(1 << 10)
#define RESET_BIT_11 ~(1 << 11)
#define RESET_BIT_12 ~(1 << 12)
#define RESET_BIT_13 ~(1 << 13)
#define RESET_BIT_14 ~(1 << 14)
#define RESET_BIT_15 ~(1 << 15)
#define RESET_BIT_16 ~(1 << 16)
#define RESET_BIT_17 ~(1 << 17)

typedef struct{
	uint16_t USART2_BRR;
	uint16_t USART2_CR1;
	uint16_t USART2_CR2;
}Uart2InitStruct;

typedef struct{
	uint32_t RCC_AHBENR;
	uint32_t RCC_APB1ENR;
}Uart2ClockStruct;

typedef struct{

}Uart2InterruptStruct;


void __INIT_UART2_SETTINGS(void);

void __INIT_UART2_CLOCK(void);

void __APPLY_UART2_CLOCK(Uart2ClockStruct *uart2ClockStruct);

void __APPLY_UART2_SETTINGS(Uart2InitStruct *uart2InitStruct);

void __INIT_UART2_INTERRUPT(void);







#endif
