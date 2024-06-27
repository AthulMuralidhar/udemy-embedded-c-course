/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	// the base address of RCC: `0x40023800`
	// Address offset: 0x30
	// used to turn on the clock
	uint32_t *pClockControlRegister = (uint32_t*) (0x40023800 + 0x30);
	// the base address of GPIOD mode register: `0x40020C00`
	// Address offset: 0x00
	// used to control the mode of GPIOD
	uint32_t *pGPIODModeRegister = (uint32_t*) (0x40020C00 + 0x00);
	// the base address of GPIOD output data register: `0x40020C00`
	// Address offset: 0x14
	// used to write to the pin
	uint32_t *pGPIODOutputRegister = (uint32_t*) (0x40020C00 + 0x14);

	// step 1. enable the clock for GPIOD peripheral in AHB1ENR
	*pClockControlRegister |= 1 << 3;     // the third bit mask!

	// step 2. configure the  GPIOD_MODER to output mode for pd13
	// so 26th and 27th bits
	// a. clear the 26th and 27th bit
	*pGPIODModeRegister &= ~(1 << 26); // clear 26th bit
	*pGPIODModeRegister &= ~(1 << 27);  // clear 27th bit
	// b. set the 26th bit
	*pGPIODModeRegister |= (1 << 26);

	// step 3. SET the 13th pin of the GPIO register
	*pGPIODOutputRegister |= (1 << 13);


    /* Loop forever */
	for(;;);
}
