#include "FreeRTOSConfig.h"             // ARM.FreeRTOS::RTOS:Config
#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "TaskLed.h"
#include "led.h"
#include "Puls.h"
#include "SysClock.h"




int main(void){
	
	PulsInit();
	LedInit();
	pllInit(0, 10, 0);
	
	
	
	xTaskCreate(vTask_LED_rosso, /* Pointer to the function that implements the task.              */
		"Task 1 (Toggle LED rosso)",    /* Text name for the task.  This is to facilitate debugging only. */
		50,   /* Stack depth in words.                */
		NULL,  /* We are not using the task parameter. */
		1,     /* This task will run at priority 1.    */
		NULL); /* We are not using the task handle.    */
	
	xTaskCreate(vTask_LED_verde, /* Pointer to the function that implements the task.              */
		"Task 1 (Toggle LED verde)",    /* Text name for the task.  This is to facilitate debugging only. */
		50,   /* Stack depth in words.                */
		NULL,  /* We are not using the task parameter. */
		1,     /* This task will run at priority 1.    */
		NULL); /* We are not using the task handle.    */
	
	
	xTaskCreate(vTask_PA0, /* Pointer to the function that implements the task.              */
		"Task 1 (Toggle LED verde)",    /* Text name for the task.  This is to facilitate debugging only. */
		50,   /* Stack depth in words.                */
		NULL,  /* We are not using the task parameter. */
		1,     /* This task will run at priority 1.    */
    NULL); /* We are not using the task handle.    */
	
		vTaskStartScheduler();
	
}