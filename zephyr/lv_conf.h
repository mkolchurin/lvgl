/*
 * Copyright (c) 2018-2020 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 * Copyright (c) 2020 Teslabs Engineering S.L.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_
#define ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_

// #define LV_DEMO_BENCHMARK_MODE_RENDER_AND_DRIVER 1
// #define LV_DEMO_BENCHMARK_MODE_REAL 1
#define LV_DEMO_BENCHMARK_MODE_RENDER_ONLY 1
#define LV_CONF_SUPPRESS_DEFINE_CHECK 1
#define STM32F4

/* Memory manager settings */

#define LV_MEMCPY_MEMSET_STD 1

#if defined(CONFIG_LV_Z_MEM_POOL_HEAP_LIB_C)

#define LV_MEM_CUSTOM_INCLUDE	"stdlib.h"
#define LV_MEM_CUSTOM_ALLOC	malloc
#define LV_MEM_CUSTOM_REALLOC	realloc
#define LV_MEM_CUSTOM_FREE	free

#else

#define LV_MEM_CUSTOM_INCLUDE	"../zephyr/lvgl_mem.h"
#define LV_MEM_CUSTOM_ALLOC	lvgl_malloc
#define LV_MEM_CUSTOM_REALLOC	lvgl_realloc
#define LV_MEM_CUSTOM_FREE	lvgl_free

#endif

/* HAL settings */

#define LV_TICK_CUSTOM			1
#define LV_TICK_CUSTOM_INCLUDE		<zephyr/kernel.h>
#define LV_TICK_CUSTOM_SYS_TIME_EXPR	(k_uptime_get_32())

/* Misc settings */

#define LV_SPRINTF_CUSTOM 1
#define LV_SPRINTF_INCLUDE "stdio.h"
#define lv_snprintf snprintf
#define lv_vsnprintf vsnprintf

#endif /* ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_ */
