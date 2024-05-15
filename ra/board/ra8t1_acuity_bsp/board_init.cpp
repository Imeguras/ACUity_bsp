/**
 * @file board_init.cpp
 *
 *  @date Created on: 23/04/2024
 *  @author João Vieira
 */
#include "board_init.hpp"
#include <unordered_map>

/**
 * A map to keep track of the state of the can buses, its just an aid and shouldn't be used for non setup purposes
*/
static std::unordered_map<uint16_t, e_acuity_can_status> g_bsp_prv_can_t {
    {CANFD_LITE_UNIT0_CHANNEL0, AVAILABLE},
    {CANFD_LITE_UNIT0_CHANNEL1, AVAILABLE},
    {CANFD_EXTERNAL_SPI_CHANNEL0, AVAILABLE}
};
/**
* @brief getter for the can bus state
* @param id the id of the virtualized channel
* @return the state of the can bus
*/
e_acuity_can_status g_canStateKernel(uint16_t id){
	return g_bsp_prv_can_t[id];
}
/**
* @brief setter for the can bus state
* @param id_target the id of the virtualized channel to be changed
* @param ingress_status the desired state of the can bus
* @return void
*/
void s_canStateKernel(uint16_t id_target, e_acuity_can_status ingress_status){
	//check if id_target exists
	if(g_bsp_prv_can_t.find(id_target) != g_bsp_prv_can_t.end()){
		g_bsp_prv_can_t[id_target] = ingress_status;
	}

}
