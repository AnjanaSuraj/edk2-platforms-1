#  LS1046aFrwyPkg.dsc
#
#  LS1046AFRWY Board package.
#
#  Copyright 2019-2020 NXP
#  Copyright 2021 Puresoftware Ltd
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  #
  # Defines for default states.  These can be changed on the command line.
  # -D FLAG=VALUE
  #
  PLATFORM_NAME                  = LS1046aFrwyPkg
  PLATFORM_GUID                  = 79adaa48-5f50-49f0-aa9a-544ac9260ef8
  OUTPUT_DIRECTORY               = Build/LS1046aFrwyPkg
  FLASH_DEFINITION               = Platform/NXP/LS1046aFrwyPkg/LS1046aFrwyPkg.fdf

  # This flag controls the dynamic acpi generation
  #
  DEFINE DYNAMIC_ACPI_ENABLE     = TRUE

!include Silicon/NXP/NxpQoriqLs.dsc.inc
!include MdePkg/MdeLibs.dsc.inc
!include Silicon/NXP/LS1046A/LS1046A.dsc.inc

!if $(DYNAMIC_ACPI_ENABLE) == TRUE
  !include DynamicTablesPkg/DynamicTables.dsc.inc
!endif

[LibraryClasses.common]
  ArmPlatformLib|Platform/NXP/LS1046aFrwyPkg/Library/ArmPlatformLib/ArmPlatformLib.inf
  RealTimeClockLib|EmbeddedPkg/Library/VirtualRealTimeClockLib/VirtualRealTimeClockLib.inf

################################################################################
#
# Components Section - list of all EDK II Modules needed by this Platform
#
################################################################################
[Components.common]
  #
  # Architectural Protocols
  #
  MdeModulePkg/Universal/Variable/RuntimeDxe/VariableRuntimeDxe.inf {
    <PcdsFixedAtBuild>
    gEfiMdeModulePkgTokenSpaceGuid.PcdEmuVariableNvModeEnable|TRUE
  }

  Silicon/NXP/Drivers/UsbHcdInitDxe/UsbHcd.inf

  #
  # Dynamic Table Factory
  !if $(DYNAMIC_ACPI_ENABLE) == TRUE
    DynamicTablesPkg/Drivers/DynamicTableFactoryDxe/DynamicTableFactoryDxe.inf {
      <LibraryClasses>
        NULL|DynamicTablesPkg/Library/Acpi/Arm/AcpiFadtLibArm/AcpiFadtLibArm.inf
        NULL|DynamicTablesPkg/Library/Acpi/Arm/AcpiGtdtLibArm/AcpiGtdtLibArm.inf
        NULL|DynamicTablesPkg/Library/Acpi/Arm/AcpiMadtLibArm/AcpiMadtLibArm.inf
        NULL|DynamicTablesPkg/Library/Acpi/Arm/AcpiMcfgLibArm/AcpiMcfgLibArm.inf
        NULL|DynamicTablesPkg/Library/Acpi/Arm/AcpiSpcrLibArm/AcpiSpcrLibArm.inf
    }
  !endif

  #
  # Acpi Support
  #
  MdeModulePkg/Universal/Acpi/AcpiPlatformDxe/AcpiPlatformDxe.inf
  MdeModulePkg/Universal/Acpi/AcpiTableDxe/AcpiTableDxe.inf

##
