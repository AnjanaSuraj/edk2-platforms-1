/** SerDes.c
  Provides SoC specific SerDes interface

  Copyright 2017-2020 NXP

  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/ChassisLib.h>
#include <Library/DebugLib.h>
#include <Library/SerDesHelperLib.h>
#include <SocSerDes.h>
#include <Soc.h>
#include <Uefi.h>

// SerDes1 Protocol Mask in Reset Configuration Word (RCW) Status Register
#define SERDES1_PROTOCOL_MASK      0xffff0000

// SerDes1 Protocol Shift in Reset Configuration Word (RCW) Status Register
#define SERDES1_PROTOCOL_SHIFT     16

// SerDes2 Protocol Mask in Reset Configuration Word (RCW) Status Register
#define SERDES2_PROTOCOL_MASK     0x0000ffff

// SerDes2 Protocol Shift in Reset Configuration Word (RCW) Status Register
#define SERDES2_PROTOCOL_SHIFT    0

STATIC SERDES_CONFIG mSerDes1ConfigTable[] = {
        /* SerDes 1 */
        {0x3333, {SGMII_FM1_DTSEC9, SGMII_FM1_DTSEC10, SGMII_FM1_DTSEC5, SGMII_FM1_DTSEC6 } },
        {0x1133, {XFI_FM1_MAC9, XFI_FM1_MAC10, SGMII_FM1_DTSEC5, SGMII_FM1_DTSEC6 } },
        {0x1333, {XFI_FM1_MAC9, SGMII_FM1_DTSEC10, SGMII_FM1_DTSEC5, SGMII_FM1_DTSEC6 } },
        {0x2333, {SGMII_2500_FM1_DTSEC9, SGMII_FM1_DTSEC10, SGMII_FM1_DTSEC5, SGMII_FM1_DTSEC6 } },
        {0x2233, {SGMII_2500_FM1_DTSEC9, SGMII_2500_FM1_DTSEC10, SGMII_FM1_DTSEC5, SGMII_FM1_DTSEC6 } },
        {0x1040, {XFI_FM1_MAC9, NONE, QSGMII_FM1_A, NONE } },
        {0x2040, {SGMII_2500_FM1_DTSEC9, NONE, QSGMII_FM1_A, NONE } },
        {0x1163, {XFI_FM1_MAC9, XFI_FM1_MAC10, PCIE1, SGMII_FM1_DTSEC6 } },
        {0x2263, {SGMII_2500_FM1_DTSEC9, SGMII_2500_FM1_DTSEC10, PCIE1, SGMII_FM1_DTSEC6 } },
        {0x3363, {SGMII_FM1_DTSEC5, SGMII_FM1_DTSEC6, PCIE1, SGMII_FM1_DTSEC6 } },
        {0x2223, {SGMII_2500_FM1_DTSEC9, SGMII_2500_FM1_DTSEC10, SGMII_2500_FM1_DTSEC5, SGMII_FM1_DTSEC6 } },
        {0x3040, {SGMII_FM1_DTSEC9, NONE, QSGMII_FM1_A, NONE } },
        {}
};

STATIC SERDES_CONFIG mSerDes2ConfigTable[] = {
        /* SerDes 2 */
        {0x8888, {PCIE1, PCIE1, PCIE1, PCIE1 } },
        {0x5559, {PCIE1, PCIE2, PCIE3, SATA } },
        {0x5577, {PCIE1, PCIE2, PCIE3, PCIE3 } },
        {0x5506, {PCIE1, PCIE2, NONE, PCIE3 } },
        {0x0506, {NONE, PCIE2, NONE, PCIE3 } },
        {0x0559, {NONE, PCIE2, PCIE3, SATA } },
        {0x5A59, {PCIE1, SGMII_FM1_DTSEC2, PCIE3, SATA } },
        {0x5A06, {PCIE1, SGMII_FM1_DTSEC2, NONE, PCIE3 } },
        {}
};

