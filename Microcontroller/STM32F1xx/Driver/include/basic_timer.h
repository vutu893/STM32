#ifndef _BASIC_TIMER_H_
#define _BASIC_TIMER_H_

#include <stdint.h>

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t reserved1;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t reserved2[3];
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
}BASICTIMER_TypeDef;

//function prototype for basic timer
void BasicTimer_Init(BASICTIMER_TypeDef volatile *TIM, uint16_t prescaler, uint16_t auto_reload);
void BasicTimer_Enable(BASICTIMER_TypeDef volatile *TIM);
void BasicTimer_Disable(BASICTIMER_TypeDef volatile *TIM);
void BasicTimer_EnableInterrupt(BASICTIMER_TypeDef volatile *TIM);
void BasicTimer_DisableInterrupt(BASICTIMER_TypeDef volatile *TIM);
void BasicTimer_ClearUpdateFlag(BASICTIMER_TypeDef volatile *TIM);

#endif