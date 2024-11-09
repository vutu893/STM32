#include <basic_timer.h>


void BasicTimer_Init(BASICTIMER_TypeDef volatile *TIM, uint16_t prescaler, uint16_t auto_reload)
{
  // Set prescaler value
   TIM->PSC = prescaler;
   
   // Set auto-reload value
   TIM->ARR = auto_reload;
   
   // Generate an update event to apply the prescaler and ARR setting
   TIM->EGR |= 0x01;
   
   TIM->CR1 |= (1U << 7);
}

// Enable the basic timer
void BasicTimer_Enable(BASICTIMER_TypeDef volatile *TIM)
{
  TIM->CR1 |= 0x01;
}

//Disable the basic timer
void BasicTimer_Disable(BASICTIMER_TypeDef volatile *TIM)
{
  TIM->CR1 &= ~(0x01);
}
void BasicTimer_EnableInterrupt(BASICTIMER_TypeDef volatile *TIM)
{
  TIM->DIER |= 0x01; // Set UIE bit in DIER register to enable interrupt
}
// Disable update interrupt for the Basic Timer
void BasicTimer_DisableInterrupt(BASICTIMER_TypeDef volatile *TIMx) {
    TIMx->DIER &= ~0x01; // Clear UIE bit in DIER register to disable interrupt
}

// Clear the update interrupt flag
void BasicTimer_ClearUpdateFlag(BASICTIMER_TypeDef volatile *TIMx) {
    TIMx->SR &= ~0x01; // Clear UIF bit in SR register
}