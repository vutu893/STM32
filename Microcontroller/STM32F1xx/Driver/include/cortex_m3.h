#ifndef _CORTEX_M3_H_
#define _CORTEX_M3_H_

#include <stdint.h>

/* Base addresses for core peripheral */
#define SCB_BASE        (0xE000ED00U)   // System control block base address
#define SYSTICK_BASE    (0xE000E010U)   // Systick base address
#define NVIC_BASE       (0xE000E100U)   // NVIC base address


/*-----------------------------------------Define register of system tick timer(STK)-------------------------------------------------------*/
typedef struct
{
  uint32_t STK_CTRL; // SysTick control and status
  uint32_t STK_LOAD; // SysTick reload 
  uint32_t STK_VAL; // SysTick current value register
  uint32_t STK_CALIB;// SysTick calibration value register
} SYSTICK_TypeDef;

__root __no_init volatile SYSTICK_TypeDef SYSTICK @ (0xE000E010U);

#define STK_CTRL_COUNTFLAG_COUNTED_TO_0        (1U << 16)
#define STK_CTRL_CLKSOURCE_AHB_DIV8            (0U << 2)
#define STK_CTRL_CLKSOURCE_AHB                 (1U << 2)
#define STK_CTRL_TICKINT_DISABLE               (0U << 1)
#define STK_CTRL_TICKINT_ENABLE                (1U << 1)
#define STK_CTRL_COUNTER_ENABLE                (1U << 0)
#define STK_CTRL_COUNTER_DISABLE               (0U << 0)

// prototy function for systick
void SysTick_Config(uint32_t reload);
void SysTick_SetReload(uint32_t reload);
void SysTick_SetClockSource(uint32_t source);
void SysTick_Enable(void);
void SysTick_Disable(void);
void SysTick_EnableInterrupt(void);
void SysTick_DisableInterrupt(void);
uint32_t SysTick_GetCountFlag(void);
uint32_t SysTick_GetCurrentValue(void);
void SysTick_Clear(void);
void SysTick_Handler(void);

/*-------------------------------------------- Define register of SCB system control block ---------------------------------------------------- */
typedef struct
{
  uint32_t SCB_ACTLR;
  uint32-t SCB_CPUID;
  uint32_t SCB_ICSR;
  uint32_t SCB_VTOR;
  uint32_t SCB_AIRCR;
  uint32_t SCB_SCR;
  uint32_t SCB_CCR;
  uint32_t SCB_SHPR1;
  uint32_t SCB_SHPR2;
  uint32_t SCB_SHPR3;
  uint32_t SCB_SHCRS;
  uint32_t SCB_CFSR;
  uint32_t SCB_HFSR;
  uint32_t SCB_MMAR;
  uint32_t SCB_BFAR;
} SCB_TypeDef;

/*--------------------------------------------- Define register of NVIC(Nest vector interrupt control)-----------------------------------------*/
typedef struct
{
  uint32_t NVIC_ISER[3]; // Enable interrupts
  uint32_t NVIC_ICER[3]; // Disable interrupts
  uint32_t NVIC_ISPR[3]; // Sets the pending status of interrupts
  uint32_t NVIC_ICPR[3]; // Clears the pending status of interrupts
  uint32_t NVIC_IABR[3]; // Shows if an interrupt is currently active
  uint32_t NVIC_IPR[21];   // Sets the priority level for each interrupt 
  uint32_t NVIC_STIR;
} NVIC_TypeDef;

__root __no_init volatile NVIC_TypeDef NVIC @ (0xE000E100U);
// Define IRQn_Type
typedef enum
{
  // Cortex-M core exceptions (negative IQR numbers)
  NonMaskableInt_IRQn   = -14,
  HardFault_IRQn        = -13,
  MemoryManagement_IRQn = -12,
  BusFault_IRQn         = -11,
  UsageFault_IRQn       = -10,
  SVCall_IRQn           = -5,
  DebugMonitor_IRQn     = -4,
  PendSV_IRQn           = -2,
  SysTick_IRQn          = -1,
  
  //Device specific IRQ number
  WWDG_IRQn             = 0,
  PVD_IRQn              = 1,
  TAMPER_IRQn           = 2,
  // add if necessary
}IRQn_Type;
//define mask for register of NVIC
#define NVIC_PRIORITY_BITS  (4)
// Prototype functions of NVIC
void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
//uint32_t NVIC_GetActive(IRQn_Type IRQn);
void NVIC_SetPriority((IRQn_Type IRQn, uint32_t priority);
//uint32_t NVIC_GetPriority(IRQn_Type IRQn);
#endif