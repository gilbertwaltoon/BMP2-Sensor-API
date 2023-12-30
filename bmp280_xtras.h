
#include <inttypes.h>
#include "esp_err.h"

/*!
 * \code
 * esp_err_t bmp280_init(struct bmp2_dev *dev);
 * \endcode
 * @details A wrapper around Bosch bmp2_init() used to
 * return an esp_err_t
 * @param[in] dev         : Structure instance of bmp2_dev.
 *
 * @return Result of API execution status.
 *
 * @retval Success -> ESP_OK.
 * @retval Fail -> ESP_FAIL.
 *
 */

struct ident
{
  uint8_t dev_addr; /* BMP280's I2C address */
};

esp_err_t bmp280_init(struct bmp2_dev *dev);



