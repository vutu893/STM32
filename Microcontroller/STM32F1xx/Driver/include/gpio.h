#ifndef _GPIO_H_
#define _GPIO_H_

#include <define.h>

// Map register GPIO in stm32f10xx:
/*
  ----------------------------------------------------------------------------
- PURPOSE: Build astract layer map register GPIO for stm32f103
- Description: modes in GPIO
              +, Port configuration register
                                      0: Input mode(reset state)
                                      1: Output mode, max speed 10Mhz
                                      2: Output mode, max speed 2Mhz
                                      3: Output mode, max speed 50MHz
              +, Input mode:
                                      0: Analog mode
                                      1: Floating input (reset state)
                                      2: Input with  pull-up / pull_dowm
              +, Output mode:
                                      0: General purpose output push-pull
                                      1: General purpose ouput open-drain
                                      2: Alternate function output push-pull
                                      3: Alternate function output open-drain
*/
typedef struct
{
  BUNION(CRL, unsigned long,  /* Thanh ghi GPIO_CRL */
         MODE_0,           2,   
         CNF_0,            2,
         MODE_1,           2,
         CNF_1,            2,
         MODE_2,           2,
         CNF_2,            2,
         MODE_3,           2,
         CNF_3,            2,
         MODE_4,           2,
         CNF_4,            2,
         MODE_5,           2,
         CNF_5,            2,
         MODE_6,           2,
         CNF_6,            2,
         MODE_7,           2,
         CNF_7,            2);
  BUNION(CRH, unsigned long,  /* Thanh ghi GPIO_CRH */
         MODE_9,           2,   
         CNF_9,            2,
         MODE_10,           2,
         CNF_10,            2,
         MODE_11,           2,
         CNF_11,            2,
         MODE_12,           2,
         CNF_12,            2,
         MODE_13,           2,
         CNF_13,            2,
         MODE_14,           2,
         CNF_14,            2,
         MODE_15,           2,
         CNF_15,            2,
         MODE_16,           2,
         CNF_16,            2);
  BUNION(IDR, unsigned long,   /* Thanh ghi GPIO_IDR */
          xBITS_B(b, 0, 15, 1),
          _reserved , 16);
  BUNION(ODR, unsigned long,   /* Thanh ghi GPIO_ODR */
          xBITS_B(b, 0, 15, 1),
          _reserved , 16);
  union     /* Thanh ghi GPIO_BSRR: have two part BR and BSR */
  {
    unsigned long REG;
    struct
    {
      xBUNION(BSR, unsigned short, b, 0, 15, 1);
      xBUNION(BR, unsigned short, b, 0, 15, 1);
    };
  } BSRR;
  BUNION(BRR, unsigned long,  /* Thanh ghi BRR */
         xBITS_B(b, 0, 15, 1),
         _reserved, 16);
  BUNION(LCKR, unsigned long,
         xBITS_B(b, 0, 15, 1),
         LOCK, 1, 
         _reserved, 15);
} GPIO_TypeDef;


