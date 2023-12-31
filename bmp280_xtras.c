#include <stdio.h>
#include <inttypes.h>
#include "bmp2.h"
#include "bmp280_xtras.h"
// #include <string.h>
// #include "esp_log.h"
#include "esp_err.h"
#include "esp_check.h"


static const char *TAG = "bmp280_xtras.c";

esp_err_t bmp280_err(int8_t rslt)
{
    switch (rslt)
    {
    case BMP2_E_NULL_PTR:
        ESP_RETURN_ON_ERROR(ESP_FAIL, TAG, "BMP2_E_NULL_PTR");
        break;
    case BMP2_E_COM_FAIL:
        ESP_RETURN_ON_ERROR(ESP_FAIL, TAG, "BMP2_E_COM_FAIL");
        break;
    case BMP2_E_INVALID_LEN:
        ESP_RETURN_ON_ERROR(ESP_FAIL, TAG, "BMP2_E_INVALID_LEN");
        break;
    case BMP2_E_DEV_NOT_FOUND:
        ESP_RETURN_ON_ERROR(ESP_FAIL, TAG, "BMP2_E_DEV_NOT_FOUND");
        break;
    case BMP2_E_UNCOMP_TEMP_RANGE:
        ESP_RETURN_ON_ERROR(ESP_FAIL, TAG, "BMP2_E_UNCOMP_TEMP_RANGE");
        break;
    case BMP2_E_UNCOMP_PRESS_RANGE:
        ESP_RETURN_ON_ERROR(ESP_FAIL, TAG, "BMP2_E_UNCOMP_PRESS_RANGE");
        break;
    case BMP2_E_UNCOMP_TEMP_AND_PRESS_RANGE:
        ESP_RETURN_ON_ERROR(ESP_FAIL, TAG, "BMP2_E_UNCOMP_TEMP_AND_PRESS_RANGE");
        break;
    default:
        break;
    }

    return ESP_OK;
}

/*!
 * @brief A wrapper around Bosch bmp2_init() used to
 * return an esp_err_t
 */
esp_err_t bmp280_init(struct bmp2_dev *dev)
{
    return bmp280_err(bmp2_init(dev));
}

/*!
 * @brief A wrapper around Bosch bmp2_get_config() used to
 * return an esp_err_t
 */
esp_err_t bmp280_get_config(struct bmp2_config *conf, struct bmp2_dev *dev)
{
    return bmp280_err(bmp2_get_config(conf, dev));
}

/*!
 * @brief A wrapper around Bosch bmp2_set_config() used to
 * return an esp_err_t
 */
esp_err_t bmp280_set_config(struct bmp2_config *conf, struct bmp2_dev *dev)
{
    return bmp280_err(bmp2_set_config(conf, dev));
}

/*!
 * @brief A wrapper around Bosch bmp2_set_power_mode() used to
 * return an esp_err_t
 */
esp_err_t bmp280_set_power_mode(uint8_t mode, const struct bmp2_config *conf, struct bmp2_dev *dev)
{
    return bmp280_err(bmp2_set_power_mode(mode, conf, dev));
}

esp_err_t bmp280_compute_meas_time(uint32_t *sampling_time,
                                   const struct bmp2_config *conf, const struct bmp2_dev *dev)
{

    return bmp280_err(bmp2_compute_meas_time(sampling_time, conf, dev));
}

static esp_err_t _bmp280_get_sensor_data(struct bmp2_data *comp_data, struct bmp2_dev *dev)
{
    return bmp280_err(bmp2_get_sensor_data(comp_data, dev));
}

// esp_err_t bmp280_get_tp(uint32_t period, struct bmp2_config *conf,
//                         struct bmp2_dev *dev, struct bmp2_data *bmp280_data)
// {
//     int8_t r;
//     esp_err_t e;
//     struct bmp2_status status;

//     // ESP_LOGI(TAG, "Measurement delay : %lu us\n", (long unsigned int)period);
//     do
//     {
//         r = bmp2_get_status(&status, dev);
//         //bmp2_log_error_code(r);
//     } while (r != BMP2_MEAS_DONE);

//     /* Delay between measurements */
//     dev->delay_us(period, dev->intf_ptr);
//     e = _bmp280_get_sensor_data(bmp280_data, dev);

// #ifdef BMP2_64BIT_COMPENSATION
//     bmp280_data->pressure = (bmp280_data->pressure) / 256;
// #endif

//     return e;
// }

esp_err_t bmp280_get_tp(struct s_bmp280 *bmp280, struct bmp2_data *bmp280_data){
    int8_t r;
    esp_err_t e;
    struct bmp2_status status;

    // ESP_LOGI(TAG, "Measurement delay : %lu us\n", (long unsigned int)period);
    do
    {
        r = bmp2_get_status(&status, &bmp280->dev);
        //bmp2_log_error_code(r);
    } while (r != BMP2_MEAS_DONE);

    /* Delay between measurements */
    (&bmp280->dev)->delay_us(bmp280->sampling_time, (&bmp280->dev)->intf_ptr);
    e = _bmp280_get_sensor_data(bmp280_data, &bmp280->dev);

#ifdef BMP2_64BIT_COMPENSATION
    bmp280_data->pressure = (bmp280_data->pressure) / 256;
#endif

    return e;
}

