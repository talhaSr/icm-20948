/**
 * @file: Utils.c
 * @author: Talha SARI (talha.sari@outlook.com.tr)
 * @version: 1.0
 * @date: 2021-02-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "main.h"
#include "Utils.h"

HAL_StatusTypeDef WriteByte(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t data)
{
    uint8_t buffer[2];
    buffer[0] = register_addr;
    buffer[1] = data;

    if (HAL_I2C_Master_Transmit(hi2c, (uint16_t)device_addr, (uint8_t *)buffer, 2, 100) != HAL_OK)
    {
        if (HAL_I2C_GetError(hi2c) != HAL_I2C_ERROR_AF) {}
        return HAL_ERROR;
    }
    return HAL_OK;
}

HAL_StatusTypeDef ReadByte(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data)
{
    if (HAL_I2C_Master_Transmit(hi2c, (uint16_t)device_addr, &register_addr, 1, 100) != HAL_OK)
	{
		{
			if (HAL_I2C_GetError(hi2c) != HAL_I2C_ERROR_AF) {}
			return HAL_ERROR;
		}
	}
    if (HAL_I2C_Master_Receive(hi2c, (uint16_t)device_addr, data, 1, 100) != HAL_OK)
	{
		{
			if (HAL_I2C_GetError(hi2c) != HAL_I2C_ERROR_AF) {}
			return HAL_ERROR;
		}
	}
	return HAL_OK;
}

HAL_StatusTypeDef WriteMultiBytes(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data, uint16_t count)
{
    if (HAL_I2C_Mem_Write(hi2c, (uint16_t)device_addr, register_addr, register_addr > 0xFF ? I2C_MEMADD_SIZE_16BIT : I2C_MEMADD_SIZE_8BIT, data, count, 100) != HAL_OK)
	{
		{
			if (HAL_I2C_GetError(hi2c) != HAL_I2C_ERROR_AF) {}
			return HAL_ERROR;
		}
	}
	return HAL_OK;
}

HAL_StatusTypeDef ReadMultiBytes(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data, uint16_t count)
{
    if (HAL_I2C_Master_Transmit(hi2c, (uint16_t)device_addr, &register_addr, 1, 100) != HAL_OK)
	{
		if (HAL_I2C_GetError(hi2c) != HAL_I2C_ERROR_AF) {}
		return HAL_ERROR;
	}
    if (HAL_I2C_Master_Receive(hi2c, (uint16_t)device_addr, data, count, 100) != HAL_OK)
	{
		if (HAL_I2C_GetError(hi2c) != HAL_I2C_ERROR_AF) {}
		return HAL_ERROR;
	}
	return HAL_OK;
}