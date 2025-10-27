#pragma once

#include "external_def.h"

typedef enum
{
  EFI_STATUS_EFI_TEXT_QUERY_MODE_EFI_SUCCESS, //INFO: The requested mode information was returned.
  EFI_STATUS_EFI_TEXT_QUERY_MODE_EFI_DEVICE_ERROR, //INFO: The device had an error and could not complete the request.
  EFI_STATUS_EFI_TEXT_QUERY_MODE_EFI_UNSUPPORTED, //INFO: The mode number was not valid.
}EFI_STATUS_EFI_TEXT_QUERY_MODE;

typedef EFI_STATUS_EFI_TEXT_QUERY_MODE (*EFI_TEXT_QUERY_MODE)(
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    UINTN ModeNumber,
    UINTN *Columns,
    UINTN *Rows);
