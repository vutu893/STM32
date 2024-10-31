/*--------------------------------------------------
                            DOCUMENT ABOUT AFIO IN STM32F103- DETAILS IN MANUAL IN RM0008
1. Defintion
    - Alternate Function I/O(AFIO) is a powerful peripheral that manages the con
  configuration of alternative functions for I/O pins.
    - Since each GPIO pin can serve multiple functions such as acting as a standard
  GPIO pin, an anolog input, or being mapped to a specific peripheral.
2. Functions of AFIO
a, Pin remapping:
    - Certain peripherals are mapped to specific pins by default, but with AFIOI
  you can remap these peripheral signals to diffent pins.
            Example: USART1 TX and RX are mapped to PA9 and PA10 by default, but
      can be remapped to PB6 and PB7 if required.
    - This featur is useful for avoiding conflicts when multiple peripherals need
  to use the sam pins or if a specific pin layout is necessary.
b, External interrupt(EXTI) line configuration:
    - The AFIO allows you to select which GPIO pin will act as the source for each 
  each external interrupt line (EXTI), EXTI0 can be configured to use PA0, PB0,..
c, Event output:
    - AFIO provides an Event Output function, which allows an internal signal to be routed
  to a specific GPIO pins. This can trigger an external event signal to synchronize
  or signal to other devices.
    - The event output feature selects the pin and enables output through the AFIO_EVCR
  register
d, Debug Pin configuration:
 
3. AFIO registers 
  - AFIO_EVCR: Event control register ---> Configures and enables the event output feature
  - AFIO_MAPR: Remap and Debug I/O configuration register --> Configures pin remapping for specific peripherals and enables/disable debuf features
  - AFIO_EXTICR: External interrupt configuration registers ---> Assigns a GPIO pin to each external interrupt line(EXTI)
  - AFIO_MMAPR2: Additional remap register ---> Adds extra remapping options for peripherals not covered in AFIO_MAPR.
*/