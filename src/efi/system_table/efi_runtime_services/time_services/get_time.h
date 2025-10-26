#pragma once

#include "time_def.h"

//******************************************************
// EFI_TIME_CAPABILITIES
//******************************************************
// This provides the capabilities of the
// real time clock device as exposed through the EFI
typedef struct {
  UINT32 Resolution;
  UINT32 Accuracy;
  BOOLEAN SetsToZero;
}EFI_TIME_CAPABILITIES;


typedef enum
{
  EFI_STATUS_EFI_GET_TIME_EFI_SUCCESS, //INFO: The operation completed successfully.
  EFI_STATUS_EFI_GET_TIME_EFI_INVALID_PARAMETER, //INFO: Time is NULL.
  EFI_STATUS_EFI_GET_TIME_EFI_DEVICE_ERROR, //INFO: The time could not be retrieved due to a hardware error.
}EFI_STATUS_EFI_GET_TIME;
typedef EFI_STATUS_EFI_GET_TIME(*EFI_GET_TIME) (EFI_TIME *Time, EFI_TIME_CAPABILITIES *Capabilities);

