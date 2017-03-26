//Toka Mojaje
// Parking lot design
#include <stdint.h>
#define STM32F051
#include "stm32f0xx.h"  // you can remove this if you're not using it
//============ Global Variables ===========================
#define SW0 (GPIOA->IDR & GPIO_IDR_0)	//count up
#define SW1 (GPIOA->IDR & GPIO_IDR_1)	//count down
#define SW2 (GPIOA->IDR & GPIO_IDR_2)
//============   functions ================================
void debounce(void);
void reset(void);
//============   variables ================================
volatile uint32_t previous_state0 , current_state0, previous_state1 , current_state1;
volatile int counter;

int main(void) {
	
	previous_state0 = SW0;
	previous_state1 = SW1;
    while(1) {
        current_state0 = SW0;
        if ((current_state0 == 1) && (previous_state0 != 1 )){
			counter = counter + 1;
			GPIOB-> ODR = patterns0[counter];
			if(counter == 9){
				reset();
			}
        }
        previous_state0 = current_state0;
        current_state1 = SW1;
        if ((current_state1 == 1) && (previous_state1 != 1 )){
			counter = counter - 1;
			GPIOB-> ODR = patterns1[counter];
			if(counter == 0){
				reset();
			}
        }
        previous_state1 = current_state1;
		debounce();
    }
    return 0;  // keep compiler happy with a return code.
}

void debounce(void){
    uint32_t v;
    for(v = 0;v <12208;v++){
    }
}
void reset(void){
	if(counter == 9){
		for(;;){
			//Dipslay some shit on the LCD
			//Garage is full
			if(SW1==0){
				counter = counter -1;
				break;
			}
		}
	}
	if(counter==0){
		for(;;){
			//Dipslay some shit on the LCD
			//Garage is empty
			if(SW0==0){
				counter = counter +1;
				break;
			}
		}
	}
}