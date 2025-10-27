#pragma once

#include "external_def.h"

typedef enum
{
  EFI_STATUS_EFI_TEXT_RESET_EFI_SUCCESS, //INFO: The text output device was reset.
  EFI_STATUS_EFI_TEXT_RESET_EFI_DEVICE_ERROR //INFO: The text output device is not functioning correctly and could not be reset.
}EFI_STATUS_EFI_TEXT_RESET;
typedef EFI_STATUS_EFI_TEXT_RESET (*EFI_TEXT_RESET) (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,BOOLEAN ExtendedVerification);
