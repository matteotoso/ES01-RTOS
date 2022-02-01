#include "stm32l4xx.h"                  // Device header
#include "led.h"
#include "Puls.h"
#include "SysClock.h"




/*Funzione che raggruppa tutte le funzioni 
necessarie per le inizializzazioni*/

void LedInit(void){
  LedRedInit();
	LedGreenInit();
	
  
	
	
}

//-------------------------------------------




/*Configurazione del pin dove è collegato 
il led rosso e verde  come output digitale*/

void LedRedInit(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER2_0;
	GPIOB->MODER &= ~GPIO_MODER_MODER2_1;
}

void LedGreenInit(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
	GPIOE->MODER |= GPIO_MODER_MODER8_0;
	GPIOE->MODER &= ~GPIO_MODER_MODER8_1;
}

//-------------------------------------------

/*Funzioni per accendere o spegnere il led rosso*/

void LedRedOn(void){
	GPIOB->ODR |= GPIO_ODR_OD2;
}

void LedRedOff(void){
	GPIOB->ODR &= ~GPIO_ODR_OD2;
}

void LedRedToggle(void){
	GPIOB->ODR ^= GPIO_ODR_OD2;
}	

//-------------------------------------------

/*Funzioni per accendere o spegnere il led verde*/

void LedGreenOn(void){
	GPIOE->ODR |= GPIO_ODR_OD8;
}

void LedGreenOff(void){
  GPIOE->ODR &= ~ GPIO_ODR_OD8;
}

void LedGreenToggle(void){
	GPIOE->ODR ^= GPIO_ODR_OD8;
}

//-------------------------------------------

/*Funzioni per il lampeggio del led Rosso*/

void LedRedBlink (int n,int ms){
	for(int a=0;a<n;a++){
	LedRedToggle();
	delay(ms);
	LedRedToggle();
	delay(ms);
	}
}

/*Funzioni per il lampeggio del led Verde*/

void LedGreenBlink (int n,int ms){
	for(int a=0;a<n;a++){
	LedGreenToggle();
	delay(ms);
	LedGreenToggle();
	delay(ms);
	}
}

/*Funzioni per il lampeggio del led Verde e led Rosso*/

void LedBlink (int led,int n,int ms){
	if (led==0){
  LedRedBlink(n,ms);}
	else{
	LedGreenBlink(n,ms);
	}
	
}

int LedGreenCheck(void){
	if((GPIOE->ODR & GPIO_ODR_OD8)==0)
		return 0;
	else
		return 1;
}

int LedRedCheck(void){
	if((GPIOB->ODR & GPIO_ODR_OD2)==0)
		return 0;
	else
		return 1;
}	


