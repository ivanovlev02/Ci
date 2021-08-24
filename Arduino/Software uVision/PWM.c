#include "stm32f407xx.h"
unsigned int i=0;
unsigned int j;
void delay(void)
{
volatile uint32_t i;
for (i=1; i != 100000; i++);
}

void TIM6_DAC_IRQHandler(){
	
	TIM6->SR &= ~TIM_SR_UIF;
	TIM4->CCR3= 2^i;
	i++;
}


int main(){
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	RCC->APB1ENR|=RCC_APB1ENR_TIM6EN;

	GPIOD->MODER |= (GPIO_MODER_MODER13_0);
	
	TIM4->PSC = 0x1; //Preddelitel
	TIM4->ARR = 0xFFFF;
	
  TIM4->CCER |= TIM_CCER_CC1E;
	TIM4->CCER |= TIM_CCER_CC2E;
	TIM4->CCER |= TIM_CCER_CC3E;
	
	TIM4->CCMR2 |= TIM_CCMR2_OC3M_2;
	TIM4->CCMR2 |= TIM_CCMR2_OC3M_1;
	//TIM4->CCMR2 &= ~TIM_CCMR2_OC3M_0;
	
	GPIOD->MODER |= (GPIO_MODER_MODER14_1);
	
	GPIOD->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14_1;
	GPIOD->OSPEEDR &= ~GPIO_OSPEEDER_OSPEEDR14_0;
	

	GPIOD->AFR[1] = (uint32_t)0x02220000;
	TIM4->CR1 |= TIM_CR1_CEN;
	
	TIM6->PSC = 240;
	TIM6->ARR = 100;
	TIM6->DIER |= TIM_DIER_UIE;
	
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
  TIM6->CR1 = TIM_CR1_CEN;

	while(1){
		
	}
}
