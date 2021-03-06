/*
 * Copyright (C) 2013 SolidRun ltd.
 * Based on sabresd board from Freescale Semiconductor, Inc. All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _BOARD_MX6Q_MICROSOM_H
#define _BOARD_MX6Q_MICROSOM_H
#include <mach/iomux-mx6q.h>
#define MX6Q_ENET_PAD_CTRL_PD (PAD_CTL_PKE | PAD_CTL_PUE  |		\
		PAD_CTL_PUS_100K_DOWN | PAD_CTL_SPEED_MED |		\
		PAD_CTL_DSE_40ohm   | PAD_CTL_HYS)

static iomux_v3_cfg_t mx6q_usom_pads[] = {
	/* WiFi 11n and BlueTooth */
	MX6Q_PAD_GPIO_8__ANATOP_ANATOP_32K_OUT,
	MX6Q_PAD_CSI0_DAT8__GPIO_5_26,		/* WL_RST_IN */
	MX6Q_PAD_CSI0_DAT9__GPIO_5_27,		/* WL_GPIO_0 */
	MX6Q_PAD_CSI0_DATA_EN__GPIO_5_20,	/* WL_GPIO_1 */
	MX6Q_PAD_EIM_D19__GPIO_3_19,		/* WL_BT_REG_ON */
	MX6Q_PAD_DISP0_DAT11__GPIO_5_5,         /* XTAL power up */
	MX6Q_PAD_CSI0_DAT14__GPIO_6_0,		/* BT_RST_N */
	MX6Q_PAD_CSI0_DAT15__GPIO_6_1,		/* BT_GPIO_0 */
	MX6Q_PAD_CSI0_DAT18__GPIO_6_4,		/* BT_GPIO_1 */
        MX6Q_PAD_CSI0_DAT19__GPIO_6_5,		/* WL_SHUTDOWN_N - BRCM 4330 only */

	/* AUD5 for BRCM WiFi/BT/FM */
	MX6Q_PAD_CSI0_DAT4__AUDMUX_AUD3_TXC,
	MX6Q_PAD_CSI0_DAT5__AUDMUX_AUD3_TXD,
	MX6Q_PAD_CSI0_DAT6__AUDMUX_AUD3_TXFS,
	MX6Q_PAD_CSI0_DAT7__AUDMUX_AUD3_RXD,

	/* USDHC1 - Connected to BRCM Wifi/BT/FM */
	MX6Q_PAD_SD1_CLK__USDHC1_CLK_50MHZ_40OHM,
	MX6Q_PAD_SD1_CMD__USDHC1_CMD_50MHZ_40OHM,
	MX6Q_PAD_SD1_DAT0__USDHC1_DAT0_50MHZ_40OHM,
	MX6Q_PAD_SD1_DAT1__USDHC1_DAT1_50MHZ_40OHM,
	MX6Q_PAD_SD1_DAT2__USDHC1_DAT2_50MHZ_40OHM,
	MX6Q_PAD_SD1_DAT3__USDHC1_DAT3_50MHZ_40OHM,

	/* UART4 for BRCM WiFi/BT/FM */
	MX6Q_PAD_CSI0_DAT12__UART4_TXD,
	MX6Q_PAD_CSI0_DAT13__UART4_RXD,
	MX6Q_PAD_CSI0_DAT17__UART4_CTS,
	MX6Q_PAD_CSI0_DAT16__UART4_RTS,

	/* I2C2 */
	MX6Q_PAD_KEY_COL3__I2C2_SCL,
	MX6Q_PAD_KEY_ROW3__I2C2_SDA,
	
	/* HDMI CEC */
	MX6Q_PAD_KEY_ROW2__HDMI_TX_CEC_LINE,
};

static iomux_v3_cfg_t mx6q_usom_ar8030_phy[] = {
	/* ENET */
	MX6Q_PAD_ENET_MDIO__ENET_MDIO,
	MX6Q_PAD_ENET_MDC__ENET_MDC,
	IOMUX_PAD(0x0650, 0x0268, 5, 0x0000, 0, MX6Q_ENET_PAD_CTRL_PD), /* KEY_ROW4 reset signal */
	
	MX6Q_PAD_DI0_PIN2__GPIO_4_18, /* Interrupt */
	/* RMII */
	IOMUX_PAD(0x04F0, 0x01DC, 1, 0x0858, 1, PAD_CTL_PKE | PAD_CTL_PUE  |
		  PAD_CTL_PUS_100K_DOWN), /* MX6Q_PAD_ENET_CRS_DV__ENET_RX_EN */
	IOMUX_PAD(0x04F8, 0x01E4, 1, 0x0848, 1, PAD_CTL_PKE | PAD_CTL_PUE  |
		  PAD_CTL_PUS_100K_DOWN), /* MX6Q_PAD_ENET_RXD0__ENET_RDATA_0 */
	IOMUX_PAD(0x04F4, 0x01E0, 1, 0x084C, 1, PAD_CTL_PKE | PAD_CTL_PUE  |
		  PAD_CTL_PUS_100K_DOWN), /* MX6Q_PAD_ENET_RXD1__ENET_RDATA_1 */
	MX6Q_PAD_ENET_TXD0__ENET_TDATA_0,
	MX6Q_PAD_ENET_TXD1__ENET_TDATA_1,
	MX6Q_PAD_ENET_TX_EN__ENET_TX_EN,
	MX6Q_PAD_GPIO_16__ENET_ANATOP_ETHERNET_REF_OUT,

//	MX6Q_PAD_RGMII_TXC__ENET_RGMII_TXC, This is dangerous once since it's input in AR8030 and output in AR8035
	MX6Q_PAD_RGMII_TXC__GPIO_6_19,
	MX6Q_PAD_RGMII_TD0__ENET_RGMII_TD0,
	MX6Q_PAD_RGMII_TD1__ENET_RGMII_TD1,
	MX6Q_PAD_RGMII_TD2__ENET_RGMII_TD2,
	MX6Q_PAD_RGMII_TD3__ENET_RGMII_TD3,
	MX6Q_PAD_RGMII_TX_CTL__ENET_RGMII_TX_CTL,
	MX6Q_PAD_ENET_REF_CLK__ENET_TX_CLK,
	MX6Q_PAD_RGMII_RXC__ENET_RGMII_RXC,
	IOMUX_PAD(0x0694, 0x02AC, 1, 0x0818, 1, MX6Q_ENET_PAD_CTRL_PD),/*RGMII RD0*/
	IOMUX_PAD(0x0698, 0x02B0, 1, 0x081C, 1, MX6Q_ENET_PAD_CTRL_PD),/*RGMII RD1*/
	/* In RGMII mode RD2 should be '1' to disable the stupid PLL OFF mode */
	IOMUX_PAD(0x069C, 0x02B4, 1, 0x0820, 1, MX6Q_ENET_PAD_CTRL_PD),/*RGMII RD2*/
	IOMUX_PAD(0x06A0, 0x02B8, 1, 0x0824, 1, MX6Q_ENET_PAD_CTRL_PD),/*RGMII RD3*/
	/* In RGMII mode RX_DV should be pulled down for reset strap */
	IOMUX_PAD(0x06A4, 0x02BC, 1, 0x0828, 1, MX6Q_ENET_PAD_CTRL_PD),/*RGMII RXCTL*/
};

