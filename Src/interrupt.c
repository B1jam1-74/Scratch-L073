
#include <stdint.h>
#include <stm32l073xx.h>
#include "interrupt.h"

extern uint32_t ticks;

// Interrupt Handler for SysTick Interrupt
void SysTick_Handler(void){
	ticks++;
}

void TIM2_IRQHandler(void) {
	// Remet le flag à 0
	TIM2->SR &= ~(TIM_SR_UIF);

	// Fait clignoter la LED
	GPIOA->ODR 	 ^= 1 << GPIO_ODR_OD5_Pos;
}
