/**
 ******************************************************************************
 * @file    board_setup.c
 * @author  Philippose Rajan
 * @date    06.01.2014
 * @brief   <Put in a brief description here>
 *
 * @see     The GNU Public License (GPL) Version 3
 *
 ******************************************************************************
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ---- Includes --------------------------------------------------------- */
#include "globals.h"
#include "sys_led_intern.h"

/* ---- Externally visible Variables ------------------------------------- */

/* ---- Externally visible Functions ------------------------------------- */

/* ---- Local Variables -------------------------------------------------- */

/* ---- Local Functions -------------------------------------------------- */

/* ----------------------------------------------------------------------- */

const struct Sys_LED brdLEDs[] = {
        [BRD_LED_BLUE_NW] = {
                .pin = {
                        .basePort = GPIOE,
                        .initData = {
                                    .GPIO_Pin = GPIO_Pin_8,
                                    .GPIO_Mode = GPIO_Mode_OUT,
                                    .GPIO_OType = GPIO_OType_PP,
                                    .GPIO_PuPd = GPIO_PuPd_NOPULL,
                                    .GPIO_Speed = GPIO_Speed_50MHz
                        },
                },
                .activeHigh = TRUE
        },
        [BRD_LED_RED_N] = {
                .pin = {
                        .basePort = GPIOE,
                        .initData = {
                                    .GPIO_Pin = GPIO_Pin_9,
                                    .GPIO_Mode = GPIO_Mode_OUT,
                                    .GPIO_OType = GPIO_OType_PP,
                                    .GPIO_PuPd = GPIO_PuPd_NOPULL,
                                    .GPIO_Speed = GPIO_Speed_50MHz
                        },
                },
                .activeHigh = TRUE
        },
        [BRD_LED_ORANGE_NE] = {
                .pin = {
                        .basePort = GPIOE,
                        .initData = {
                                    .GPIO_Pin = GPIO_Pin_10,
                                    .GPIO_Mode = GPIO_Mode_OUT,
                                    .GPIO_OType = GPIO_OType_PP,
                                    .GPIO_PuPd = GPIO_PuPd_NOPULL,
                                    .GPIO_Speed = GPIO_Speed_50MHz
                        },
                },
                .activeHigh = TRUE
        },
        [BRD_LED_GREEN_E] = {
                .pin = {
                        .basePort = GPIOE,
                        .initData = {
                                    .GPIO_Pin = GPIO_Pin_11,
                                    .GPIO_Mode = GPIO_Mode_OUT,
                                    .GPIO_OType = GPIO_OType_PP,
                                    .GPIO_PuPd = GPIO_PuPd_NOPULL,
                                    .GPIO_Speed = GPIO_Speed_50MHz
                        },
                },
                .activeHigh = TRUE
        },
        [BRD_LED_BLUE_SE] = {
                .pin = {
                        .basePort = GPIOE,
                        .initData = {
                                    .GPIO_Pin = GPIO_Pin_12,
                                    .GPIO_Mode = GPIO_Mode_OUT,
                                    .GPIO_OType = GPIO_OType_PP,
                                    .GPIO_PuPd = GPIO_PuPd_NOPULL,
                                    .GPIO_Speed = GPIO_Speed_50MHz
                        },
                },
                .activeHigh = TRUE
        },
        [BRD_LED_RED_S] = {
                .pin = {
                        .basePort = GPIOE,
                        .initData = {
                                    .GPIO_Pin = GPIO_Pin_13,
                                    .GPIO_Mode = GPIO_Mode_OUT,
                                    .GPIO_OType = GPIO_OType_PP,
                                    .GPIO_PuPd = GPIO_PuPd_NOPULL,
                                    .GPIO_Speed = GPIO_Speed_50MHz
                        },
                },
                .activeHigh = TRUE
        },
        [BRD_LED_ORANGE_SW] = {
                .pin = {
                        .basePort = GPIOE,
                        .initData = {
                                    .GPIO_Pin = GPIO_Pin_14,
                                    .GPIO_Mode = GPIO_Mode_OUT,
                                    .GPIO_OType = GPIO_OType_PP,
                                    .GPIO_PuPd = GPIO_PuPd_NOPULL,
                                    .GPIO_Speed = GPIO_Speed_50MHz
                        },
                },
                .activeHigh = TRUE
        },
        [BRD_LED_GREEN_W] = {
                .pin = {
                        .basePort = GPIOE,
                        .initData = {
                                    .GPIO_Pin = GPIO_Pin_15,
                                    .GPIO_Mode = GPIO_Mode_OUT,
                                    .GPIO_OType = GPIO_OType_PP,
                                    .GPIO_PuPd = GPIO_PuPd_NOPULL,
                                    .GPIO_Speed = GPIO_Speed_50MHz
                        },
                },
                .activeHigh = TRUE
        },
};

static const struct Sys_LED_Cfg brdLEDCfg = {
        .LEDs = brdLEDs,
        .numLEDs = NELEMENTS(brdLEDs),
};


