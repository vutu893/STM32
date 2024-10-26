/*----------------------------------------------
                      DOCUMENT RCC REGISTER IN STM32- DETAILS IN MANUAL RM0008
1. Reset 
   Three types of reset: system reset, power reset and backup domain reset
a, System reset:
  A system reset sets all registers to their reset values.
  A system reset is generated when one of the following events occurs:
                  A low level on the NRST pin(external reset)
                  Window watchdog end of count condition
                  Independent watchdog end of count condition
                  A software reset
b, Power reset
  Be generated when one of the following events occurs:
                  Power on/power down reset
                  When exiting standby mode
-----> Reset all registers to their reset values 
c, Backup domain reset

2. Clocks
    Three different clock sources can be used to drive the system clock (SYSCLK):
                    HSI oscillator clock        
                    HSE oscillator clock
                    PLL clock
    The devices have the following two secondary clock source: 40Khz, 32.768KHz.

3. RCC registers

a, RCC_CR - Clock control register: to on or off a source clock 
b, RCC_CFGR - Clock configuration register: mul, div clock 
c, RCC_CIR - Clock interrupt register 
d, RCC_APB2RSTR - APB2 peripheral reset register
e, RCC_APB1RSTR - APB1 peripheral reset register
f, RCC_AHBENR - AHB peripheral clock enable register
g, RCC_APB2ENR - APB2 peripheral clock enable register
h, RCC_APB1ENR - APB1 peripheral clock enable register
k, RCC_BDCR
i, RCC_CSR - Control/status register



----------------------------------------------------------> NOTE IMPORTANT <-----------------------------------------------------
 Each programing, first is config RCC - a first function for each programing.
*/