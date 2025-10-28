#include <stddef.h>

#include "efi/efi.h"
#include "util/util.h"

typedef enum
{
 EFI_STATUS_MAIN_EFI_SUCCES,
 EFI_STATUS_MAIN_EFI_OUT_OF_RESOURCES,
}EFI_STATUS_MAIN;
EFI_STATUS_MAIN EfiMain (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  EFI_STATUS err =0;

  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut = SystemTable->ConOut;

  CHAR8 alive_mex[] = "bootloader alive\n\r";
  CHAR16 outchar[16] = {0};

  if(conv_str_u8_u16(alive_mex, outchar,sizeof(alive_mex))!=S_U8_TO_U16_SUCCESS)
  {
    CHAR16 err_conv[] = {'K','K','\n','\r','\0'};
    ConOut->OutputString(ConOut,err_conv);
  }

  if((err+=ConOut->OutputString(ConOut,outchar))!=EFI_STATUS_EFI_TEXT_STRING_EFI_SUCCESS)
  {
    CHAR16 err_conv[] = {0};
    CHAR8 err_str[] =  "error alive mex\n\r";
    conv_str_u8_u16(err_str, err_conv, sizeof(err_str));
    ConOut->OutputString(ConOut,err_conv);
  }

  LOOP(ConOut);

  return EFI_STATUS_MAIN_EFI_SUCCES; 
}
