#include <stdio.h>
#include <inttypes.h>
#include "bmp2.h"
#include "bmp280_xtras.h"
//#include <string.h>
//#include "esp_log.h"
#include "esp_err.h"
#include "esp_check.h"

static const char *TAG = "bmp280_xtras.c";

/*!
 * @brief A wrapper around Bosch bmp2_init() used to
 * return an esp_err_t
 */
esp_err_t bmp280_init(struct bmp2_dev *dev){
    int8_t rslt;
    rslt = bmp2_init(dev);

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




