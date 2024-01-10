#include "time_sync.h"

#include <stdio.h>

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_expression_with_stack.h"

#include "esp_sntp.h"
#include "esp_log.h"
#include <time.h>

/*-----------------------------------------------------------*/

static const char * TAG = "time_sync";
static bool g_timeInitialized = false;

/*-----------------------------------------------------------*/

static void time_sync_notification_cb( struct timeval * tv )
{
    ESP_LOGI( TAG, "Notification of a time synchronization event" );
    g_timeInitialized = true;
}

/*-----------------------------------------------------------*/

void get_current_time(void) {
    time_t now;
    struct tm timeinfo;

    time(&now); // Get the current time as time_t
    localtime_r(&now, &timeinfo); // Convert the time to struct tm format

    // use strftime to format the date and time
    char strftime_buf[64];
    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    ESP_LOGI("SNTP", "The current date and time are: %s", strftime_buf);
}

/*-----------------------------------------------------------*/

static void initialize_time()
{
    esp_sntp_setoperatingmode( SNTP_OPMODE_POLL );
    esp_sntp_setservername( 0, SNTP_SERVER_FQDN );
    sntp_set_time_sync_notification_cb( time_sync_notification_cb );
    esp_sntp_init();

    ESP_LOGI( TAG, "Waiting for time synchronization with SNTP server" );

    while( !g_timeInitialized )
    {
        vTaskDelay( pdMS_TO_TICKS( 1000 ) );
    }
    get_current_time();
}
/*-----------------------------------------------------------*/

void initialize_sntp(void) {
    initialize_time();
}

