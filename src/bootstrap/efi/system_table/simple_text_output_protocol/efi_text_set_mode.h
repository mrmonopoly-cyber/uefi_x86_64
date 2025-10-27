#pragma once

#include "external_def.h"

typedef enum
{
  EFI_STATUS_EFI_TEXT_SET_MODE_EFI_SUCCESS, //INFO: The requested text mode was set.
  EFI_STATUS_EFI_TEXT_SET_MODE_EFI_DEVICE_ERROR, //INFO: The device had an error and could not complete the request.
  EFI_STATUS_EFI_TEXT_SET_MODE_EFI_UNSUPPORTED, //INFO: The mode number was not valid.
}EFI_STATUS_EFI_TEXT_SET_MODE;
typedef EFI_STATUS_EFI_TEXT_SET_MODE (*EFI_TEXT_SET_MODE) (
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    UINTN ModeNumber);
