/**
 * @file board_init.cpp
 *
 *  @date Created on: 23/04/2024
 *  @author João Vieira
 */
#include "board_init.hpp"

fsp_err_t R_IOPORT_OutputLogicFetch (ioport_ctrl_t * const p_ctrl,
                                     bsp_io_port_pin_t         pin,
                                     bsp_io_level_t * value){

#if (1 == IOPORT_CFG_PARAM_CHECKING_ENABLE)
    ioport_instance_ctrl_t * p_instance_ctrl = (ioport_instance_ctrl_t *) p_ctrl;
    FSP_ASSERT(NULL != p_instance_ctrl);
    FSP_ERROR_RETURN(IOPORT_OPEN == p_instance_ctrl->open, FSP_ERR_NOT_OPEN);
    FSP_ERROR_RETURN(mask > (ioport_size_t) 0, FSP_ERR_INVALID_ARGUMENT);
#else
    FSP_PARAMETER_NOT_USED(p_ctrl);
#endif
    bsp_io_port_t port    = (bsp_io_port_t) (IOPORT_PRV_PORT_BITS & (ioport_size_t) pin);
    /* Get the port address */
    R_PORT0_Type * p_ioport_regs = RENESAS_IOPORT_PRV_PORT_ADDRESS((port >> RENESAS_IOPORT_PRV_PORT_OFFSET) & RENESAS_IOPORT_PRV_8BIT_MASK);
    //now lets get PODR
    uint8_t level =  p_ioport_regs->PODR & 0x1U;

    if(level){
        *value = BSP_IO_LEVEL_HIGH;
    }else{
        *value = BSP_IO_LEVEL_LOW;
    }
    return FSP_SUCCESS;
}
