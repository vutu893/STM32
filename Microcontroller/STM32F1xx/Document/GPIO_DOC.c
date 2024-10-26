/*--------------------------------------------------------------------------
                                    DOCUMENT GPIO IN STM32F103 - DETAILS IN MANUAL RM0008 OF STM
     The GPIO registers in the STM32F103 microcontroller— CRL, CRH, BSRR, ODR, and IDR—allow you
to configure, read, and manipulate the behavior of individual pins. 

1. CRL (Configuration Register Low)
  The CRL register configures the mode and configuration of the first 8 GPIO pins (from GPIO_PIN_0 to GPIO_PIN_7).
      MODE (2 bits): Defines the mode for the pin (input, output) and its speed for output mode (2 MHz, 10 MHz, or 50 MHz).
      CNF (2 bits): Defines the configuration (input type or output type like push-pull, open-drain, etc.).
      Each pin is controlled by 4 bits (2 for MODE and 2 for CNF).

2. CRH (Configuration Register High)
  The CRH register works exactly like CRL, but it configures pins GPIO_PIN_8 to GPIO_PIN_15.
  The structure and behavior are the same: 2 bits for MODE and 2 bits for CNF, controlling 8 pins at a time.

3. ODR (Output Data Register)
  The ODR register controls the output state of each GPIO pin (HIGH or LOW) in output mode. Each bit
in the register corresponds to one GPIO pin: 
    Bit 0 for GPIO_PIN_0,
    Bit 1 for GPIO_PIN_1,
    ... and so on up to Bit 15 for GPIO_PIN_15.
  Writing 1 to a bit sets the corresponding pin to HIGH, and writing 0 sets it to LOW.

4. IDR (Input Data Register)
  The IDR register holds the current input state of each GPIO pin in input mode. Each bit corresponds to the state of one GPIO pin:
    Bit 0 for GPIO_PIN_0,
    Bit 1 for GPIO_PIN_1,
    ... and so on up to Bit 15 for GPIO_PIN_15.
  This register is read-only, meaning you can check the state of the pins but not modify it directly.

5. BSRR (Bit Set/Reset Register)
  The BSRR register is used to set or reset individual GPIO pins in a single atomic operation. It allows you to:
     Set a pin HIGH: Write 1 to the lower 16 bits.
     Reset a pin to LOW: Write 1 to the upper 16 bits.
  This approach prevents race conditions that can occur when writing directly to the ODR register.



----------------> Different between when use GPIO_MODE and GPIO_Read, GPIO_Write, GPIO_Toggle:  <--------------------------------------
      GPIO_Mode: Affects the configuration of multiple pins collectively for a GPIO port (using CRL and CRH).
      BSRR and ODR: Allow for manipulation of individual pins:
                    BSRR: For setting or resetting pins in an atomic operation.
                    ODR: For reading or writing the output state of specific pins.
*/