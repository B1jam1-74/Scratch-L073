#include <stdint.h>
#include <stm32l073xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "timer.h"


int main(void)
{
	GPIO_Init();
	SYSTICK_Init();
	TIM2_init();

	while(1){
		//SYSTICK_Delay(1000);
		//GPIOA->ODR 	 ^= 1 << GPIO_ODR_OD5_Pos;
	}
}

