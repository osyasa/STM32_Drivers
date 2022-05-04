#include "stm32l152xc.h"
#include "stm32l1xx_hal.h"
#include "uart.h"

void __INIT_UART2_SETTINGS(void){

	Uart2InitStruct uart2InitStruct = {0};

	uart2InitStruct.USART2_CR1 &= RESET_BIT_15;
	uart2InitStruct.USART2_CR1 |= SET_BIT_13;
	uart2InitStruct.USART2_CR1 &= RESET_BIT_12;
	uart2InitStruct.USART2_CR1 &= RESET_BIT_10;
	uart2InitStruct.USART2_CR1 |= SET_BIT_3;
	uart2InitStruct.USART2_CR1 |= SET_BIT_2;

	uart2InitStruct.USART2_CR2 &= RESET_BIT_13;
	uart2InitStruct.USART2_CR2 &= RESET_BIT_12;
	uart2InitStruct.USART2_CR2 &= RESET_BIT_11;

	uart2InitStruct.USART2_BRR = 0x116;

	__APPLY_UART2_SETTINGS(&uart2InitStruct);
}

void __INIT_UART2_CLOCK(void){
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	Uart2ClockStruct uart2ClockStruct = {0};

	uart2ClockStruct.RCC_AHBENR |= SET_BIT_0;
	uart2ClockStruct.RCC_APB1ENR |= SET_BIT_17;

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	__APPLY_UART2_CLOCK(&uart2ClockStruct);
}

void __INIT_UART2_INTERRUPT(void){
	USART2->CR1 |= SET_BIT_5;

	NVIC_SetPriority(USART2_IRQn, 1);
	NVIC_EnableIRQ(USART2_IRQn);
}

void __APPLY_UART2_CLOCK(Uart2ClockStruct *uart2ClockStruct){
	RCC->AHBENR |= uart2ClockStruct->RCC_AHBENR;
	RCC->APB1ENR |= uart2ClockStruct->RCC_APB1ENR;
}

void __APPLY_UART2_SETTINGS(Uart2InitStruct *uart2InitStruct){
	USART2->CR1 = uart2InitStruct->USART2_CR1;
	USART2->CR2 = uart2InitStruct->USART2_CR2;
	USART2->BRR = uart2InitStruct->USART2_BRR;
}

void USART2_IRQHandler(void){
	/*
	if(USART2->SR & (1 << 5)){
		char data = USART2->DR;
		if(data == '1'){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
		}
		else if(data == '0'){
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
		}
		else{
			asm("NOP");
		}
	}
	*/
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);

	static char buffer[4];
	static int8_t i = 0;

	if(USART2->SR & (1 << 5)){
		buffer[i] = USART2->DR;
		switch(i){
		case 3:
			if(buffer[0] == 'O' && buffer[1] == 'M' && buffer[2] == 'E' && buffer[3] == 'R'){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
			}
			break;
		case 0:
			if(buffer[0] == 'R' && buffer[1] == 'O' && buffer[2] == 'M' && buffer[3] == 'E'){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
			}
			break;
		case 1:
			if(buffer[0] == 'E' && buffer[1] == 'R' && buffer[2] == 'O' && buffer[3] == 'M'){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
			}
			break;
		case 2:
			if(buffer[0] == 'M' && buffer[1] == 'E' && buffer[2] == 'R' && buffer[3] == 'O'){
				HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
			}
			break;
		}
		i = (i+1) % 4;
	}
}
