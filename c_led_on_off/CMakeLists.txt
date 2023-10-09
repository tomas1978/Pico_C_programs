cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(led_on_off)

pico_sdk_init()

add_executable(led_on_off
    led_on_off.c
)

pico_enable_stdio_uart(led_on_off 0)
pico_enable_stdio_usb(led_on_off 1)

pico_add_extra_outputs(led_on_off)

target_link_libraries(led_on_off pico_stdlib)

