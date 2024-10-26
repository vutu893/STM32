#include <gpio.h>
#include <myRCC.h>

__root __no_init volatile GPIO_TypeDef GPIOC @ (0x40011000U);
__root __no_init volatile RCC_TypeDef RCC @ (0x40021000U);

void main()
{
  RCC_Init(&RCC);
  GPIO_Mode(&GPIOC, 1U << 13, GPIO_MODE_OUTPUT_PUSHPULL_10MHz);
  while(1)
  {
    GPIO_Toggle(&GPIOC, 1U << 13);
    for (int i = 0; i < 6; i++)
    {
      for (int j = 0; j < 500000; j++);
    }
  }
}