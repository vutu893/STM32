#include  <gpio.h>


/* ---------------------------------------------------------
- FUNCTION: GPIO_Mode(volatile GPIO_TypeDef* GPIO, unsigned int PIN, GPIO_MODE Mode)
- PURPOSE: implement a mode for a pin in stm32f103
- DESCRIPTION:  pre: reset, set is 4 bytes, GPIO_MODE is 4 bytes
                      PIN is 4 bytes too.
      Example: GPIO_Mode(&GPIOA, 4,GPIO_MODE_AF_OUTPUT_PUSHPULL_10MHz);
      Details: 
            
*/
void GPIO_Mode(volatile GPIO_TypeDef* GPIO, unsigned int PIN, GPIO_MODE Mode)
{
  unsigned int reset = 0, set = 0;
  for (unsigned int i = 0; i < 8; i++)
  {
    reset <<= 4;
    set <<= 4;
    if (PIN & (1UL << 15))
        set |= Mode;
    else
        reset |= 0x0F;
    PIN <<= 1;
  }
  GPIO->CRH.REG &= reset; //clear 4 bit corresponding to the pin
  GPIO->CRH.REG |= set; // Set the new mode 
  
  reset = 0; set = 0;
  for (unsigned int i = 0; i < 8; i++)
  {
     reset <<= 4;
     set <<= 4;
     if (PIN & (1UL << 15))
        set |= Mode;
     else
        reset |= 0x0F;
     PIN <<= 1;
  }
  GPIO->CRL.REG &= reset; // Clear 4 bit corresponding to the pin
  GPIO->CRL.REG != set;   // Set the new mode
}

/* -------------------------------------------------------------------
- FUNCTION: GPIO_Mode_2 (way two above)
- DESCRIPTION: GPIO_Mode_2(volatile GPIO_TypeDef* GPIO, unsigned int PIN, GPIO_MODE Mode);

*/
void GPIO_Mode_2( volatile GPIO_TypeDef* GPIO, unsigned int PIN, GPIO_MODE Mode)
{
  volatile unsigned long* res = (PIN < 8) ? &GPIO->CRL.REG : &GPIO->CRH.REG; //check PIN in CRL or CRH
  
  unsigned int pos = (PIN%8) *4; // Caculate bit position
  
  *res &= ~(0xF << pos); //Clear 4 bits corresponing to the pin
  *res |= (Mode << pos); //Set the new mode
}

/* -------------------------------------------------------------------
- FUNCTION: GPIO_Read(volatile GPIO_TypeDef* GPIO, unsigned int PIN);
- DESCRIPTION: unsigned char GPIO_Read(volatile GPIO_TypeDef* GPIO, unsigned int PIN);

*/
unsigned char GPIO_Read(volatile GPIO_TypeDef* GPIO, unsigned int PIN)
{
  // Read the bit corresponding to the specific pin and return its state (0 or 1)
  // Register IDRy: y = 0-15 corresponding pin for each GPIO
  return (GPIO->IDR.REG & (1 << PIN)) ? 1 : 0;
}

/* -------------------------------------------------------------------
- FUNCTION: GPIO_Write(volatile GPIO_TypeDef* GPIO, unsigned int PIN, unsigned char State);
- DESCRIPTION: void GPIO_Write(volatile GPIO_TypeDef* GPIO, unsigned int PIN, unsigned char State);
- IMPLEMENT: 
          To implement a GPIO_Write function for STM32F103, you can use the Bit Set/Reset Register (BSRR)
      or Output Data Register (ODR) of the GPIO port. The BSRR register is generally preferred because it
      allows atomic operations—setting and resetting bits without affecting the other bits in the register.
 
*/
void GPIO_Write(volatile GPIO_TypeDef* GPIO, unsigned int PIN, unsigned char State)
{
  if (State)
      //Set the pin by writing to the lower 16 bits of BSRR
      GPIO->BSRR.REG = PIN;
  else
      //Reset the pin by writing to the upper 16 bits of BSRR
      GPIO->BSRR.REG = (unsigned long) (PIN << 16);
}

// USE ODR
void GPIO_Write_ODR(volatile GPIO_TypeDef* GPIO, unsigned int PIN, unsigned char State)
{
  if (State)
    GPIO->ODR.REG |= PIN; //Set the pin 
  else
    GPIO->ODR.REG &= ~PIN; //Reset the pin      
}

/* -------------------------------------------------------------------
- FUNCTION: GPIO_TOGGLE(volatile GPIO_TypeDef* GPIO, unsigned int PIN)
- DESCRIPTION: This can be done by reading the current state of the pin from the ODR register and then
                toggling the corresponding bit.
*/

void GPIO_Toggle(volatile GPIO_TypeDef* GPIO, unsigned int PIN)
{
  // Check the current state of pin by reading the ODR register
  if (GPIO->ODR.REG  & PIN)
  {
      // If the pin is set -> reset it 
    GPIO->BSRR.REG =(unsigned int) (PIN << 16); // Use BSRR to reset the pin to low
  }else
  {
    GPIO->BSRR.REG = (unsigned int)PIN; //Use BSRR to set the pin to high
  }
}