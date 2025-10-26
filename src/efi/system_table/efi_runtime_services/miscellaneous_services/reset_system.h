#pragma once

#include "../../../basic_data_types.h"

//******************************************************
// EFI_RESET_TYPE
//******************************************************
typedef enum {
  EfiResetCold,
  EfiResetWarm,
  EfiResetShutdown,
  EfiResetPlatformSpecific,
}EFI_RESET_TYPE;

typedef VOID (*EFI_RESET_SYSTEM) (
    EFI_RESET_TYPE ResetType,
    EFI_STATUS ResetStatus,
    UINTN DataSize,
    VOID *ResetData);
