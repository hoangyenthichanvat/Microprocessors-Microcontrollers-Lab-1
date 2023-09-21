/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void clearAllClock(){
    //TODO
    for(int i = 4 ; i <= 15; i++)
{
    HAL_GPIO_WritePin(GPIOA, 1 << i, RESET);
}
}
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_GPIO_WritePin(hour0_GPIO_Port, hour0_Pin, SET);
  HAL_GPIO_WritePin(hour1_GPIO_Port, hour1_Pin, SET);
  HAL_GPIO_WritePin(hour2_GPIO_Port, hour2_Pin, SET);
  HAL_GPIO_WritePin(hour3_GPIO_Port, hour3_Pin, SET);
  HAL_GPIO_WritePin(hour4_GPIO_Port, hour4_Pin, SET);
  HAL_GPIO_WritePin(hour5_GPIO_Port, hour5_Pin, SET);

  HAL_GPIO_WritePin(hour6_GPIO_Port, hour6_Pin, SET);
  HAL_GPIO_WritePin(hour7_GPIO_Port, hour7_Pin, SET);
  HAL_GPIO_WritePin(hour8_GPIO_Port, hour8_Pin, SET);
  HAL_GPIO_WritePin(hour9_GPIO_Port, hour9_Pin, SET);
  HAL_GPIO_WritePin(hour10_GPIO_Port, hour10_Pin, SET);
  HAL_GPIO_WritePin(hour11_GPIO_Port, hour11_Pin, SET);

  HAL_GPIO_TogglePin(hour0_GPIO_Port, hour0_Pin);
  HAL_GPIO_TogglePin(hour1_GPIO_Port, hour1_Pin);
  HAL_GPIO_TogglePin(hour2_GPIO_Port, hour2_Pin);
  HAL_GPIO_TogglePin(hour3_GPIO_Port, hour3_Pin);
  HAL_GPIO_TogglePin(hour4_GPIO_Port, hour4_Pin);
  HAL_GPIO_TogglePin(hour5_GPIO_Port, hour5_Pin);
  HAL_GPIO_TogglePin(hour6_GPIO_Port, hour6_Pin);
  HAL_GPIO_TogglePin(hour7_GPIO_Port, hour7_Pin);
  HAL_GPIO_TogglePin(hour8_GPIO_Port, hour8_Pin);
  HAL_GPIO_TogglePin(hour9_GPIO_Port, hour9_Pin);
  HAL_GPIO_TogglePin(hour10_GPIO_Port, hour10_Pin);
  HAL_GPIO_TogglePin(hour11_GPIO_Port, hour11_Pin);

  int count = 0;

  while (1)
  {
	  if (count == 0) {
		  HAL_GPIO_TogglePin(hour0_GPIO_Port, hour0_Pin);
		    HAL_GPIO_TogglePin(hour1_GPIO_Port, hour1_Pin);
		    HAL_GPIO_TogglePin(hour2_GPIO_Port, hour2_Pin);
		    HAL_GPIO_TogglePin(hour3_GPIO_Port, hour3_Pin);
		    HAL_GPIO_TogglePin(hour4_GPIO_Port, hour4_Pin);
		    HAL_GPIO_TogglePin(hour5_GPIO_Port, hour5_Pin);
	  }
	  else {
		  count = -1;
		  clearALLClock();
	  }
	  count++;
	 HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, hour0_Pin|hour1_Pin|hour2_Pin|hour3_Pin
                          |hour4_Pin|hour5_Pin|hour6_Pin|hour7_Pin
                          |hour8_Pin|hour9_Pin|hour10_Pin|hour11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, pot0_Pin|pot1_Pin|pot2_Pin|pot3_Pin
                          |pot4_Pin|pot5_Pin|pot6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : hour0_Pin hour1_Pin hour2_Pin hour3_Pin
                           hour4_Pin hour5_Pin hour6_Pin hour7_Pin
                           hour8_Pin hour9_Pin hour10_Pin hour11_Pin */
  GPIO_InitStruct.Pin = hour0_Pin|hour1_Pin|hour2_Pin|hour3_Pin
                          |hour4_Pin|hour5_Pin|hour6_Pin|hour7_Pin
                          |hour8_Pin|hour9_Pin|hour10_Pin|hour11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : pot0_Pin pot1_Pin pot2_Pin pot3_Pin
                           pot4_Pin pot5_Pin pot6_Pin */
  GPIO_InitStruct.Pin = pot0_Pin|pot1_Pin|pot2_Pin|pot3_Pin
                          |pot4_Pin|pot5_Pin|pot6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
