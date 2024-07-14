#ifndef BITWISE_H
#define BITWISE_H

#include <stdint.h>

typedef struct {
    uint32_t gpioa_en:1;  // bit position: 0
    uint32_t gpiob_en:1;  // bit position: 1
    uint32_t gpioc_en:1;  // bit position: 2
    uint32_t gpiod_en:1;  // bit position: 3
    uint32_t gpioe_en:1;  // bit position: 4
    uint32_t gpiof_en:1;  // bit position: 5
    uint32_t gpiog_en:1;  // bit position: 6
    uint32_t gpioh_en:1;  // bit position: 7
    uint32_t gpioi_en:1;  // bit position: 8
    uint32_t reserved_1:3;  // bit position: 9-11
    uint32_t crc_en:1;       // bit position: 12
    uint32_t reserved_2:5;  // bit position: 13- 17
    uint32_t bkpsram_en:1;  // bit position: 18
    uint32_t reserved_3:1;  // bit position: 19
    uint32_t ccm_dataram_en:1;  // bit position: 20
    uint32_t dma1_en:1;  // bit position: 21
    uint32_t dma2_en:1;  // bit position: 22
    uint32_t reserved_4:2;  // bit position: 23-24
    uint32_t ethmac_en:1;  // bit position: 25
    uint32_t ethmac_tx_en:1;  // bit position: 26
    uint32_t ethmac_rx_en:1;  // bit position: 27
    uint32_t ethmac_ptp_en:1;  // bit position: 28
    uint32_t otghs_en:1;  // bit position: 29
    uint32_t otghs_ulpi_en:1;  // bit position: 30
    uint32_t reserved_5:1;  // bit position: 31
} RCC_AHB1ENR_t ;

typedef struct {
    uint32_t odr_0 :1; 
    uint32_t odr_1 :1; 
    uint32_t odr_2 :1; 
    uint32_t odr_3 :1; 
    uint32_t odr_4 :1; 
    uint32_t odr_5 :1; 
    uint32_t odr_6 :1; 
    uint32_t odr_7 :1; 
    uint32_t odr_8 :1; 
    uint32_t odr_9 :1; 
    uint32_t odr_10 :1; 
    uint32_t odr_11 :1; 
    uint32_t odr_12 :1; 
    uint32_t odr_13 :1; 
    uint32_t odr_14 :1; 
    uint32_t odr_15 :1; 
    uint32_t reserved :16; 
} GPIOx_ODR_t ;

typedef struct {
    uint32_t moder_0:2;  // bit pos: 0-1
    uint32_t moder_1:2;  // bit pos: 2-3
    uint32_t moder_2:2;  // bit pos: 4-5
    uint32_t moder_3:2;  // bit pos: 6-7
    uint32_t moder_4:2;  // bit pos: 8-9
    uint32_t moder_5:2;  // bit pos: 10-11
    uint32_t moder_6:2;  // bit pos: 12-13
    uint32_t moder_7:2;  // bit pos: 14-15
    uint32_t moder_8:2;  // bit pos: 16-17
    uint32_t moder_9:2;  // bit pos: 18-19
    uint32_t moder_10:2;  // bit pos: 20-21
    uint32_t moder_11:2;  // bit pos: 22-23
    uint32_t moder_12:2;  // bit pos: 24-25
    uint32_t moder_13:2;  // bit pos: 26-27
    uint32_t moder_14:2;  // bit pos: 28-29
    uint32_t moder_15:2;  // bit pos: 30-31
} GPIOx_MODER_t ;

#endif
