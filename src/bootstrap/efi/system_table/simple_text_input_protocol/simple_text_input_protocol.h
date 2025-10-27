#pragma once

//INFO: Simple Text Input Protocol, Section 12.3

#include "../../basic_data_types.h"

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID \
{0x387477c1,0x69c7,0x11d2,\
{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

//******************************************************
// EFI_INPUT_KEY
//******************************************************
typedef struct {
  UINT16 ScanCode;
  CHAR16 UnicodeChar;
} EFI_INPUT_KEY;

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

typedef enum
{
  EFI_STATUS_EFI_INPUT_RESET_EFI_SUCCESS, //INFO: The device was reset.
  EFI_STATUS_EFI_INPUT_RESET_EFI_DEVICE_ERROR, //INFO: The device is not functioning correctly and could not be reset.
}EFI_STATUS_EFI_INPUT_RESET;
typedef EFI_STATUS_EFI_INPUT_RESET (*EFI_INPUT_RESET) (EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, BOOLEAN ExtendedVerification);


typedef enum
{
 EFI_STATUS_EFI_INPUT_READ_KEY_EFI_SUCCESS, //INFO: The keystroke information was returned.
 EFI_STATUS_EFI_INPUT_READ_KEY_EFI_NOT_READY, //INFO: There was no keystroke data available.
 EFI_STATUS_EFI_INPUT_READ_KEY_EFI_DEVICE_ERROR, //INFO: The keystroke information was not returned due to hardware errors.
 EFI_STATUS_EFI_INPUT_READ_KEY_EFI_UNSUPPORTED, //INFO: The device does not support the ability to read keystroke data.
}EFI_STATUS_EFI_INPUT_READ_KEY;
typedef EFI_STATUS (*EFI_INPUT_READ_KEY) (EFI_SIMPLE_TEXT_INPUT_PROTOCOL *This, EFI_INPUT_KEY *Key);

typedef struct _EFI_SIMPLE_TEXT_INPUT_PROTOCOL {
  EFI_INPUT_RESET Reset;
  EFI_INPUT_READ_KEY ReadKeyStroke;
  EFI_EVENT WaitForKey;
} EFI_SIMPLE_TEXT_INPUT_PROTOCOL;

