#ifndef WIFI_CONNECT_H
#define WIFI_CONNECT_H

#include "sdkconfig.h"

/*-----------------------------------------------------------*/

#define NR_OF_IP_ADDRESSES_TO_WAIT_FOR     1

#if CONFIG_SAMPLE_IOT_WIFI_SCAN_METHOD_FAST
    #define SAMPLE_IOT_WIFI_SCAN_METHOD    WIFI_FAST_SCAN
#elif CONFIG_SAMPLE_IOT_WIFI_SCAN_METHOD_ALL_CHANNEL
    #define SAMPLE_IOT_WIFI_SCAN_METHOD    WIFI_ALL_CHANNEL_SCAN
#endif

#if CONFIG_SAMPLE_IOT_WIFI_CONNECT_AP_BY_SIGNAL
    #define SAMPLE_IOT_WIFI_CONNECT_AP_SORT_METHOD    WIFI_CONNECT_AP_BY_SIGNAL
#elif CONFIG_SAMPLE_IOT_WIFI_CONNECT_AP_BY_SECURITY
    #define SAMPLE_IOT_WIFI_CONNECT_AP_SORT_METHOD    WIFI_CONNECT_AP_BY_SECURITY
#endif

#if CONFIG_SAMPLE_IOT_WIFI_AUTH_OPEN
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_OPEN
#elif CONFIG_SAMPLE_IOT_WIFI_AUTH_WEP
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_WEP
#elif CONFIG_SAMPLE_IOT_WIFI_AUTH_WPA_PSK
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_WPA_PSK
#elif CONFIG_SAMPLE_IOT_WIFI_AUTH_WPA2_PSK
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_WPA2_PSK
#elif CONFIG_SAMPLE_IOT_WIFI_AUTH_WPA_WPA2_PSK
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_WPA_WPA2_PSK
#elif CONFIG_SAMPLE_IOT_WIFI_AUTH_WPA2_ENTERPRISE
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_WPA2_ENTERPRISE
#elif CONFIG_SAMPLE_IOT_WIFI_AUTH_WPA3_PSK
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_WPA3_PSK
#elif CONFIG_SAMPLE_IOT_WIFI_AUTH_WPA2_WPA3_PSK
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_WPA2_WPA3_PSK
#elif CONFIG_SAMPLE_IOT_WIFI_AUTH_WAPI_PSK
    #define SAMPLE_IOT_WIFI_SCAN_AUTH_MODE_THRESHOLD    WIFI_AUTH_WAPI_PSK
#endif /* if CONFIG_SAMPLE_IOT_WIFI_AUTH_OPEN */

// Function to initialize WiFi
void initialize_wifi(void);

#endif // WIFI_CONNECT_H