#ifndef BMP280_XTRAS_H
#define BMP280_XTRAS_H

#include <inttypes.h>
#include "esp_err.h"
#include "bmp2.h"

/*!
 * @details User defineable struct to hold
 * additional info. about the BMP280
 */
struct ident
{
  uint8_t dev_addr; /* BMP280's I2C address */
};

struct s_bmp280 {
  struct ident id;
  struct bmp2_dev dev;
  struct bmp2_config conf;
  uint32_t sampling_time;
};


/*
 * @details A wrapper around Bosch bmp2_init() used to
 * return an esp_err_t
 */
esp_err_t
bmp280_init(struct bmp2_dev *dev);

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

/*!
 * @brief A wrapper around Bosch bmp2_set_power_mode() used to
 * return an esp_err_t
 */
esp_err_t bmp280_set_power_mode(uint8_t mode, const struct bmp2_config *conf, struct bmp2_dev *dev);

esp_err_t bmp280_compute_meas_time(uint32_t *sampling_time,
                                   const struct bmp2_config *conf, const struct bmp2_dev *dev);
/*
// esp_err_t bmp280_get_tp(uint32_t period, struct bmp2_config *conf, struct bmp2_dev *dev, struct bmp2_data *bmp280_data); 
*/
esp_err_t bmp280_get_tp(struct s_bmp280 *bmp280, struct bmp2_data *bmp280_data);

#endif