/**
 * @file: ICM20948.h
 * @author: Talha SARI (talha.sari@outlook.com.tr)
 * @brief: This library is created for STM32 development environment and can be used only with STM32F series microcontrollers.
 * @note: Requires I2C_HAL!
 * @version: 1.0
 * @date: 2021-02-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INC_ICM20948_H_
#define INC_ICM20948_H_

#ifdef __cplusplus
extern "C" {
#endif

/* TypeDef Declerations */
typedef enum {
    ICM20948_RESULT_OK = 0x00,
    ICM20948_RESULT_ERROR
} ICM20948_Result_t;

typedef enum {
    ACCEL_SCALE_2G = 0x00,
    ACCEL_SCALE_4G = 0x02,
    ACCEL_SCALE_8G = 0x04,
    ACCEL_SCALE_16G = 0x06
} ICM20948_Accel_Scale_t;

typedef enum {
    GYRO_SCALE_250 = 0x00,
    GYRO_SCALE_500 = 0x02,
    GYRO_SCALE_1000 = 0x04,
    GYRO_SCALE_2000 = 0x06
} ICM20948_Gyro_Scale_t;

typedef enum {
    ICM20948_Device_0 = 0x00,
    ICM20948_Device_1
} ICM20948_Device_t;

typedef struct {
    float acc[3];
    float gyro[3];
    float mag[3];
    float temp;
    int16_t acc_raw[3];
    int16_t gyro_raw[3];
    int16_t mag_raw[3];

    float accMult;
    float gyroMult;
    float magMult;
    float tempMult;

    uint8_t addr;
    uint8_t addr_mag;
} ICM20948_t;

/* Functions */
ICM20948_Result_t ICM20948_Init(ICM20948_t *imu, ICM20948_Device_t dev, ICM20948_Accel_Scale_t accScale, ICM20948_Gyro_Scale_t gyroScale);
ICM20948_Result_t ICM20948_ReadAccel(ICM20948_t *imu);
ICM20948_Result_t ICM20948_ReadGyro(ICM20948_t *imu);
ICM20948_Result_t ICM20948_ReadMag(ICM20948_t *imu);
ICM20948_Result_t ICM20948_ReadTemp(ICM20948_t *imu);
ICM20948_Result_t ICM20948_DataReady(ICM20948_t *imu);
ICM20948_Result_t ICM20948_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint8_t device_addr);

#ifdef __cplusplus
}
#endif

#endif /* INC_ICM20948_H_ */