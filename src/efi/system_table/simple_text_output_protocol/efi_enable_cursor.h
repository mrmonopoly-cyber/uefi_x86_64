#pragma once

#include "external_def.h"

typedef enum
{
  EFI_STATUS_EFI_TEXT_ENABLE_CURSOR_EFI_SUCCESS, //INFO: The operation completed successfully.
  EFI_STATUS_EFI_TEXT_ENABLE_CURSOR_EFI_DEVICE_ERROR, //INFO:The device had an error and could not complete the request or the device does not support changing the cursor mode.
  EFI_STATUS_EFI_TEXT_ENABLE_CURSOR_EFI_UNSUPPORTED, //INFO: The output device does not support visibility control of the cursor.
}EFI_STATUS_EFI_TEXT_ENABLE_CURSOR;
typedef EFI_STATUS_EFI_TEXT_ENABLE_CURSOR (*EFI_TEXT_ENABLE_CURSOR) (
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    BOOLEAN Visible);
