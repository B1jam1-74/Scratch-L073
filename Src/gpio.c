#include <stdint.h>
#include <stm32l073xx.h>
#include "main.h"
#include "gpio.h"

void GPIO_Init(void){
	RCC->IOPENR   |= RCC_IOPENR_GPIOAEN | RCC_IOPENR_GPIOBEN | RCC_IOPENR_GPIOCEN;
	GPIOA->MODER  &= ~(GPIO_MODER_MODE5_Msk);
	GPIOA->MODER  |= OUTPUT_MODE << GPIO_MODER_MODE5_Pos;	// PA5 Output LED
}

