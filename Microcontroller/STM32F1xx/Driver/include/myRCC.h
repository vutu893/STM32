#ifndef _MYRCC_H_
#define _MYRCC_H_

/* This is library of myself, reference manual rm0008 and chatgpt */
#include <stdint.h>

#define RCC_BASE (0x40021000U) //base address for RCC

// Define the RCC_TypeDef structure with offset-based registers
typedef struct
{
  volatile uint32_t CR;         // Clock control register
  volatile uint32_t CFGR;       // Clock configuration register
  volatile uint32_t CIR;        // Clock interrupt register
  volatile uint32_t APB2RSTR;   // APB2 peripheral reset register
  volatile uint32_t APB1RSTR;   // APB1 peripheral reset register
  volatile uint32_t AHBENR;     // AHB peripheral clock enable register
  volatile uint32_t APB2ENR;    // APB2 peripheral clock enable register
  volatile uint32_t APB1ENR;    // APB1 peripheral clock enable register
  volatile uint32_t BDCR;       // Backup domain control register
  volatile uint32_t CSR;        // Control/status register
} RCC_TypeDef;



/*--------------- Define bit masks for RCC_CR register --------------*/
#define RCC_CR_HSION (1U << 0)          //HSI clock enable
#define RCC_CR_HSIRDY (1U << 1)         // HSI clock ready flag
#define RCC_CR_HSEON (1U << 16)         // HSE clock enable
#define RCC_CR_HSERDY (1U << 17)        // HSE clock ready flag
#define RCC_CR_PLLON (1U << 24)         // PLL enable
#define RCC_CR_PLLRDY (1U << 25)        // PLL ready flag
    

/*-------- Define bit masks for RCC_CFGR registe -----------*/
// set system clock
#define RCC_CFGR_SW_HSI (0x0U << 0) //set HSI as system clock
#define RCC_CFGR_SW_HSE (0x1U << 0) // set HSE as system clock
#define RCC_CFGR_SW_PLL (0x2U << 0) // set PLL as system clock

// system clock switch status
#define RCC_CFGR_SWS_HSI (0x0U << 2) // HSI used as system clock
#define RCC_CFGR_SWS_HSE (0x1U << 2) // HSE used as system clock
#define RCC_CFGR_SWS_PLL (0x2U << 2) // PLL used as system clock

//AHB prescaler
#define RCC_CFGR_HPRE_DIV1   (0x0U << 4) // AHB prescaler (div1)
#define RCC_CFGR_HPRE_DIV2   (0x8U << 4) // AHB prescaler (div2)
#define RCC_CFGR_HPRE_DIV4   (0x9U << 4) // AHB prescaler (div4)
#define RCC_CFGR_HPRE_DIV8   (0xAU << 4) // AHB prescaler (div8)
#define RCC_CFGR_HPRE_DIV16  (0xBU << 4) // AHB prescaler (div16)
#define RCC_CFGR_HPRE_DIV64  (0xCU << 4) // AHB prescaler (div64)
#define RCC_CFGR_HPRE_DIV128 (0xDU << 4) // AHB prescaler (div128)
#define RCC_CFGR_HPRE_DIV256 (0xEU << 4) // AHB prescaler (div256)
#define RCC_CFGR_HPRE_DIV512 (0xFU << 4) // AHB prescaler (div512)

// APB1 prescaler
#define RCC_CFGR_PPRE1_DIV1  (0x0U << 8)   // APB1 prescaler (div1)
#define RCC_CFGR_PPRE1_DIV2  (0x1U << 8)   // APB1 prescaler (div2)
#define RCC_CFGR_PPRE1_DIV4  (0x2U << 8)   // APB1 prescaler (div4)
#define RCC_CFGR_PPRE1_DIV8  (0x6U << 8)   // APB1 prescaler (div8)
#define RCC_CFGR_PPRE1_DIV16 (0x7U << 8)   // APB1 prescaler (div16)

// APB2 prescaler
#define RCC_CFGR_PPRE2_DIV1  (0x0U << 11)   // APB2 prescaler (div1)
#define RCC_CFGR_PPRE2_DIV2  (0x1U << 11)   // APB2 prescaler (div2)
#define RCC_CFGR_PPRE2_DIV4  (0x2U << 11)   // APB2 prescaler (div4)
#define RCC_CFGR_PPRE2_DIV8  (0x6U << 11)   // APB2 prescaler (div8)
#define RCC_CFGR_PPRE2_DIV16 (0x7U << 11)   // APB2 prescaler (div16)

