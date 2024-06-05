/**
 *  @file board_leds.hpp
 *
 *  @date Created on: 23/04/2024
 *  @author João Vieira
 */




#ifndef BOARD_RA8T1_ACUITY_BSP_BOARD_LEDS_H_
#define BOARD_RA8T1_ACUITY_BSP_BOARD_LEDS_H_
#ifndef   __STATIC_INLINE
  #define __STATIC_INLINE                        static inline
#endif
#include "../../src/bsp/mcu/all/bsp_exceptions.h"
#include <bsp_api.h>
#include "../../ra/fsp/src/bsp/cmsis/Device/RENESAS/Include/R7FA8T1AH.h"
#include "../../ra/fsp/src/bsp/mcu/all/bsp_io.h"

#include <stdint.h>
/* BSP MCU Specific Includes. */

typedef struct st_bsp_leds{
    uint16_t led_count;
    uint16_t const * p_leds;
}bsp_leds_t;

typedef enum
{
   red = 1,
   ambar = 2,
   yellow = 3,
   green = 4,
   lime = 5,
   cyan = 6,
   blue = 7,
   unknown
} led_state_t;



void rainbow();

void error_blink (int times);
void led_blink (uint16_t led_id , int times);
void leds_blink (led_state_t led_state , int times);

void led_update (uint16_t led_id , bsp_io_level_t value);
void leds_update (led_state_t led_state , bsp_io_level_t value);

#endif /* BOARD_RA8T1_ACUITY_BSP_BOARD_LEDS_H_ */
