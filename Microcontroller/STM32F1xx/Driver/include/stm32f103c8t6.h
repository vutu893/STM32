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

/* EXTI */
#include <exti.h>
__root __no_init volatile EXTI_TypeDef EXTI @ (0x40010400U);

/*CORTEX_M3 */
#include <cortex_m3.h>
__root __no_init volatile SYSTICK_TypeDef SYSTICK @ (0xE000E010U);
__root __no_init volatile NVIC_TypeDef NVIC @ (0xE000E100U);

/* BASIC TIMER */
#include <basic_timer.h>
__root __no_init volatile BASICTIMER_TypeDef TIM6 @(0x40001000U);
//BASICTIMER_TypeDef volatile *TIM6 = (BASICTIMER_TypeDef volatile *)0x40001000;  // Base address of TIM6

__root __no_init volatile BASICTIMER_TypeDef TIM7 @(0x40001400U);
#endif