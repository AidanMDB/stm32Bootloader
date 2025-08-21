

#include <stdint.h>


// base adresses came from stm32f0xx reference manual on page 45-46
// those pages contain the memory mappings of the microcontroller
// UL at the end stand for unsigned long
#define PERIPH_BASE     0x40000000UL
#define AHB2_BASE       (PERIPH_BASE + 0x08000000UL)
#define AHB1_BASE       (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE        (AHB1_BASE + 0x1000UL)
#define GPIOC_BASE      (AHB2_BASE + 0x0800UL)

#define RCC_AHBENR      (*(volatile uint32_t*) (RCC_BASE + 0x14))
#define GPIOC_MODER     (*(volatile uint32_t*) (GPIOC_BASE + 0x00))
#define GPIOC_BSRR       (*(volatile uint32_t*) (GPIOC_BASE + 0x28))


static volatile uint32_t count = 0;

/**
 * Initialize GPIO Port C
 * specifically pin C6 to output mode
 */
void init_c() {
    RCC_AHBENR |= (1 << 19);
    GPIOC_MODER &= ~0x00003000;     // sets all other pins to 0 and pin 6 to 11
    GPIOC_MODER |=  0x00001000;     // sets pin 6 to 01 for output mode
}



/**
 * Toggle pin based on value given
 * @param val = 1 set pin
 *            = 0 reset pin
 */
void toggle(uint8_t val) {
    if (val) {
        GPIOC_BSRR |= (1 << 6);     // lower 16 are set
    }
    else {
        GPIOC_BSRR |= (1 << (6 + 16));  // upper 16 are reset
    }
}




void main() {
    while(1) {
        count != 1;
        toggle(count);
        for (uint32_t i = 0; i < 100000; i++) {}
    }
}