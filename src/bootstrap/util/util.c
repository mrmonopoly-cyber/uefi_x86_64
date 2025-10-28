#include "util.h"

S_U8_TO_U16 conv_str_u8_u16(const CHAR8* const src, CHAR16* const dst, const UINT8 len)
{
  if (!src || !dst)
  {
    return S_U8_TO_U16_ERROR_PARAMETER;
  }

  int i=0;
  for (; i<len; i++)
  {
    dst[i] = src[i];
  }

  return S_U8_TO_U16_SUCCESS;
}
