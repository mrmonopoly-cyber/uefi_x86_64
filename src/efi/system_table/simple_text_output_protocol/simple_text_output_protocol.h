#pragma once

//INFO: Simple Text Output Protocol, Section 12.4

#include "external_def.h"
#include "efi_status_text_string.h"
#include "efi_text_test_string.h"
#include "efi_text_reset.h"
#include "efi_text_query_mode.h"
#include "efi_text_set_mode.h"
#include "efi_text_set_attribute.h"
#include "efi_text_clear_screen.h"
#include "efi_text_set_cursor_position.h"
#include "efi_enable_cursor.h"

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID \
{0x387477c2,0x69c7,0x11d2,\
{0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}


//******************************************************
// SIMPLE_TEXT_OUTPUT_MODE
//******************************************************
typedef struct {
  INT32 MaxMode;
  // current settings
  INT32 Mode;
  INT32 Attribute;
  INT32 CursorColumn;
  INT32 CursorRow;
  BOOLEAN CursorVisible;
} SIMPLE_TEXT_OUTPUT_MODE;

typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
EFI_TEXT_RESET Reset;
EFI_TEXT_STRING OutputString;
EFI_TEXT_TEST_STRING TestString;
EFI_TEXT_QUERY_MODE QueryMode;
EFI_TEXT_SET_MODE SetMode;
EFI_TEXT_SET_ATTRIBUTE SetAttribute;
EFI_TEXT_CLEAR_SCREEN ClearScreen;
EFI_TEXT_SET_CURSOR_POSITION SetCursorPosition;
EFI_TEXT_ENABLE_CURSOR EnableCursor;
SIMPLE_TEXT_OUTPUT_MODE *Mode;
}EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;



