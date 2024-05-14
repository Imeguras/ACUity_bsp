/**
 * @file board_init.hpp
 *
 *  @date Created on: 23/04/2024
 *  @author João Vieira
 */
#include <stdint.h>

#ifndef BOARD_RA8T1_BSP_BOARD_H_
#define BOARD_RA8T1_BSP_BOARD_H_
/**
 * Just a simple type to be more readable
 * OCCUPIED: describes the state when a can bus is already opened and fully operational
 * AVAILABLE: describes the state when a can bus can presumably open communication
 * UNAVAILABLE: describes the state when a can bus either was configured in the "kernel" to not be operational or external hardware issues exist
 * ERROR:  describes the state when a can bus is facing errors or problems.
 */
typedef enum{
    OCCUPIED=0, /**< OCCUPIED */
    AVAILABLE=1, /**< AVAILABLE */
    UNAVAILABLE=2, /**< UNAVAILABLE */
    ERROR       /**< ERROR */
}e_acuity_can_status;


#endif
