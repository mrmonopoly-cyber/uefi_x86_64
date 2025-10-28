#pragma once

#include "../efi/efi.h"


typedef enum
{
  S_U8_TO_U16_SUCCESS,
  S_U8_TO_U16_ERROR_PARAMETER, //INFO: 
}S_U8_TO_U16;
S_U8_TO_U16 conv_str_u8_u16(const CHAR8* const src, CHAR16* const dst, const UINT8 len);

#define LOOP(CONOUT) \
  CHAR16 loop_mex[] = {'I','N','F','I','N','I','T','E',' ','L','O','O','P','\n','\r','\0'}; \
  CONOUT->OutputString(CONOUT,loop_mex); \
  while (1){}
