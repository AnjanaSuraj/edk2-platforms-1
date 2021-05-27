/** @file
 *  Platform headers
 *
 *  Copyright 2021 NXP
 *  Copyright 2021 Puresoftware Ltd
 *
 *  SPDX-License-Identifier: BSD-2-Clause-Patent
 *
**/


#ifndef LS1046AFRWY_PLATFORM_H
#define LS1046AFRWY_PLATFORM_H

#define EFI_ACPI_ARM_OEM_REVISION    0x00000000

// Soc defines
#define PLAT_SOC_NAME                "LS1046AFRWY"
#define SVR_SOC_VER(svr)             (((svr) >> 8) & 0xFFFFFE)
#define SVR_MAJOR(svr)               (((svr) >> 4) & 0xf)
#define SVR_MINOR(svr)               (((svr) >> 0) & 0xf)

// Gic
#define GIC_VERSION                  2
#define GICD_BASE                    0x1410000
#define GICC_BASE                    0x142f000
#define GICH_BASE                    0x1440000
#define GICV_BASE                    0x1460000

// UART
#define UART0_BASE                   0x21C0500
#define UART0_IT                     86
#define UART0_LENGTH                 0x100
#define SPCR_FLOW_CONTROL_NONE       0

// Timer
#define TIMER_BLOCK_COUNT            1
#define TIMER_FRAME_COUNT            4
#define TIMER_WATCHDOG_COUNT         1
#define TIMER_BASE_ADDRESS           0x23E0000 // a.k.a CNTControlBase
#define TIMER_READ_BASE_ADDRESS      0x23F0000 // a.k.a CNTReadBase
#define TIMER_SEC_IT                 29
#define TIMER_NON_SEC_IT             30
#define TIMER_VIRT_IT                27
#define TIMER_HYP_IT                 26
#define TIMER_FRAME0_IT              78
#define TIMER_FRAME1_IT              79
#define TIMER_FRAME2_IT              92

// Mcfg
#define LS1046A_PCI_SEG0_CONFIG_BASE 0x4000000000
#define LS1046A_PCI_SEG0             0x0
#define LS1046A_PCI_SEG_BUSNUM_MIN   0x0
#define LS1046A_PCI_SEG_BUSNUM_MAX   0xff
#define LS1046A_PCI_SEG1_CONFIG_BASE 0x4800000000
#define LS1046A_PCI_SEG2_CONFIG_BASE 0x5000000000
#define LS1046A_PCI_SEG1             0x1
#define LS1046A_PCI_SEG2             0x2

// Platform specific info needed by Configuration Manager

#define CFG_MGR_TABLE_ID  SIGNATURE_64 ('L','S','1','0','4','6',' ',' ')

#define OEM_ACPI_TABLES   1 // OEM defined DSDT

#define PLAT_PCI_SEG0               LS1046A_PCI_SEG0
#define PLAT_PCI_SEG1_CONFIG_BASE   LS1046A_PCI_SEG1_CONFIG_BASE
#define PLAT_PCI_SEG1               LS1046A_PCI_SEG1
#define PLAT_PCI_SEG_BUSNUM_MIN     LS1046A_PCI_SEG_BUSNUM_MIN
#define PLAT_PCI_SEG_BUSNUM_MAX     LS1046A_PCI_SEG_BUSNUM_MAX
#define PLAT_PCI_SEG2_CONFIG_BASE   LS1046A_PCI_SEG2_CONFIG_BASE
#define PLAT_PCI_SEG2               LS1046A_PCI_SEG2

#define PLAT_GIC_VERSION            GIC_VERSION
#define PLAT_GICD_BASE              GICD_BASE
#define PLAT_GICI_BASE              GICI_BASE
#define PLAT_GICR_BASE              GICR_BASE
#define PLAT_GICR_LEN               GICR_LEN
#define PLAT_GICC_BASE              GICC_BASE
#define PLAT_GICH_BASE              GICH_BASE
#define PLAT_GICV_BASE              GICV_BASE

#define PLAT_CPU_COUNT              4
#define PLAT_GTBLOCK_COUNT          0
#define PLAT_GTFRAME_COUNT          0
#define PLAT_PCI_CONFG_COUNT        2

#define PLAT_WATCHDOG_COUNT           0
#define PLAT_GIC_REDISTRIBUTOR_COUNT  0
#define PLAT_GIC_ITS_COUNT            0

/* GIC CPU Interface information
   GIC_ENTRY (CPUInterfaceNumber, Mpidr, PmuIrq, VGicIrq, EnergyEfficiency)
 */
#define PLAT_GIC_CPU_INTERFACE    {                          \
             GICC_ENTRY (0,  GET_MPID (0, 0), 138, 0x19, 0), \
             GICC_ENTRY (1,  GET_MPID (0, 1), 139, 0x19, 0), \
             GICC_ENTRY (2,  GET_MPID (0, 2), 127, 0x19, 0), \
             GICC_ENTRY (3,  GET_MPID (0, 3), 129, 0x19, 0), \
}

#define PLAT_WATCHDOG_INFO                    \
  {                                           \
  }                                           \

#define PLAT_TIMER_BLOCK_INFO                 \
  {                                           \
  }                                           \

#define PLAT_TIMER_FRAME_INFO                 \
  {                                           \
  }                                           \

#define PLAT_GIC_DISTRIBUTOR_INFO                                      \
  {                                                                    \
    PLAT_GICD_BASE,                  /* UINT64  PhysicalBaseAddress */ \
    0,                               /* UINT32  SystemVectorBase */    \
    PLAT_GIC_VERSION                 /* UINT8   GicVersion */          \
  }                                                                    \

#define PLAT_GIC_REDISTRIBUTOR_INFO                                    \
  {                                                                    \
  }                                                                    \

#define PLAT_GIC_ITS_INFO                                              \
  {                                                                    \
  }                                                                    \

#define PLAT_MCFG_INFO                \
  {                                   \
    {                                 \
      PLAT_PCI_SEG1_CONFIG_BASE,      \
      PLAT_PCI_SEG1,                  \
      PLAT_PCI_SEG_BUSNUM_MIN,        \
      PLAT_PCI_SEG_BUSNUM_MAX,        \
    },                                \
    {                                 \
      PLAT_PCI_SEG2_CONFIG_BASE,      \
      PLAT_PCI_SEG2,                  \
      PLAT_PCI_SEG_BUSNUM_MIN,        \
      PLAT_PCI_SEG_BUSNUM_MAX,        \
    }                                 \
  }                                   \

#define PLAT_SPCR_INFO                                                            \
  {                                                                               \
    UART0_BASE,                                                                   \
    UART0_IT,                                                                     \
    115200,                                                                       \
    0,                                                                            \
    EFI_ACPI_SERIAL_PORT_CONSOLE_REDIRECTION_TABLE_INTERFACE_TYPE_16550           \
  }                                                                               \

#endif // LS1046AFRWY_PLATFORM_H
