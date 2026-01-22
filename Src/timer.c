#include <stdint.h>
#include <stm32l073xx.h>
#include "timer.h"

uint32_t SystemCoreClock = 2000000;
uint32_t ticks = 0;

void SYSTICK_Init(void){
	SysTick_Config(SystemCoreClock / 1000);
}

void SYSTICK_Delay(uint32_t Delay)
{
	uint32_t tickstart = SYSTICK_Get();
	uint32_t wait = Delay;

	while((SYSTICK_Get() - tickstart) < wait);
}

uint32_t SYSTICK_Get(void){
	return ticks;
}


void TIM2_init(void) {
	// Reglé pour toutes les 1 sec avec f = 2MHz
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = 30;
	TIM2->EGR &= ~(1 >> TIM_EGR_UG_Pos);
	TIM2->ARR = 65535;
	TIM2->CNT = 0;
	TIM2->CR1 |= TIM_CR1_CEN;

	// Activation de l'interruption correspondante
	NVIC_EnableIRQ(TIM2_IRQn);

	// Active l'interruption si l'on arrive dans l'overflow du compteur
	TIM2->DIER |= TIM_DIER_UIE;
}

