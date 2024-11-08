#include <exti.h>
#include <myAFIO.h>
#include <stm32f103c8t6.h>
/*
*@brief
*@param 
*@param 
*@param 
*@return 
*/

/*
*@brief: Initializes the EXTI line for a specific GPIO pin with the specified trigger type
*@param pin: GPIO pin number 0 - 15 to configure EXTI line
*@param port: GPIO port('A', 'B', 'C') corresponding to the pin
*@param edge_type: Trigger type (rising, falling, or both edges)
*@return None
*/
void EXTI_Init(uint8_t pin, char port, EXTI_EdgeType edge_type)
{
  // Enable AFIO clock
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    
  // Map the EXTI line to the appopriate GPIO port
    uint32_t port_selected = 0;
    switch (port)
    {
    case 'A': port_selected = 0x0; break;
    case 'B': port_selected = 0x1; break;
    case 'C': port_selected = 0x2; break;
    default: return;
    }
    
    // Configure the EXTI line to the selected port in AFIO_EXTICR
    uint8_t exti_index = pin / 4;
    uint8_t exti_pos = (pin % 4) *4;
    AFIO->EXTICR[exti_index] &= ~( 0xF << exti_pos); // clearn current config
    AFIO->EXTICR[exti_index] |= (port_selected << exti_pos);
    
    // Confige edge trigger (rising, falling, or both)
    if (edge_type == EXTI_RISING_EDGE || edge_type == EXTI_BOTH_EDGE)
        EXTI->RTSR |= (1 << pin); // Enable rising edge trigger
    else
        EXTI->RTSR &= ~(1 << pin); // Disable rising edge trigger
    
    if (edge_type == EXTI_FALLING_EDGE || edge_type == EXTI_BOTH_EDGE)
        EXTI->FTSR |= (1 << pin);
    else
        EXTI->FTSR &= ~(1 << pin);
    
    // Enable the interrupt line in IMR
    EXTI_EnableInterrupt(pin);
}

/*
*@brief          Enables interrupt on the specified EXTI line
*@param          pin: GPIO pin number 0 to 15 corresponding to the EXTI line
*@return        None
*/
void EXTI_EnableInterrupt(uint8_t pin)
{
  EXTI->IMR |= (1 << pin);
}

/*
*@brief         Disable interrupt on the specified EXTI line
*@param         pin: GPIO pin number 0 to 15 corresponding to the EXTI line
*@return        None
*/
void EXTI_DisableInterrupt(uint8_t pin)
{
  EXTI->IMR &= ~(1 << pin);
}

/*
*@brief         Clears the pending interrupt flag for the specified EXTI line.
*@param         pin: GPIO pin number (0 to 15) corresponding to the EXTI line.
*@return        None
*/
void EXTI_ClearPending(uint8_t pin)
{
  EXTI->PR |= (1 << pin);  // Clear the pending bit by writing 1
}

/*
* @brief  Sets a software interrupt for the specified EXTI line.
* @param  pin: GPIO pin number (0 to 15) corresponding to the EXTI line.
* @retval None
*/
void EXTI_GenerateSWInterrupt(uint8_t pin) {
    EXTI->SWIER |= (1 << pin);  // Set the software interrupt/event for the EXTI line
}