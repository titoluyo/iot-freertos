message("++ cmake: iot_freertos/main")

set(COMPONENT_INCLUDE_DIRS
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/../config
)

set(COMPONENT_SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/iot_freertos.c
    ${CMAKE_CURRENT_LIST_DIR}/wifi_connect.c
    ${CMAKE_CURRENT_LIST_DIR}/time_sync.c
    ${CMAKE_CURRENT_LIST_DIR}/led_control.c
)

idf_component_register(SRCS ${COMPONENT_SOURCES}
                    INCLUDE_DIRS ${COMPONENT_INCLUDE_DIRS}
                    REQUIRES driver freertos nvs_flash spi_flash coreMQTT coreHTTP azure-iot-middleware-freertos azure-sdk-for-c
                    )
