#pragma once

#include "external_def.h"

//*******************************************************
// Attributes
//*******************************************************
#define EFI_BLACK 0x00
#define EFI_BLUE 0x01
#define EFI_GREEN 0x02
#define EFI_CYAN 0x03
#define EFI_RED 0x04
#define EFI_MAGENTA 0x05
#define EFI_BROWN 0x06
#define EFI_LIGHTGRAY 0x07
#define EFI_BRIGHT 0x08
#define EFI_DARKGRAY 0x08 //(EFI_BLACK \| EFI_BRIGHT)
#define EFI_LIGHTBLUE 0x09
#define EFI_LIGHTGREEN 0x0A
#define EFI_LIGHTCYAN 0x0B
#define EFI_LIGHTRED 0x0C
#define EFI_LIGHTMAGENTA 0x0D
#define EFI_YELLOW 0x0E
#define EFI_WHITE 0x0F
#define EFI_BACKGROUND_BLACK 0x00
#define EFI_BACKGROUND_BLUE 0x10
#define EFI_BACKGROUND_GREEN 0x20
#define EFI_BACKGROUND_CYAN 0x30
#define EFI_BACKGROUND_RED 0x40
#define EFI_BACKGROUND_MAGENTA 0x50
#define EFI_BACKGROUND_BROWN 0x60
#define EFI_BACKGROUND_LIGHTGRAY 0x70
//
// Macro to accept color values in their raw form to create
// a value that represents both a foreground and background
// color in a single byte.
// For Foreground, and EFI_\* value is valid from EFI_BLACK(0x00)
// to EFI_WHITE (0x0F).
// For Background, only EFI_BLACK, EFI_BLUE, EFI_GREEN,
// EFI_CYAN, EFI_RED, EFI_MAGENTA, EFI_BROWN, and EFI_LIGHTGRAY
// are acceptable.
//
// Do not use EFI_BACKGROUND_xxx values with this macro.
#define EFI_TEXT_ATTR(Foreground,Background) \
((Foreground) | ((Background) << 4))

typedef enum
{
  EFI_STATUS_EFI_TEXT_SET_ATTRIBUTE_EFI_SUCCESS, //INFO: The requested attributes were set.
  EFI_STATUS_EFI_TEXT_SET_ATTRIBUTE_EFI_DEVICE_ERROR, //INFO: The device had an error and could not complete the request.
}EFI_STATUS_EFI_TEXT_SET_ATTRIBUTE;

typedef
EFI_STATUS_EFI_TEXT_SET_ATTRIBUTE (*EFI_TEXT_SET_ATTRIBUTE) (
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    UINTN Attribute);
