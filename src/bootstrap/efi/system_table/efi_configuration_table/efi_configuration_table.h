#pragma once

//INFO: EFI Configuration Table & Properties Table, Section 4.6

#include "../../basic_data_types.h"

typedef struct{
  EFI_GUID VendorGuid;
  VOID *VendorTable;
}EFI_CONFIGURATION_TABLE;
