# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(BOARD stm32f746g_disco)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(Zephyr_STM32F7)


# set(LVGL_DIR ${ZEPHYR_LVGL_MODULE_DIR})

add_subdirectory(drivers)

include_directories(gui)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})

target_sources(app PRIVATE gui/ui_helpers.c)
target_sources(app PRIVATE gui/ui.c)
target_sources(app PRIVATE gui/ui_events.c)
target_sources(app PRIVATE gui/components/ui_comp_hook.c)
target_sources(app PRIVATE gui/screens/ui_Screen1.c)

add_compile_definitions(LV_LVGL_H_INCLUDE_SIMPLE)