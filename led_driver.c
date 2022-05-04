/*
 * led_driver.c
 *
 *  Created on: Apr 21, 2022
 *      Author: lab_3d
 */

#include "stm32l152xc.h"
//#include "stm32l1xx_hal.h"

void init_led_green(void){
	RCC->AHBENR |= (1 << 1);

	GPIOB->MODER |= (1 << 14);
	GPIOB->MODER &= ~(1 << 15);

	GPIOB->OTYPER &= ~(1 << 7);

	GPIOB->OSPEEDR &= ~(1 << 14);
	GPIOB->OSPEEDR &= ~(1 << 15);

	GPIOB->PUPDR &= ~(1 << 14);
	GPIOB->PUPDR &= ~(1 << 15);
}

void init_led_blue(void){
	RCC->AHBENR |= (1 << 1);

	GPIOB->MODER |= (1 << 12);
	GPIOB->MODER &= ~(1 << 13);

	GPIOB->OTYPER &= ~(1 << 6);

	GPIOB->OSPEEDR &= ~(1 << 12);
	GPIOB->OSPEEDR &= ~(1 << 13);

	GPIOB->PUPDR &= ~(1 << 12);
	GPIOB->PUPDR &= ~(1 << 13);
}

void init_button(void){
	RCC->AHBENR |= (1 << 0);

	GPIOA->MODER &= ~(1 << 0);
	GPIOA->MODER &= ~(1 << 1);

	GPIOA->PUPDR &= ~(1 << 0);
	GPIOA->PUPDR &= ~(1 << 1);
}

void led_green_write(int status){
	if(status==1){
		GPIOB->ODR |= (1 << 7);
	}
	else if(status==0){
		GPIOB->ODR &= ~(1 << 7);
	}
	else{

	}
}

void led_blue_write(int status){
	if(status==1){
		GPIOB->ODR |= (1 << 6);
	}
	else if(status==0){
		GPIOB->ODR &= ~(1 << 6);
	}
	else{

	}
}

int button_status(void){
	if(GPIOA->IDR & (1 << 0)==1){
		return 1;
	}
	else if(GPIOA->IDR | ~(1 << 0)==0){
		return 0;
	}
	else{

	}
}

void init_button_interrupt(void){
	init_button();

	RCC->APB2ENR |= (1 << 0);

	SYSCFG->EXTICR[1] &= ~(1 << 0);
	SYSCFG->EXTICR[1] &= ~(1 << 1);
	SYSCFG->EXTICR[1] &= ~(1 << 2);
	SYSCFG->EXTICR[1] &= ~(1 << 3);

	EXTI->IMR |= (1 << 0);

	EXTI->RTSR |= (1 << 0);

	NVIC_SetPriority(EXTI0_IRQn, 1);
	NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void){
	//EXTI->PR |= (1 << 0);
	EXTI->PR |= EXTI_PR_PIF0;

	led_green_write(1);
	led_blue_write(1);

	for(int i=0;i<2000;i++){
		for(int i=0;i<1500;i++){
			asm("NOP");
		}
	}
}


















