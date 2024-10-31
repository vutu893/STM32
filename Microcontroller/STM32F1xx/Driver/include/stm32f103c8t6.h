#ifndef _STM32F103C8T6_H_
#define _STM32F103C8T6_H_


/* GPIO */
#include <gpio.h>

__root __no_init volatile GPIO_TypeDef GPIOA @ (0x40010800U);
__root __no_init volatile GPIO_TypeDef GPIOB @ (0x40010C00U);
__root __no_init volatile GPIO_TypeDef GPIOC @ (0x40011000U);

/* RCC */
#include <myRCC.h>
__root __no_init volatile RCC_TypeDef RCC @ (0x40021000U);


#endif