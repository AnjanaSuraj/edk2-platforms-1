/** @file
  Differentiated System Description Table Fields (DSDT)

  Copyright 2021 NXP
  Copyright 2021 Puresoftware Ltd.

  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include "Platform.h"

DefinitionBlock("DsdtTable.aml", "DSDT", 2, "NXP  ", "LS1046  ", EFI_ACPI_ARM_OEM_REVISION) {
  include ("Clk.asl")
}
