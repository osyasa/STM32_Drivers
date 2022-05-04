/*
 * led_driver.h
 *
 *  Created on: Apr 21, 2022
 *      Author: lab_3d
 */

#ifndef OMERLIB_LED_DRIVER_H_
#define OMERLIB_LED_DRIVER_H_

void init_led_green(void);
void init_led_blue(void);
void init_button(void);
void led_green_write(int status);
void led_blue_write(int status);
int button_status(void);
void init_button_interrupt(void);
void EXTI0_IRQHandler(void);

#endif /* OMERLIB_LED_DRIVER_H_ */
