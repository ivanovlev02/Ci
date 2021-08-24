#include "stm32f407xx.h"
unsigned int i;
unsigned int j;

int main(){
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= (GPIO_MODER_MODER13_0);
	
	
	TIM4->PSC = 0x00A7; //Preddelitel
	TIM4->ARR = 0x0FFF;
	TIM4->CCR3 = 0xFFFF;
	
	TIM4->CCMR2 |= TIM_CCMR2_OC3M_2;
	TIM4->CCMR2 |= TIM_CCMR2_OC3M_1;
	
	TIM4->CCER |= TIM_CCER_CC1E;
	TIM4->CCER |= TIM_CCER_CC2E;
	TIM4->CCER |= TIM_CCER_CC3E;
	
	GPIOD->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14_1;
	GPIOD->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR14_0;
	
	GPIOD->AFR[1] = (uint32_t)0x02220000;
	TIM4->CR1 |= TIM_CR1_CEN;
while(1){
		for(i=0; i<0xFFFF;i++){
			TIM4->CCR3 = i;
			for(j=0; j<0x100000;j++);
		}
	}
}