static iomux_v3_cfg_t mx6q_usom_ar8035_phy[] = {
	/* ENET */
	MX6Q_PAD_ENET_MDIO__ENET_MDIO,
	MX6Q_PAD_ENET_MDC__ENET_MDC,
	IOMUX_PAD(0x05EC, 0x021C, 5, 0x0000, 0, MX6Q_ENET_PAD_CTRL_PD), /* KEY_ROW4 reset signal */
	MX6Q_PAD_DI0_PIN2__GPIO_4_18, /* Interrupt */
	/* RMII */

	IOMUX_PAD(0x04F0, 0x01DC, 1, 0x0858, 1, PAD_CTL_PKE | PAD_CTL_PUE  |
		  PAD_CTL_PUS_100K_DOWN), /* MX6Q_PAD_ENET_CRS_DV__ENET_RX_EN */
	IOMUX_PAD(0x04F8, 0x01E4, 1, 0x0848, 1, PAD_CTL_PKE | PAD_CTL_PUE  |
		  PAD_CTL_PUS_100K_DOWN), /* MX6Q_PAD_ENET_RXD0__ENET_RDATA_0 */
	IOMUX_PAD(0x04F4, 0x01E0, 1, 0x084C, 1, PAD_CTL_PKE | PAD_CTL_PUE  |
		  PAD_CTL_PUS_100K_DOWN), /* MX6Q_PAD_ENET_RXD1__ENET_RDATA_1 */
	MX6Q_PAD_ENET_TXD0__ENET_TDATA_0,
	MX6Q_PAD_ENET_TXD1__ENET_TDATA_1,
	MX6Q_PAD_ENET_TX_EN__ENET_TX_EN,
	MX6Q_PAD_GPIO_16__ENET_ANATOP_ETHERNET_REF_OUT,
	MX6Q_PAD_RGMII_TXC__ENET_RGMII_TXC,
	MX6Q_PAD_RGMII_TD0__ENET_RGMII_TD0,
	MX6Q_PAD_RGMII_TD1__ENET_RGMII_TD1,
	MX6Q_PAD_RGMII_TD2__ENET_RGMII_TD2,
	MX6Q_PAD_RGMII_TD3__ENET_RGMII_TD3,
	MX6Q_PAD_RGMII_TX_CTL__ENET_RGMII_TX_CTL,
	MX6Q_PAD_ENET_REF_CLK__ENET_TX_CLK,
	MX6Q_PAD_RGMII_RXC__ENET_RGMII_RXC,
	IOMUX_PAD(0x0384, 0x0070, 1, 0x0848, 0, MX6Q_ENET_PAD_CTRL_PD),/*RGMII RD0*/
	IOMUX_PAD(0x038C, 0x0078, 1, 0x084C, 0, MX6Q_ENET_PAD_CTRL_PD),/*RGMII RD1*/
	/* In RGMII mode RD2 should be '1' to disable the PLL OFF mode */
	MX6Q_PAD_RGMII_RD2__ENET_RGMII_RD2,
	MX6Q_PAD_RGMII_RD3__ENET_RGMII_RD3,
	/* In RGMII mode RX_DV should be pulled down for reset strap */
	IOMUX_PAD(0x0380, 0x006C, 1, 0x0858, 0, MX6Q_ENET_PAD_CTRL_PD),/*RGMII RXCTL*/
};

static iomux_v3_cfg_t mx6q_usom_hdmi_ddc_pads[] = {
	MX6Q_PAD_KEY_COL3__HDMI_TX_DDC_SCL, /* HDMI DDC SCL */
	MX6Q_PAD_KEY_ROW3__HDMI_TX_DDC_SDA, /* HDMI DDC SDA */
};

static iomux_v3_cfg_t mx6q_usom_i2c2_pads[] = {
	MX6Q_PAD_KEY_COL3__I2C2_SCL,	/* I2C2 SCL */
	MX6Q_PAD_KEY_ROW3__I2C2_SDA,	/* I2C2 SDA */
};
#endif
