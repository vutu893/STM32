#include <myRCC.h>

void RCC_Init(volatile RCC_TypeDef *RCC)
{
  // Enable HSE and wait until it's ready
  RCC->CR |= RCC_CR_HSEON; // turn on HSE
  while(!(RCC->CR & RCC_CR_HSERDY)); //Wait until HSE is ready
  
  // Configure the PLL
  // Select HSE as PLL source and configure PLL multiplier to 9
  RCC->CFGR |= RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMUL9;
  
  // configure the prescalers for AHB, APB1, and APB2 buses
  RCC->CFGR |= RCC_CFGR_HPRE_DIV1;
  RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;
  RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;
  
  //enbale PLL and wait until it's ready
  RCC->CR |= RCC_CR_PLLON;
  while(!(RCC->CR & RCC_CR_PLLRDY));
  
  // Select PLL as the system clock
  RCC->CFGR |= RCC_CFGR_SW_PLL;
  while((RCC->CFGR & RCC_CFGR_SWS_PLL) != RCC_CFGR_SWS_PLL); //Wait for PLL to be system clock
  
  // Enable peripheral clocks as needed
  RCC->APB2ENR |= RCC_APB2ENR_IOPCEN; // Enable GPIOC clock
}