#include <cortex_m3.h>
#include <stm32f103c8t6.h>
/*-----------------------------Funtion for System Tick Timer----------------------------*/

void SysTick_SetReload(uint32_t reload)
{
  // Sets the reload value for the SysTick timer
  SYSTICK.STK_LOAD = reload & 0x00FFFFFF;
}

void SysTick_SetClock(uint32_t source)
{
  // Sets the systick clock source
  if (source == STK_CTRL_CLKSOURCE_AHB)
  {
    SYSTICK.STK_CTRL |= STK_CTRL_CLKSOURCE_AHB;
  }else
  {
    SYSTICK.STK_CTRL |= STK_CTRL_CLKSOURCE_AHB_DIV8;
  }
}

void SysTick_Enable(void)
{
  // Enables the Systick timer and interrupt 
  SYSTICK.STK_CTRL |= STK_CTRL_COUNTER_ENABLE; 
}
void SysTick_Disable(void)
{
  // Disables the systick timer and interrupt
  SYSTICK.STK_CTRL |= STK_CTRL_COUNTER_DISABLE;
}

void SysTick_EnableInterrupt(void)
{
  // Enables the systick interrupt
  SYSTICK.STK_CTRL |= STK_CTRL_TICKINT_ENABLE;                
}

void SysTick_DisableInterrupt(void)
{
  // Disable the systick interrupt 
  SYSTICK.STK_CTRL |= STK_CTRL_TICKINT_DISABLE;
}

uint32_t SysTick_GetCountFlag(void)
{
  // Get the current count flag
  return (SYSTICK.STK_CTRL & STK_CTRL_COUNTFLAG_COUNTED_TO_0) ? 1 : 0;
}

uint32_t SysTick_GetCurrentValue(void)
{
  // Read the current value of the Systick timer
  return SYSTICK.STK_VAL;
}

void SysTick_Clear(void)
{
  // Clears the systick current value register
  SYSTICK.STK_VAL = 0; 
}

void SysTick_Handle(void)
{
  // SysTick interrupt handler
}

void SysTick_Config(uint32_t reload)
{
  // Initializes the SysTick timer with a specified reload value
  SysTick_SetReload(reload);
  SysTick_Clear();
  SysTick_SetClock(STK_CTRL_CLKSOURCE_AHB);
  SysTick_EnableInterrupt();
  SysTick_Enable();
}
/*--------------------------------------- System control Block------------------------------------- */


/*--------------------------------------- Nest vector interrupt control - NVIC---------------------*/
void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if (IRQn >= 0)
  {
    NVIC.NVIC_ISER[IRQn >> 5] = (1 << (((uint32_t)IRQn) & 0x1F)); //Set bit to enable IRQ
  }
}

void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if (IRQn >= 0)
  {
    NVIC.NVIC_ICER[IRQn >> 5] = (1 << (IRQn & 0x1F));
  }
}

void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if (IRQn >= 0)
  {
    NVIC.NVIC_ISPR[IRQn >> 5] = (1 << (IRQn & 0x1F));
  }
}

void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if (IRQn >= 0)
  {
    NVIC.NVIC_ICPR[IRQn >> 5] = (1 << (IRQn & 0x1F));
  }
}

void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
   if (IRQn >= 0 && priority < (1 << NVIC_PRIORITY_BITS))
   {
      NVIC.NVIC_IPR[IRQn] = (priority << (8 - NVIC_PRIORITY_BITS));
   }
}