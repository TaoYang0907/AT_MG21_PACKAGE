/*
 * File      : at_sample_esp8266.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-05-10     chenyong     first version
 */

#include <at_device_mg21.h>

#define LOG_TAG                        "at.sample.mg"
#include <at_log.h>

#define AT_MG21_SAMPLE_DEIVCE_NAME        "mg0"

static struct at_device_mg21 mg0 =
{
    AT_MG21_SAMPLE_DEIVCE_NAME,
    AT_MG21_SAMPLE_CLIENT_NAME,
    AT_MG21_SAMPLE_RECV_BUFF_LEN,
};

static int mg21_device_register(void)
{
    struct at_device_mg21 *mg21 = &mg0;

    LOG_I("mg21 register");
    return at_device_register(&(mg21->device),
                              mg21->device_name,
                              mg21->client_name,
                              AT_DEVICE_CLASS_MG21,
                              (void *) mg21);
}
INIT_APP_EXPORT(mg21_device_register);
