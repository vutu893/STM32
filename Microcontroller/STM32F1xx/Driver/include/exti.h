#ifndef _EXTI_H_
#define _EXTI_H_

#include <stdint.h>


// address base of EXTI
#define EXTI_ADDRESS_BASE       (0x40010400U)

// Map register of EXTI
typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
}EXTI_TypeDef;

// Edge interrupt type of EXTI
typedef enum
{
  EXTI_RISING_EDGE,
  EXTI_FALLING_EDGE,
  EXTI_BOTH_EDGE        
}EXTI_EdgeType;



void EXTI_Init(uint8_t pin,char port, EXTI_EdgeType edge_type);
void EXTI_EnableInterrupt(uint8_t pin);
void EXTI_DisableInterrupt(uint8_t pin);
void EXTI_ClearPending(uint8_t pin);
void EXTI_GenerateSWInterrupt(uint8_t pin);

#endif