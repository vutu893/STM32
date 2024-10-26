#ifndef _MYGPIO_H_
#define _MYGPIO_H_


#include <stdint.h>

/*---------------- Define the GPIO_TypeDef structure with offset-based registers -----------------*/
typedef struct
{
  volatile uint32_t GPIO_CRL;
  volatile uint32_t GPIO_CRH;
  volatile uint32_t GPIO_IDR;
  volatile uint32_t GPIO_ODR;
  volatile uint32_t GPIO_BSRR;
  volatile uint32_t GPIO_BRR;
  volatile uint32_t GPIO_LCKR;
} GPIO_Typedef;

/*------------- Define bits mask for GPIO_CRL/GPIO_CRH to config mode for GPIO -----------------------*/
#define 

 
#endif