#ifndef BMP280_XTRAS_H
#define BMP280_XTRAS_H

#include <inttypes.h>
#include "esp_err.h"

/*!
* @details User defineable struct to hold
* additional info. about the BMP280
*/
struct ident {
  uint8_t dev_addr; /* BMP280's I2C address */
};

 /*
 * @details A wrapper around Bosch bmp2_init() used to
 * return an esp_err_t
 */
esp_err_t bmp280_init(struct bmp2_dev *dev);

/*!
 * @brief A wrapper around Bosch bmp2_set_config() used to
 * return an esp_err_t
 */
esp_err_t bmp280_set_config(struct bmp2_config *conf, struct bmp2_dev *dev);

/*!
 * @brief A wrapper around Bosch bmp2_get_config() used to
 * return an esp_err_t
 */
esp_err_t bmp280_get_config(struct bmp2_config *conf, struct bmp2_dev *dev);

#endif