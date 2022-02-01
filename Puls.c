#include "stm32l4xx.h"                  // Device header
#include "Puls.h"
#include "led.h"


void PulsInit(void){
	SwCxInit();
	SwSxInit();
	SwRxInit();
	SwUpInit();
	SwDwInit();
}
/*Funzione per configurazione del pulsante centrale del Joystick*/

void SwCxInit(void){

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE0_Msk;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD0_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD0_0;
	
}

/*Funzione che premendo il tasto centrale avvierà la ledblink.*/

 int SwCxPress(void){
	return (GPIOA->IDR & GPIO_IDR_ID0_Msk);
 }

/*Funzione per configurazione del pulsante sinistro del Joystick*/
 
void SwSxInit(void){

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE1_Msk;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD1_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD1_0;
	

}

/*Funzione che premendo il tasto centrale avvierà la ledredon*/

void SwSxPress(void){
	if ((GPIOA->IDR & GPIO_IDR_ID1_Msk)){
		LedRedOn();
	}
}

void SwUpInit(void){

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE3_Msk;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD3_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD3_0;
	

}
void SwUpPress(void){
	if ((GPIOA->IDR & GPIO_IDR_ID3_Msk)){
		LedRedOff();
	}
}
void SwDwInit(void){

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE5_Msk;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD5_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD5_0;

}
 void SwDwPress(void){
	if ((GPIOA->IDR & GPIO_IDR_ID5_Msk)){
		LedGreenOn();
	}
}

void SwRxInit(void){

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	GPIOA->MODER &= ~GPIO_MODER_MODE2_Msk;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPD2_1;
	GPIOA->PUPDR &= ~GPIO_PUPDR_PUPD2_0;
	

}
void SwRxPress(void){
	if ((GPIOA->IDR & GPIO_IDR_ID2_Msk)){
		LedGreenOff();
	}
}
