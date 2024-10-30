#include "stm32f10x.h"

void delay_s(uint32_t ms){
    // Assuming 72MHz system clock
    ms *= 12000;  // Rough approximation, may need adjustment
    while(ms--) {
        __NOP();
    }
}

int main(void){
	SystemInit();
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->CRH &= ~(0xF << (13-8)*4);
	GPIOC->CRH |= (0x3 << (13-8)*4);
	
	while(1){
		GPIOC->ODR ^= (0x1 << 13);
		delay_s(1000);
	}
}