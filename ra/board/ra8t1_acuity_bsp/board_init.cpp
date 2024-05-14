/**
 * @file board_init.cpp
 *
 *  @date Created on: 23/04/2024
 *  @author João Vieira
 */
#include "board_init.hpp"
#include <unordered_map>

typedef enum {
    CANFD_LITE_UNIT0_CHANNEL0 = 1,
    CANFD_LITE_UNIT0_CHANNEL1 = 2,
    CANFD_EXTERNAL_SPI_CHANNEL0 = 3
}e_total_can_channels;

static std::unordered_map<uint16_t, e_acuity_can_status> g_bsp_prv_can_t {
    {CANFD_LITE_UNIT0_CHANNEL0, AVAILABLE},
    {CANFD_LITE_UNIT0_CHANNEL1, AVAILABLE},
    {CANFD_EXTERNAL_SPI_CHANNEL0, AVAILABLE}
};
