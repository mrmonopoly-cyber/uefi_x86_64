#pragma once

#include "external_def.h"

typedef enum
{
  EFI_STATUS_EFI_TEXT_TEST_STRING_EFI_SUCCESS, //INFO: The device(s) are capable of rendering the output string.
  EFI_STATUS_EFI_TEXT_TEST_STRING_EFI_STATUS_EFI_TEXT_TEST_STRING_, //INFO: Some of the characters in the string cannot be rendered by one or more of the output devices mapped by the EFI handle.
}EFI_STATUS_EFI_TEXT_TEST_STRING;
typedef
EFI_STATUS_EFI_TEXT_TEST_STRING (*EFI_TEXT_TEST_STRING) (EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This, CHAR16 *String);
