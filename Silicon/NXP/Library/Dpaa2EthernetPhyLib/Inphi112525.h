/*
 * Copyright 2018 INPHI
 * Copyright 2019 NXP
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Inphi is a registered trademark of Inphi Corporation
 *
 */

#ifndef IN112525_H_
#define IN112525_H_

#define PHYCTRL_REG0     0x0000
#define PHYCTRL_REG1     0x0012
#define PHYCTRL_REG2     0x0014
#define PHYCTRL_REG4     0x0121
#define PHYCTRL_REG5     0x0180
#define PHYCTRL_REG6     0x0580
#define PHYCTRL_REG7     0x05C4
#define PHYCTRL_REG8     0x01C8
#define PHYCTRL_REG10    0x0520
#define PHYCTRL_REG11    0x0521
#define PHYCTRL_REG12    0x0522
#define PHYCTRL_REG13    0x05c8
#define PHYCTRL_REG14    0x059b
#define PHYCTRL_REG15    0x0520
#define PHYCTRL_REG16    0x0521
#define PHYCTRL_REG17    0x0522
#define PHYCTRL_REG18    0x0525
#define PHYCTRL_REG19    0x0524
#define PHYCTRL_REG20    0x05ad

#define PHYSTAT_REG1     0x0021
#define PHYSTAT_REG2     0x0022
#define PHYSTAT_REG3     0x0123
                                     
#define PHYMISC_REG1     0x0025
#define PHYMISC_REG2     0x002c
#define PHYMISC_REG3     0x00b3
#define PHYMISC_REG4     0x0181
#define PHYMISC_REG5     0x019d
#define PHYMISC_REG6     0x0198
#define PHYMISC_REG7     0x0199
#define PHYMISC_REG8     0x0581
#define PHYMISC_REG9     0x0598
#define PHYMISC_REG11    0x00f0
#define PHYMISC_REG12    0x00f4
#define PHYMISC_REG20    0x01B0
#define PHYMISC_REG21    0x01BC
#define PHYMISC_REG22    0x01C0
#define PHYMISC_REG30    0x0584
#define PHYMISC_REG31    0x0585
#define PHYMISC_REG32    0x0184

#define IN112525_HRESET              0x20
#define IN112525_SRESET              0x200
#define IN112525_MDIOINIT            0x1000
#define IN112525_MANUALRESET_SELECT  0x8000

#define IN112525_CALIBRATION_DONE    0x10
#define IN112525_PLL_POWERDOWN       0x8
#define IN112525_CORE_DATAPATH_RESET 0x0400
#define IN112525_TX_SERDES_RESET     0x0800
#define IN112525_TX_PLL_RESET        0x1000
#define IN112525_RX_PLL_RESET        0x8000


#define IN112525_TX_RF_EN            0x0000
#define IN112525_CTLE_10G            0x0

#define IN112525_FORCE_PC            0x1000
#define IN112525_LOL_CTRL            0x2000
#define IN112525_USEQ_EN             0x8000
#define IN112525_USEQ_FL             0x4
#define IN112525_USEQ_LOS            0x2
#define IN112525_USEQ_LOL            0x1


#define PHYCTRL_REG15_VAL   0xA02D

#define IN112525_TXPLL_MSDIV         0x00
#define IN112525_TXPLL_IQDIV         0x000


#define PHYCTRL_REG17_VAL   0x0005
#define IN112525_FA_WIN_SIZE         0x2

#define IN112525_RX_MISC_TRIM1_VAL   0xB
#define IN112525_RX_HALFRATE_EN      0x20
#define IN112525_RX_LOS_EN             0x8000
#define IN112525_RX_LOS_10G_THRESHOLD  0x1
#define IN112525_RX_LOS_100G_THRESHOLD 0x2

#define PHYCTRL_REG13_VAL  0x0
#define IN112525_LOSD_HYSTERESIS_EN 0x01

#define IN112525_EFUSE_REG                0x600
#define IN112525_EFUSE_DONE               0x2000
#define IN112525_AUTOZERO_COMPLETION_DONE 0x4
#define IN112525_RX_PLL_LOCK_ACQUIRED     0x20
#define IN112525_TX_PLL_LOCK_ACQUIRED     0x40


#define IN112525_PRESCALE_20M       0xB5

#define IN112525_RX_VCO_CODE_OFFSET        5
#define IN112525_RX_PHASE_ADJUST_TRACK_VAL 36


/* Micro-Sequencer Data Memory 0x700 - 0x73F */
#define IN112525_US_DATA_MEM_ADDR   0x73E
#define IN112525_PHASE_ADJUST_VAL   0x3

#define L0_VCO_CODE_trim            390
#define L1_VCO_CODE_trim            390
#define L2_VCO_CODE_trim            390
#define L3_VCO_CODE_trim            390

#define NUMBER_OF_LANES	        4

typedef struct {
  UINT16 Addr;
  UINT16 Value;
} IN112525_REG_CONFIG;


/* define mapping for CTLE codes to rx_ctl registers 0x1c8,...,0x4c8 */
typedef enum {
  MODE_25_10_10 = 0x0,
  MODE_25_10_25 = 0x1,
  MODE_25_25_10 = 0x2,
  MODE_25_25_25 = 0x3,
  MODE_10_10_10 = 0x80,
  MODE_10_10_25 = 0x81,
  MODE_10_25_10 = 0x82,
  MODE_10_25_25 = 0x83
} IN112525_EQ_MODE;

typedef enum {
  INIT_OC192,
  INIT_10GE,
  INIT_16GFC,
  INIT_20GE,
  INIT_100GE,
  INIT_25GE,
  INIT_OTU4,
  INIT_32GFC,
  INIT_F28P2G
} IN112525_S03_MODE;

typedef enum {
  RECOV_CLK, /* Normal Mission Mode */
  EXTERNAL,  /* BERT Mode */
  RXMUX_CLK,
  LPBK,
  SEC_REFCLK = 5
} IN112525_REF_CLOCK;

typedef struct {
  INT32 L0VcoCode;
  INT32 L1VcoCode;
  INT32 L2VcoCode;
  INT32 L3VcoCode;
} IN112525_S03_VCO_CODES;

typedef struct {
  /* OTU protocol check */
  UINT8 EnableOtuProtocol:1;
  /* external refclk buffer */
  UINT8 EnableExternalRefclk:1;
  /* clk prescaler */
  UINT8 EnablePrescaler:1;
  /* set half-rate mode */
  UINT8 EnableHalfRate:1;
  /* FA sweep range for lower rates */
  UINT8 EnableExtendedRange:1;
  /* PLL multiplier ratio settings */
  UINT16 TxPllMpyRatio;
  /* src for TX PLL (external or recovered clk */
  IN112525_REF_CLOCK TxPllRefclkSource;
  /* equalizer preset mode (25:25:25, 25:25:10, 10:10:10 */
  IN112525_EQ_MODE CtleMode;
  /* common mode settings */
  UINT8 RxCommonMode;
  /* rx termination adjustments for non-matched tx */
  UINT8 RxOdtOverride;
  /* default phase adjustments per lanes */
  UINT8 L0PhaseAdjustVal;
  UINT8 L1PhaseAdjustVal;
  UINT8 L2PhaseAdjustVal;
  UINT8 L3PhaseAdjustVal;
} IN112525_CONFIG;

#endif //IN112525_
