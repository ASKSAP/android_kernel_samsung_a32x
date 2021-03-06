/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#ifndef _CAM_CAL_DATA_H
#define _CAM_CAL_DATA_H

#ifdef CONFIG_COMPAT
/* 64 bit */
#include <linux/fs.h>
#include <linux/compat.h>
#endif

enum CAM_CAL_COMMAND {
	CAM_CAL_COMMAND_NONE,
	CAM_CAL_COMMAND_EEPROM_LIMIT_SIZE,
	CAM_CAL_COMMAND_CAL_SIZE,
	CAM_CAL_COMMAND_CONVERTED_CAL_SIZE,
	CAM_CAL_COMMAND_AWB_ADDR,
	CAM_CAL_COMMAND_CONVERTED_AWB_ADDR,
	CAM_CAL_COMMAND_LSC_ADDR,
	CAM_CAL_COMMAND_CONVERTED_LSC_ADDR,
	CAM_CAL_COMMAND_MEMTYPE,
	CAM_CAL_COMMAND_BAYERFORMAT,
	CAM_CAL_COMMAND_MODULE_INFO_ADDR,
};

struct CAM_CAL_SENSOR_INFO {
	u32 sensor_id;
	u32 device_id;
	enum CAM_CAL_COMMAND command;
	u32 *info;
};

struct stCAM_CAL_INFO_STRUCT {
	u32 u4Offset;
	u32 u4Length;
	u32 sensorID;
	/*
	 * MAIN = 0x01,
	 * SUB  = 0x02,
	 * MAIN_2 = 0x04,
	 * SUB_2 = 0x08,
	 * MAIN_3 = 0x10,
	 */
	u32 deviceID;
	u8 *pu1Params;
	enum CAM_CAL_COMMAND command;
};

#ifdef CONFIG_COMPAT

struct COMPAT_stCAM_CAL_INFO_STRUCT {
	u32 u4Offset;
	u32 u4Length;
	u32 sensorID;
	u32 deviceID;
	compat_uptr_t pu1Params;
};
#endif

#endif/*_CAM_CAL_DATA_H*/
