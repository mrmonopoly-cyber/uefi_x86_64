#pragma once

#include "time_def.h"

typedef enum
{
  EFI_STATUS_EFI_SET_TIME_EFI_SUCCESS, //INFO: The operation completed successfully.
  EFI_STATUS_EFI_SET_TIME_EFI_INVALID_PARAMETER, //INFO: Time is NULL.
  EFI_STATUS_EFI_SET_TIME_EFI_DEVICE_ERROR, //INFO: The time could not be retrieved due to a hardware error.
}EFI_STATUS_EFI_SET_TIME;
typedef EFI_STATUS_EFI_SET_TIME(*EFI_SET_TIME) (EFI_TIME *Time);

