/**
 * @file: Utils.h
 * @author: Talha SARI (talha.sari@outlook.com.tr)
 * @version: 1.0
 * @date: 2021-02-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Defines */
#define PI  3.14159265359f

/* I2C R/W Functions */
HAL_StatusTypeDef WriteByte(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t data);
HAL_StatusTypeDef ReadByte(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data);
HAL_StatusTypeDef WriteMultiBytes(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data, uint16_t count);
HAL_StatusTypeDef ReadMultiBytes(I2C_HandleTypeDef *hi2c, uint8_t device_addr, uint8_t register_addr, uint8_t *data, uint16_t count);

#ifdef __cplusplus
}
#endif

#endif /* INC_UTILS_H_ */