//ADC prescaler
#define RCC_CFGR_ADCPRE_DIV2 (0x0U << 14)   // ADC prescaler (div2)
#define RCC_CFGR_ADCPRE_DIV4 (0x1U << 14)   // ADC prescaler (div2)
#define RCC_CFGR_ADCPRE_DIV6 (0x2U << 14)   // ADC prescaler (div2)
#define RCC_CFGR_ADCPRE_DIV8 (0x3U << 14)   // ADC prescaler (div2)

// PLL entry clock source
#define RCC_CFGR_PLLSRC_HSI (0x0U << 16) // HSI oscillator clock/2 selected as PLL input clock
#define RCC_CFGR_PLLSRC_HSE (0x1U << 16) // HSE oscillator clock selected as PLL input clock

// HSE divider for PLL entry
#define RCC_CFGR_PLLXTPRE_DIV1 (0x0U << 17) //HSE clock not divided
#define RCC_CFGR_PLLXTPRE_DIV2 (0x1U << 17) //HSE clock divided by 2

// PLL multiplication factor
#define RCC_CFGR_PLLMUL2   (0x0U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL3   (0x1U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL4   (0x2U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL5   (0x3U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL6   (0x4U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL7   (0x5U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL8   (0x6U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL9   (0x7U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL10  (0x8U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL11  (0x9U << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL12  (0xAU << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL13  (0xBU << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL14  (0xCU << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL15  (0xDU << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL16  (0xEU << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)
#define RCC_CFGR_PLLMUL16_1 (0xFU << 18)          //PLL multiplier (2x for 8 MHz to 16 MHz)

// USE prescaler
#define RCC_CFGR_USBPRE_DIV1 (0x1U << 22)       //PLL clock is not divided
#define RCC_CFGR_USBPRE_DEFAULT (0x0U << 22)    //PLL clock is divided by 1.5

// Microcontroller clock output
#define RCC_CFGR_MCO_NOCLK      (0x0U << 24)    // no clock
#define RCC_CFGR_MCO_SYSCLK     (0x1U << 24)    // system clock selected
#define RCC_CFGR_MCO_HSI        (0x3U << 24)    // HSI clock selected
#define RCC_CFGR_MCO_HSE        (0x6U << 24)    // HSE clock selected
#define RCC_CFGR_MCO_PLL        (0x7U << 24)    // PLL clock divided by 2 selected

/* -------------- Define bit masks for RCC_CIR registers ----------------------- */
/*--------------- Define bit masks for RCC_APB2RSTR registers ------------------ */
/*--------------- Define bit masks for RCC_APB1RSTR registers ------------------ */
/*--------------- Define bit masks for RCC_AHBENR registers -------------------- */

// SDIO clock enable
#define RCC_AHBENR_SDIOEN       (0x1U << 10)    // SDIO clock enable
#define RCC_AHBENR_FSMCEN       (0x1U << 8)     // FSMC clock enable
#define RCC_AHBENR_CRCEN        (0x1U << 6)     // CRC clock enable
#define RCC_AHBENR_FLITFEN      (0x1U << 4)     // FLITFEN clock enable
#define RCC_AHBENR_SRAMEN       (0x1U << 2)     // SRAMEN clock enable
#define RCC_AHBENR_DMA2EN       (0x1U << 1)     // DMA2EN clock enable
#define RCC_AHBENR_DMA1EN       (0x1U << 0)     // DMA1EN clock enable

