#include "stm32f407xx.h"
uint8_t flag = 0;
void EXTI0_IRQHandler(){
	
	if(flag==0){
		flag = 0;
		GPIOD->ODR|=GPIO_ODR_OD12;
	  GPIOD->ODR|=GPIO_ODR_OD13;
	  GPIOD->ODR|=GPIO_ODR_OD14;
	}
	flag = 0;
	if(flag==0){
		flag = 1;
		GPIOD->ODR&=~(GPIO_ODR_OD12);
		GPIOD->ODR&=~(GPIO_ODR_OD13);
		GPIOD->ODR&=~(GPIO_ODR_OD14);
	}
	EXTI->PR |= EXTI_PR_PR0;
	//GPIOD->ODR=GPIOD->ODR*2;
	//EXTI->RTSR |= EXTI_RTSR_TR0;
}
int main(){
	
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER|=(GPIO_MODER_MODER12_0|GPIO_MODER_MODER13_0|GPIO_MODER_MODER14_0|GPIO_MODER_MODER15_0);
	//GPIOD->ODR|=GPIO_ODR_OD12;
	//GPIOD->ODR|=GPIO_ODR_OD13;
	//GPIOD->ODR|=GPIO_ODR_OD14;
	
	/*GPIOD->ODR&=~(GPIO_ODR_OD12);//Tilda-inversija, vykluchenie svetodioda
	GPIOD->ODR&=~(GPIO_ODR_OD13);
	GPIOD->ODR&=~(GPIO_ODR_OD14);
	GPIOD->ODR&=~(GPIO_ODR_OD15);*/
	
	NVIC_EnableIRQ(EXTI0_IRQn);
	EXTI->RTSR |= EXTI_RTSR_TR0;
	EXTI->IMR |= EXTI_IMR_MR0;
	//GPIOD->ODR|=1<<12;
	while(1){}
	
}
