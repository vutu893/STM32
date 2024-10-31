#ifndef _AFIO_H_
#define _AFIO_H_

#include <stdint.h>

#define AFIO_BASE (0x40010000U)

/* AFIO register structure */
typedef struct
{
  volatile uint32_t EVCR; // Event control register
  volatile uint32_t MAPR; // Remap and Debug IO configuration
  volatile uint32_t EXTICR[4]; //External interrupt confuguration
  volatile uint32_t MAPR2; // Additional remap register
} AFIO_TypeDef;

/* AFIO register instance */
#define AFIO            ((AFIO_TypeDef *) AFIO_BASE)



/*--------------------- Define AFIO_EVCR register ---------------*/
#define AFIO_EVCR_ENB           (0x1U << 7)  // Event output enable

#define AFIO_EVCR_PORTA         (0U << 4)  // PA selected
#define AFIO_EVCR_PORTB         (1U << 4)  // PB selected
#define AFIO_EVCR_PORTC         (2U << 4)  // PC selected
#define AFIO_EVCR_PORTD         (3U << 4)  // PD selected
#define AFIO_EVCR_PORTE         (4U << 4)  // PE selected

#define AFIO_EVCR_PIN0          (0U << 0)  // Px0 selected
#define AFIO_EVCR_PIN1          (1U << 0)  // Px1 selected
#define AFIO_EVCR_PIN2          (2U << 0)  // Px2 selected
#define AFIO_EVCR_PIN3          (3U << 0)  // Px3 selected
#define AFIO_EVCR_PIN4          (4U << 0)  // Px4 selected
#define AFIO_EVCR_PIN5          (5U << 0)  // Px5 selected
#define AFIO_EVCR_PIN6          (6U << 0)  // Px6 selected
#define AFIO_EVCR_PIN7          (7U << 0)  // Px7 selected
#define AFIO_EVCR_PIN8          (8U << 0)  // Px8 selected
#define AFIO_EVCR_PIN9          (9U << 0)  // Px0 selected
#define AFIO_EVCR_PIN10         (10U << 0) // Px10 selected
#define AFIO_EVCR_PIN11         (11U << 0) // Px11 selected
#define AFIO_EVCR_PIN12         (12U << 0) // Px12selected
#define AFIO_EVCR_PIN13         (13U << 0) // Px13selected
#define AFIO_EVCR_PIN14         (14U << 0) // Px14 selected
#define AFIO_EVCR_PIN15         (15U << 0) // Px15 selected

/*---------------------- Define AFIO_MAPR register --------------*/
#define AFIO_MAPR_SWJ_CFG_RESET         (0U << 24)              //Reset state
#define AFIO_MAPR_SWJ_CFG_NOT_NJTRST    (1U << 24)              //full SWJ, without NJTRST
#define AFIO_MAPR_SWJ_CFG_SWDP_ENB      (2U << 24)              // SW-DP enable
#define AFIO_MAPR_SWJ_CFG_SWDP_DISENB   (3U << 24)              // SW-DP disable

#define AFIO_MAPR_ADC2_ETRGREG_REMAP    (1U << 20)              // 
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP    (1U << 19)              //      
#define AFIO_MAPR_ADC1_ETRGREG_REMAP    (1U << 18)              // 
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP    (1U << 17)              //    

#define AFIO_TIM5CH4_IREMAP             (1U << 16)              //

#define AFIO_CAN_REMAP




/*--------------------------- Define AFIO_EXTICR1 -------------------------*/
/*--------------------------- Define AFIO_EXTICR2 - ------------------------*/
/*--------------------------- Define AFIO_EXTICR3 -------------------------*/
/*--------------------------- Define AFIO_EXTICR4 -------------------------*/
/*--------------------------- Define AFIO_MAPR2 -------------------------*/
#endif