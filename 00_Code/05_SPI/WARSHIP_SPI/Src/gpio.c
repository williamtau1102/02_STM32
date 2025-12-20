/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
     PF0   ------> FSMC_A0
     PF1   ------> FSMC_A1
     PF2   ------> FSMC_A2
     PF3   ------> FSMC_A3
     PF4   ------> FSMC_A4
     PF5   ------> FSMC_A5
     PA5   ------> SPI1_SCK
     PA6   ------> SPI1_MISO
     PA7   ------> SPI1_MOSI
     PF12   ------> FSMC_A6
     PF13   ------> FSMC_A7
     PF14   ------> FSMC_A8
     PF15   ------> FSMC_A9
     PG0   ------> FSMC_A10
     PG1   ------> FSMC_A11
     PE7   ------> FSMC_D4_DA4
     PE8   ------> FSMC_D5_DA5
     PE9   ------> FSMC_D6_DA6
     PE10   ------> FSMC_D7_DA7
     PE11   ------> FSMC_D8_DA8
     PE12   ------> FSMC_D9_DA9
     PE13   ------> FSMC_D10_DA10
     PE14   ------> FSMC_D11_DA11
     PE15   ------> FSMC_D12_DA12
     PD8   ------> FSMC_D13_DA13
     PD9   ------> FSMC_D14_DA14
     PD10   ------> FSMC_D15_DA15
     PD11   ------> FSMC_A16_CLE
     PD12   ------> FSMC_A17_ALE
     PD13   ------> FSMC_A18
     PD14   ------> FSMC_D0_DA0
     PD15   ------> FSMC_D1_DA1
     PG2   ------> FSMC_A12
     PG3   ------> FSMC_A13
     PG4   ------> FSMC_A14
     PG5   ------> FSMC_A15
     PD0   ------> FSMC_D2_DA2
     PD1   ------> FSMC_D3_DA3
     PD4   ------> FSMC_NOE
     PD5   ------> FSMC_NWE
     PG9   ------> FSMC_NE2
     PG10   ------> FSMC_NE3
     PG12   ------> FSMC_NE4
     PE0   ------> FSMC_NBL0
     PE1   ------> FSMC_NBL1
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LED1_Pin|VS_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, VS_XDCS_Pin|VS_XCS_Pin|LIGHT_SENSOR_Pin|T_MOSI_Pin
                          |T_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_BL_Pin|T_SCK_Pin|LED0_Pin|BEEP_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, NRF_CS_Pin|NRF_CE_Pin|OV_SDA_Pin|OV_RRST_Pin
                          |OV_OE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, OV_SCL_Pin|OV_WRST_Pin|CH395Q_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : KEY2_Pin KEY1_Pin KEY0_Pin */
  GPIO_InitStruct.Pin = KEY2_Pin|KEY1_Pin|KEY0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin VS_RST_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|VS_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : VS_DREQ_Pin OV_D0_Pin OV_D1_Pin OV_D2_Pin
                           OV_D3_Pin OV_D4_Pin OV_D5_Pin OV_D6_Pin
                           OV_D7_Pin */
  GPIO_InitStruct.Pin = VS_DREQ_Pin|OV_D0_Pin|OV_D1_Pin|OV_D2_Pin
                          |OV_D3_Pin|OV_D4_Pin|OV_D5_Pin|OV_D6_Pin
                          |OV_D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PF0 PF1 PF2 PF3
                           PF4 PF5 PF12 PF13
                           PF14 PF15 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : VS_XDCS_Pin VS_XCS_Pin LIGHT_SENSOR_Pin T_MOSI_Pin
                           T_CS_Pin */
  GPIO_InitStruct.Pin = VS_XDCS_Pin|VS_XCS_Pin|LIGHT_SENSOR_Pin|T_MOSI_Pin
                          |T_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pin : T_PEN_Pin */
  GPIO_InitStruct.Pin = T_PEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(T_PEN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_BL_Pin T_SCK_Pin LED0_Pin BEEP_Pin */
  GPIO_InitStruct.Pin = LCD_BL_Pin|T_SCK_Pin|LED0_Pin|BEEP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : T_MISO_Pin REMOTE_IN_Pin */
  GPIO_InitStruct.Pin = T_MISO_Pin|REMOTE_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PG0 PG1 PG2 PG3
                           PG4 PG5 PG9 PG10
                           PG12 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PE7 PE8 PE9 PE10
                           PE11 PE12 PE13 PE14
                           PE15 PE0 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PD8 PD9 PD10 PD11
                           PD12 PD13 PD14 PD15
                           PD0 PD1 PD4 PD5 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15
                          |GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : NRF_IRQ_Pin WIRE_DQ_Pin */
  GPIO_InitStruct.Pin = NRF_IRQ_Pin|WIRE_DQ_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : NRF_CS_Pin NRF_CE_Pin OV_RRST_Pin OV_OE_Pin */
  GPIO_InitStruct.Pin = NRF_CS_Pin|NRF_CE_Pin|OV_RRST_Pin|OV_OE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pin : OV_VSYNC_Pin */
  GPIO_InitStruct.Pin = OV_VSYNC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OV_VSYNC_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : OV_SCL_Pin */
  GPIO_InitStruct.Pin = OV_SCL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OV_SCL_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OV_WRST_Pin CH395Q_RST_Pin */
  GPIO_InitStruct.Pin = OV_WRST_Pin|CH395Q_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : OV_SDA_Pin */
  GPIO_InitStruct.Pin = OV_SDA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OV_SDA_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
