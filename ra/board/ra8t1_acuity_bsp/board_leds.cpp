
/**
 * @file board_leds.cpp
 *
 * @date Created on: 23/04/2024
 * @author João Vieira
 */
#include "board_leds.hpp"
#include "hal_data.h"

#ifndef BOARD_RA8T1_ACUITY_BSP

static const uint16_t g_bsp_prv_leds[]={
 (uint16_t)BSP_IO_PORT_00_PIN_03,//
 (uint16_t)BSP_IO_PORT_00_PIN_04,//
 (uint16_t)BSP_IO_PORT_00_PIN_05,//
 (uint16_t)BSP_IO_PORT_00_PIN_06,//
 (uint16_t)BSP_IO_PORT_00_PIN_07,//
 (uint16_t)BSP_IO_PORT_00_PIN_08,//
 (uint16_t)BSP_IO_PORT_00_PIN_09,//
 (uint16_t)BSP_IO_PORT_00_PIN_10 //
};

const bsp_leds_t g_bsp_leds = {
 .led_count = (uint16_t) ((sizeof(g_bsp_prv_leds)/ sizeof(g_bsp_prv_leds[0]))),
 .p_leds = &g_bsp_prv_leds[0]
};

void rainbow(){
   int led_count = g_bsp_leds.led_count;
   R_BSP_PinAccessEnable();

   for(int i =0; i<led_count; i++){
       R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[i], BSP_IO_LEVEL_HIGH);
       R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
       R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[i], BSP_IO_LEVEL_LOW);
   }
   R_BSP_PinAccessDisable();

}

void led_blink (uint16_t led_id , int times){
    bsp_io_level_t led_blink=BSP_IO_LEVEL_LOW;
    times*=2;
    for(int i = times; i > 0; i--){
        if(led_blink==BSP_IO_LEVEL_LOW){
            led_blink= BSP_IO_LEVEL_HIGH;
        }else{
            led_blink= BSP_IO_LEVEL_LOW;
        }
        led_update(led_id, led_blink);
        R_BSP_SoftwareDelay(500,BSP_DELAY_UNITS_MILLISECONDS );

    }
}
void leds_blink(led_state_t led_state, int times){
    bsp_io_level_t led_blink=BSP_IO_LEVEL_LOW;
        times*=2;
        for(int i = times; i > 0; i--){
            if(led_blink==BSP_IO_LEVEL_LOW){
                led_blink= BSP_IO_LEVEL_HIGH;
            }else{
                led_blink= BSP_IO_LEVEL_LOW;
            }
            led_update(led_state, led_blink);
            R_BSP_SoftwareDelay(500,BSP_DELAY_UNITS_MILLISECONDS );

        }
}

void error_blink(int times){
    led_blink(red, times);
}
void led_update (uint16_t led_id , bsp_io_level_t value){
    //BSP_IO_LEVEL_LOW
       //BSP_IO_LEVEL_HIGH
      R_BSP_PinAccessEnable();
      R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[led_id], value);
      R_BSP_PinAccessDisable();

}
 void leds_update(led_state_t led_state, bsp_io_level_t value){
    //BSP_IO_LEVEL_LOW
    //BSP_IO_LEVEL_HIGH
   R_BSP_PinAccessEnable();
    switch(led_state){
        case red:
        {
            R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[0], value);
            break;
        }
        case lime:
        {

            R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[7], value);
            R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[6], value);
            R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[5], value);
            R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[4], value);
            break;
        }
        case ambar:
        {

            R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[3], value);
            R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[2], value);
            R_IOPORT_PinWrite(&g_ioport_ctrl, (bsp_io_port_pin_t) g_bsp_leds.p_leds[1], value);
            break;
        }
        case yellow:
        case cyan:
        case blue:
        default:
        {
            break;
        }
    }
    R_BSP_PinAccessDisable();
}

void led_flip(uint16_t led_id){
    e_bsp_io_level value;
    R_IOPORT_OutputLogicFetch(&g_ioport_ctrl,(bsp_io_port_pin_t)g_bsp_leds.p_leds[led_id], &value);
    value = (e_bsp_io_level)!value;
    led_update(led_id, value);
}

#endif
