/**
 * @file: ICM20948.c
 * @author: Talha SARI (talha.sari@outlook.com.tr)
 * @brief: This library is created for STM32 development environment and can be used only with STM32F series microcontrollers.
 * @note: Requires I2C_HAL!
 * @version: 1.0
 * @date: 2021-02-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ICM20948.h"
#include "RegisterMap.h"
#include "Utils.h"

/* External I2C Handler */
extern I2C_HandleTypeDef hi2c1;

/* Private Function Prototypes */
static inline float deg2rad(float x);
static inline float rad2deg(float x);

/* Functions */
ICM20948_Result_t ICM20948_Init(ICM20948_t *imu, ICM20948_Device_t dev, ICM20948_Accel_Scale_t accScale, ICM20948_Gyro_Scale_t gyroScale)
{
    uint8_t data;
    imu->addr = ICM20948_ADDR | (uint8_t)dev;
    imu->addr_mag = AK00916_ADDR;

    /* Device Connection Check */
    if (ICM20948_IsDeviceReady(&hi2c1, imu->addr) != ICM20948_RESULT_OK)
        return ICM20948_RESULT_ERROR;

    /* Who Am I Check */
    ReadByte(&hi2c1, imu->addr, WHO_AM_I, &data);
    if (data != 0xEA)
        return ICM20948_RESULT_ERROR;
}

ICM20948_Result_t ICM20948_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint8_t device_addr)
{
    if (HAL_I2C_IsDeviceReady(hi2c, (uint16_t)device_addr, 2, 5) != HAL_OK)
        return ICM20948_RESULT_ERROR;
    return ICM20948_RESULT_OK;
}

static inline float deg2rad(float x)
{
    return ((PI / 180.0f) * x);
}

static inline float rad2deg(float x)
{
    return ((180.0f / PI) * x);
}