SERDES_CONFIG *gSerDesConfig[] = {
  mSerDes1ConfigTable,
  mSerDes2ConfigTable
};

/**
  Probe all SerDes for lane protocol and execute provided callback function.

  @param  SerDesLaneProbeCallback Pointer Callback function to be called for Lane protocol
  @param  Arg                     Pointer to Arguments to be passed to callback function.

**/
VOID
SerDesProbeLanes (
  IN SERDES_PROBE_LANES_CALLBACK SerDesLaneProbeCallback,
  IN VOID                        *Arg
  )
{
  UINT32                 SerDesProtocol;
  LS1046A_DEVICE_CONFIG  *DeviceConfig;

  DeviceConfig = (LS1046A_DEVICE_CONFIG  *)LS1046A_DCFG_ADDRESS;
  SerDesProtocol = DcfgRead32 ((UINTN)&DeviceConfig->RcwSr[4]) & SERDES1_PROTOCOL_MASK;
  SerDesProtocol >>= SERDES1_PROTOCOL_SHIFT;

  SerDesInstanceProbeLanes (
    SERDES_1,
    SerDesProtocol,
    FixedPcdGet8 (PcdSerDesLanes),
    SERDES_PROTOCOL_COUNT,
    gSerDesConfig[SERDES_1],
    SerDesLaneProbeCallback,
    Arg
    );

  SerDesProtocol = DcfgRead32 ((UINTN)&DeviceConfig->RcwSr[4]) & SERDES2_PROTOCOL_MASK;
  SerDesProtocol >>= SERDES2_PROTOCOL_SHIFT;

  SerDesInstanceProbeLanes (
    SERDES_2,
    SerDesProtocol,
    FixedPcdGet8 (PcdSerDesLanes),
    SERDES_PROTOCOL_COUNT,
    gSerDesConfig[SERDES_2],
    SerDesLaneProbeCallback,
    Arg
    );
}

/**
  Function to return SerDes protocol map for all SerDes available on board.

  @param  SerDesProtocolMap   Pointer to SerDes protocl map.

**/
VOID
GetSerDesProtocolMap (
  OUT UINT64   *SerDesProtocolMap
  )
{
  UINT32                 SerDesProtocol;
  LS1046A_DEVICE_CONFIG  *DeviceConfig;
  EFI_STATUS             Status;

  *SerDesProtocolMap = 0;
  DeviceConfig = (LS1046A_DEVICE_CONFIG  *)LS1046A_DCFG_ADDRESS;
  SerDesProtocol = DcfgRead32 ((UINTN)&DeviceConfig->RcwSr[4]) & SERDES1_PROTOCOL_MASK;
  SerDesProtocol >>= SERDES1_PROTOCOL_SHIFT;

  Status = GetSerDesMap (
             SERDES_1,
             SerDesProtocol,
             FixedPcdGet8 (PcdSerDesLanes),
             SERDES_PROTOCOL_COUNT,
             gSerDesConfig[SERDES_1],
             SerDesProtocolMap
             );

  if (Status != EFI_SUCCESS) {
    DEBUG ((DEBUG_ERROR, "%a: failed for SerDes1 \n",__FUNCTION__));
    *SerDesProtocolMap = 0;
  }

  SerDesProtocol = DcfgRead32 ((UINTN)&DeviceConfig->RcwSr[4]) & SERDES2_PROTOCOL_MASK;
  SerDesProtocol >>= SERDES2_PROTOCOL_SHIFT;

  Status = GetSerDesMap (
             SERDES_2,
             SerDesProtocol,
             FixedPcdGet8 (PcdSerDesLanes),
             SERDES_PROTOCOL_COUNT,
             gSerDesConfig[SERDES_2],
             SerDesProtocolMap
             );

  if (Status != EFI_SUCCESS) {
    DEBUG ((DEBUG_ERROR, "%a: failed for SerDes2 \n",__FUNCTION__));
    *SerDesProtocolMap = 0;
  }
}