/* ------------------------------------------------------------------------
- PURPOSE: map register for GPIO in mode access bitband( via SRAM)
- Description: 
              
*/
typedef struct
{
  RSTRUCT(CRL, unsigned long,                   //              0x4444'4444     Port configuration register
      MODE_0                            [2],    //0-1           0                       0: Input mode (reset state)
                                                //                                      1: Output mode, max speed 10 MHz.
                                                //                                      2: Output mode, max speed 2 MHz.
                                                //                                      3: Output mode, max speed 50 MHz
       CNF_0                            [2],    //2-3           1               In input mode:
                                                //                                      0: Analog mode
                                                //                                      1: Floating input (reset state)
                                                //                                      2: Input with pull-up / pull-down
                                                //                              In output mode:
                                                //                                      0: General purpose output push-pull
                                                //                                      1: General purpose output Open-drain
                                                //                                      2: Alternate function output Push-pull
                                                //                                      3: Alternate function output Open-drain
      MODE_1                            [2],    //
       CNF_1                            [2],    //
      MODE_2                            [2],    //
       CNF_2                            [2],    //
      MODE_3                            [2],    //
       CNF_3                            [2],    //
      MODE_4                            [2],    //
       CNF_4                            [2],    //
      MODE_5                            [2],    //
       CNF_5                            [2],    //
      MODE_6                            [2],    //
       CNF_6                            [2],    //
      MODE_7                            [2],    //
       CNF_7                            [2]);   //
  RSTRUCT(CRH, unsigned long,                   //              0x4444'4444     
      MODE_8                            [2],    //
       CNF_8                            [2],    //
      MODE_9                            [2],    //
       CNF_9                            [2],    //
      MODE_10                           [2],    //
       CNF_10                           [2],    //
      MODE_11                           [2],    //
       CNF_11                           [2],    //
      MODE_12                           [2],    //
       CNF_12                           [2],    //
      MODE_13                           [2],    //
       CNF_13                           [2],    //
      MODE_14                           [2],    //
       CNF_14                           [2],    //
      MODE_15                           [2],    //
       CNF_15                           [2]);   //  
  RSTRUCT(IDR, unsigned long,                   //              0x0000'----     Port input data register
      xREGS_R(b, 0, 15, ),                      //
      _reserved                         [16]);  //
  RSTRUCT(ODR, unsigned long,                   //              0x0000'0000     Port output data register
      xREGS_R(b, 0, 15, ),                      //
      _reserved                         [16]);  //
  struct
  {
      xRSTRUCT(BSR, unsigned long, b, 0, 15, ); //              0x0000          Write 1 to set pin output, set has priority 
      xRSTRUCT(BR, unsigned long, b, 0, 15, );  //              0x0000          Write 1 to clear pin output
  } BSRR;                                       //                              Port bit set/reset register
  RSTRUCT(BRR, unsigned long,                   //              0x0000'0000     Port bit reset register, Write 1 to clear pin output
      xREGS_R(b, 0, 15, ),                      //
      _reserved                         [16]);  //
  RSTRUCT(LCKR, unsigned long,                  //              0x0000'0000     Port configuration lock register
      xREGS_R(b, 0, 15, ),                      //
      LOCK                                 ,    //16            0               LOCK key writing sequence: write 1 -> 0 -> 1 -> read 0 -> 1
      _reserved                         [15]);  //
} GPIO_BITBAND_TypeDef;


/* Define mode for GPIO */
/* Explain code: shift 2 bit because mode in register CRL and CRH have 2 bit*/
typedef enum
{
  GPIO_MODE_INPUT_ANALOG                = (0 << 2) | 0,
  GPIO_MODE_INPUT_FLOAT                 = (1 << 2) | 0,
  GPIO_MODE_INPUT_PULL                  = (2 << 2) | 0,
  
  GPIO_MODE_OUTPUT_PUSHPULL_10MHz       = (0 << 2) | 1,
  GPIO_MODE_OUTPUT_OPEN_10MHz           = (1 << 2) | 1,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_10MHz    = (2 << 2) | 1,
  GPIO_MODE_AF_OUTPUT_OPEN_10MHz        = (3 << 2) | 1,
  
  GPIO_MODE_OUTPUT_PUSHPULL_2MHz        = (0 << 2) | 2,
  GPIO_MODE_OUTPUT_OPEN_2MHz            = (1 << 2) | 2,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_2MHz     = (2 << 2) | 2,
  GPIO_MODE_AF_OUTPUT_OPEN_2MHz         = (3 << 2) | 2,
  
  GPIO_MODE_OUTPUT_PUSHPULL_50MHz       = (0 << 2) | 3,
  GPIO_MODE_OUTPUT_OPEN_50MHz           = (1 << 2) | 3,
  GPIO_MODE_AF_OUTPUT_PUSHPULL_50MHz    = (2 << 2) | 3,
  GPIO_MODE_AF_OUTPUT_OPEN_50MHz        = (3 << 2) | 3,  
} GPIO_MODE;
void GPIO_Mode(volatile GPIO_TypeDef* GPIO, unsigned int PIN, GPIO_MODE Mode);
/* DESCRIPTION FUNCTION OF EACH REGISTER IN REGISTER OF GPIO (STM32F10XX)*/
/* 
    GPIOx_CRL/ GPIOx_CRH use to set up mode for GPIO: input/output mode as CNFx[1: 0], MODEx[1:0} use to chose speed for output mode
    GPIOx_IDR(port input data register): IDRx can be only read.
    GPIOx_ODR(port output data register): ODRx can be read and written.
    GPIOx_BSRR(port bit set /reset register): 
    GPIOx_ BRR(port bit reset register)
    GPIOx_LCKR( port configuration lock register).
*/
#endif