/**
 * @file board_init.hpp
 *
 *  @date Created on: 23/04/2024
 *  @author João Vieira
 */


#ifndef BOARD_RA8T1_BSP_BOARD_H_
#define BOARD_RA8T1_BSP_BOARD_H_
#ifndef   __STATIC_INLINE
  #define __STATIC_INLINE                        static inline
#endif
#include "../../src/bsp/mcu/all/bsp_exceptions.h"
#include <bsp_api.h>
#include "../../ra/fsp/src/bsp/cmsis/Device/RENESAS/Include/R7FA8T1AH.h"
#include "../../ra/fsp/src/bsp/mcu/all/bsp_io.h"
#include <stdint.h>
#include <fsp_common_api.h>
#include <r_ioport_api.h>
//#include <r_ioport.h>
#define RENESAS_IOPORT_PRV_PORT_ADDRESS(port_number)    ((uint32_t) (R_PORT1 - R_PORT0) * (port_number) + R_PORT0)
#define RENESAS_IOPORT_PRV_PORT_OFFSET            (8U)
#define RENESAS_IOPORT_PRV_8BIT_MASK                      (0xFFU)
#define IOPORT_PRV_PIN_BITS               (0x00FFU)
#define IOPORT_PRV_PORT_BITS              (0xFF00U)
fsp_err_t R_IOPORT_OutputLogicFetch (ioport_ctrl_t * const p_ctrl,
                                     bsp_io_port_pin_t         port,
                                     bsp_io_level_t * value);

#endif