/*--------------- Define bit mask for RCC_APB2ENR registers -------------------- */
#define RCC_APB2ENR_TIM11EN     (0x1U << 21)    // TIM11 clock enabled
#define RCC_APB2ENR_TIM10EN     (0x1U << 20)    // TIM10EN clock enabled
#define RCC_APB2ENR_TIM9EN      (0x1U << 19)    // TIM9EN clock enabled
#define RCC_APB2ENR_ADC3EN      (0x1U << 15)    // ADC3EN clock enabled
#define RCC_APB2ENR_USART1EN    (0x1U << 14)    // USART1EN clock enabled
#define RCC_APB2ENR_TIM8EN      (0x1U << 13)    // TIM8EN clock enabled
#define RCC_APB2ENR_SPI1EN      (0x1U << 12)    // SPI1EN clock enabled
#define RCC_APB2ENR_TIM1EN      (0x1U << 11)    // TIM1EN clock enabled
#define RCC_APB2ENR_ADC2EN      (0x1U << 10)    // ADC2EN clock enabled
#define RCC_APB2ENR_ADC1EN      (0x1U << 9)     // ADC1EN clock enabled
#define RCC_APB2ENR_IOPGEN      (0x1U << 8)     // IOPGEN clock enabled
#define RCC_APB2ENR_IOPFEN      (0x1U << 7)     // IOPGEN clock enabled
#define RCC_APB2ENR_IOPEEN      (0x1U << 6)     // IOPFEN clock enabled
#define RCC_APB2ENR_IOPDEN      (0x1U << 5)     // IOPDEN clock enabled
#define RCC_APB2ENR_IOPCEN      (0x1U << 4)     // IOPCEN clock enabled
#define RCC_APB2ENR_IOPBEN      (0x1U << 3)     // IOPBEN clock enabled
#define RCC_APB2ENR_IOPAEN      (0x1U << 2)     // IOPAEN clock enabled
#define RCC_APB2ENR_AFIOEN      (0x1U << 0)     // AFIOEN clock enabled

/*--------------- Define bit mask for RCC_APB1ENR registers -------------------- */
#define RCC_APB1ENR_DACEN       (0x1U << 29)    // DACEN clock enabled
#define RCC_APB1ENR_PWREN       (0x1U << 28)    // PWREN clock enabled
#define RCC_APB1ENR_BKPEN       (0x1U << 27)    // BKPEN clock enabled
#define RCC_APB1ENR_CANEN       (0x1U << 25)    // CANEN clock enabled
#define RCC_APB1ENR_USBEN       (0x1U << 23)    // USBEN clock enabled
#define RCC_APB1ENR_I2C2EN      (0x1U << 22)    // I2C2EN clock enabled
#define RCC_APB1ENR_I2C1EN      (0x1U << 21)    // I2C1EN clock enabled
#define RCC_APB1ENR_UART5EN     (0x1U << 20)    // UART5EN clock enabled
#define RCC_APB1ENR_UART4EN     (0x1U << 19)    // UART4EN clock enabled
#define RCC_APB1ENR_USART3EN    (0x1U << 18)    // USART3EN clock enabled
#define RCC_APB1ENR_USART2EN    (0x1U << 17)    // USART2EN clock enabled
#define RCC_APB1ENR_SPI3EN      (0x1U << 15)    // SPI3EN clock enabled
#define RCC_APB1ENR_SPI2EN      (0x1U << 14)    // SPI2EN clock enabled
#define RCC_APB1ENR_WWDGEN      (0x1U << 11)    // WWDGEN clock enabled
#define RCC_APB1ENR_TIM14EN     (0x1U << 8)    // TIM14EN clock enabled
#define RCC_APB1ENR_TIM13EN     (0x1U << 7)    // TIM13EN clock enabled
#define RCC_APB1ENR_TIM12EN     (0x1U << 6)    // TIM12EN clock enabled
#define RCC_APB1ENR_TIM7EN      (0x1U << 5)    // TIM7EN clock enabled
#define RCC_APB1ENR_TIM6EN      (0x1U << 4)    // TIM6EN clock enabled
#define RCC_APB1ENR_TIM5EN      (0x1U << 3)    // TIM5EN clock enabled
#define RCC_APB1ENR_TIM4EN      (0x1U << 2)    // TIM4EN clock enabled
#define RCC_APB1ENR_TIM3EN      (0x1U << 1)    // TIM3EN clock enabled
#define RCC_APB1ENR_TIM2EN      (0x1U << 0)    // TIM2EN clock enabled

/*--------------- Define bit masks for RCC_BDCR register ---------------*/
/*--------------- Define bit masks for RCC_CSR registers ---------------*/

/*--------------- API for RCC ------------------------------------------*/
void RCC_Init(volatile RCC_TypeDef *RCC);

#endif