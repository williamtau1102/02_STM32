/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY2_Pin GPIO_PIN_2
#define KEY2_GPIO_Port GPIOE
#define KEY1_Pin GPIO_PIN_3
#define KEY1_GPIO_Port GPIOE
#define KEY0_Pin GPIO_PIN_4
#define KEY0_GPIO_Port GPIOE
#define LED1_Pin GPIO_PIN_5
#define LED1_GPIO_Port GPIOE
#define VS_RST_Pin GPIO_PIN_6
#define VS_RST_GPIO_Port GPIOE
#define VS_DREQ_Pin GPIO_PIN_13
#define VS_DREQ_GPIO_Port GPIOC
#define VS_XDCS_Pin GPIO_PIN_6
#define VS_XDCS_GPIO_Port GPIOF
#define VS_XCS_Pin GPIO_PIN_7
#define VS_XCS_GPIO_Port GPIOF
#define LIGHT_SENSOR_Pin GPIO_PIN_8
#define LIGHT_SENSOR_GPIO_Port GPIOF
#define T_MOSI_Pin GPIO_PIN_9
#define T_MOSI_GPIO_Port GPIOF
#define T_PEN_Pin GPIO_PIN_10
#define T_PEN_GPIO_Port GPIOF
#define OV_D0_Pin GPIO_PIN_0
#define OV_D0_GPIO_Port GPIOC
#define OV_D1_Pin GPIO_PIN_1
#define OV_D1_GPIO_Port GPIOC
#define OV_D2_Pin GPIO_PIN_2
#define OV_D2_GPIO_Port GPIOC
#define OV_D3_Pin GPIO_PIN_3
#define OV_D3_GPIO_Port GPIOC
#define OV_D4_Pin GPIO_PIN_4
#define OV_D4_GPIO_Port GPIOC
#define OV_D5_Pin GPIO_PIN_5
#define OV_D5_GPIO_Port GPIOC
#define LCD_BL_Pin GPIO_PIN_0
#define LCD_BL_GPIO_Port GPIOB
#define T_SCK_Pin GPIO_PIN_1
#define T_SCK_GPIO_Port GPIOB
#define T_MISO_Pin GPIO_PIN_2
#define T_MISO_GPIO_Port GPIOB
#define T_CS_Pin GPIO_PIN_11
#define T_CS_GPIO_Port GPIOF
#define NRF_IRQ_Pin GPIO_PIN_6
#define NRF_IRQ_GPIO_Port GPIOG
#define NRF_CS_Pin GPIO_PIN_7
#define NRF_CS_GPIO_Port GPIOG
#define NRF_CE_Pin GPIO_PIN_8
#define NRF_CE_GPIO_Port GPIOG
#define OV_D6_Pin GPIO_PIN_6
#define OV_D6_GPIO_Port GPIOC
#define OV_D7_Pin GPIO_PIN_7
#define OV_D7_GPIO_Port GPIOC
#define OV_VSYNC_Pin GPIO_PIN_8
#define OV_VSYNC_GPIO_Port GPIOA
#define OV_SCL_Pin GPIO_PIN_3
#define OV_SCL_GPIO_Port GPIOD
#define OV_WRST_Pin GPIO_PIN_6
#define OV_WRST_GPIO_Port GPIOD
#define CH395Q_RST_Pin GPIO_PIN_7
#define CH395Q_RST_GPIO_Port GPIOD
#define WIRE_DQ_Pin GPIO_PIN_11
#define WIRE_DQ_GPIO_Port GPIOG
#define OV_SDA_Pin GPIO_PIN_13
#define OV_SDA_GPIO_Port GPIOG
#define OV_RRST_Pin GPIO_PIN_14
#define OV_RRST_GPIO_Port GPIOG
#define OV_OE_Pin GPIO_PIN_15
#define OV_OE_GPIO_Port GPIOG
#define LED0_Pin GPIO_PIN_5
#define LED0_GPIO_Port GPIOB
#define BEEP_Pin GPIO_PIN_8
#define BEEP_GPIO_Port GPIOB
#define REMOTE_IN_Pin GPIO_PIN_9
#define REMOTE_IN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
