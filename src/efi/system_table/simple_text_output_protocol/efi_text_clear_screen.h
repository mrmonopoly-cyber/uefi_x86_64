#pragma once

#include "external_def.h"

typedef enum
{
 EFI_STATUS_EFI_TEXT_CLEAR_SCREEN_EFI_SUCCESS, //INFO: The operation completed successfully.
 EFI_STATUS_EFI_TEXT_CLEAR_SCREEN_EFI_DEVICE_ERROR, //INFO: The device had an error and could not complete the request.
 EFI_STATUS_EFI_TEXT_CLEAR_SCREEN_EFI_UNSUPPORTED, //INFO: The output device is not in a valid text mode.
}EFI_STATUS_EFI_TEXT_CLEAR_SCREEN;

typedef EFI_STATUS_EFI_TEXT_CLEAR_SCREEN(*EFI_TEXT_CLEAR_SCREEN) (
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
