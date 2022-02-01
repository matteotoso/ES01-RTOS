#include "FreeRTOSConfig.h"             // ARM.FreeRTOS::RTOS:Config
#include "FreeRTOS.h"                   // ARM.FreeRTOS::RTOS:Core
#include "task.h"                       // ARM.FreeRTOS::RTOS:Core
#include "TaskLed.h"
#include "led.h"
#include "Puls.h"

int GDms=300;
int RDms=300;


void vTask_LED_rosso(void * pvParameters){
	while(1){
		LedRedToggle();
		vTaskDelay(RDms);
	}
}
void vTask_LED_verde(void * pvParameters){
	while(1){
		LedGreenToggle();
		vTaskDelay(GDms);
	}
}


void vTask_PA0(void * pvParameters){
	static char inizio=1;
	while(1){
		while(!SwCxPress());
		if(SwCxPress()){
				if(inizio){
					RDms=RDms-100;
					inizio=0;
				} 
			  else{
					RDms=RDms+100;
					inizio=1;
				}
		}
}
}



