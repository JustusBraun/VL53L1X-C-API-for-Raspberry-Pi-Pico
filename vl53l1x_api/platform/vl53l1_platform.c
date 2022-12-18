
/* 
* This file is part of VL53L1 Platform 
* 
* Copyright (c) 2016, STMicroelectronics - All Rights Reserved 
* 
* License terms: BSD 3-clause "New" or "Revised" License. 
* 
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met: 
* 
* 1. Redistributions of source code must retain the above copyright notice, this 
* list of conditions and the following disclaimer. 
* 
* 2. Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution. 
* 
* 3. Neither the name of the copyright holder nor the names of its contributors 
* may be used to endorse or promote products derived from this software 
* without specific prior written permission. 
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
* 
*/

/*
* Implementation of API methods is licensed as follows.
* Copyright 2022 Alex Mous
* 
* License: 3-Clause BSD License
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice,
*  this list of conditions and the following disclaimer.
* 
* 2. Redistributions in binary form must reproduce the above copyright notice,
*  this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution.
*
* 3. Neither the name of the copyright holder nor the names of its contributors
*  may be used to endorse or promote products derived from this software without
*  specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
*/

#include "vl53l1_platform.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

// Ensure i2c is available
#if !defined(i2c_default) || !defined(PICO_DEFAULT_I2C_SDA_PIN) || !defined(PICO_DEFAULT_I2C_SCL_PIN)
    #warning Board with I2C pins is required

int8_t VL53L1_WriteMulti(uint16_t dev, uint16_t index, uint8_t *pdata, uint32_t count) {
	i2c_write_blocking(i2c_default, (uint8_t)dev, &index, 2, false);
	i2c_write_blocking(i2c_default, (uint8_t)dev, pdata, count, false);
}

int8_t VL53L1_ReadMulti(uint16_t dev, uint16_t index, uint8_t *pdata, uint32_t count) {
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&index, 2, false);
	i2c_read_blocking(i2c_default, (uint8_t)dev, pdata, count, false);
}

int8_t VL53L1_WrByte(uint16_t dev, uint16_t index, uint8_t data) {
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&index, true);
	i2c_write_blocking(i2c_default, (uint8_t)dev, &data, false);
}

int8_t VL53L1_WrWord(uint16_t dev, uint16_t index, uint16_t data) {
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&index, 2, false);
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&data, 2, false);
}

int8_t VL53L1_WrDWord(uint16_t dev, uint16_t index, uint32_t data) {
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&index, 2, false);
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&data, 4, false);
}

int8_t VL53L1_RdByte(uint16_t dev, uint16_t index, uint8_t *data) {
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&index, 2, false);
	i2c_read_blocking(i2c_default, (uint8_t)dev, data, 1, false);
}

int8_t VL53L1_RdWord(uint16_t dev, uint16_t index, uint16_t *data) {
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&index, 2, false);
	i2c_read_blocking(i2c_default, (uint8_t)dev, data, 2, false);
}

int8_t VL53L1_RdDWord(uint16_t dev, uint16_t index, uint32_t *data) {
	i2c_write_blocking(i2c_default, (uint8_t)dev, (uint8_t*)&index, 2, false);
	i2c_read_blocking(i2c_default, (uint8_t)dev, data, 4, false);
}

int8_t VL53L1_WaitMs(uint16_t dev, int32_t wait_ms) {
	sleep_ms(wait_ms);
}