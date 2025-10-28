#include <stddef.h>

#include "efi/efi.h"

typedef enum
{
 EFI_STATUS_MAIN_EFI_SUCCES,
 EFI_STATUS_MAIN_EFI_OUT_OF_RESOURCES,
}EFI_STATUS_MAIN;
EFI_STATUS_MAIN EfiMain (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  EFI_STATUS err =0;

  EFI_HANDLE kernel_handle = NULL;
  EFI_DEVICE_PATH_PROTOCOL kernel_path ={0};

  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut = SystemTable->ConOut;

    CHAR16 unicode_alive_string[128] = {};
    CHAR8 alive_string[] =  "bootloader alive mex\n\r";
    alive_string[2]+=err;
    for (UINT8 i=0; i<sizeof(alive_string); i++)
    {
      unicode_alive_string[(2*i)+1] = alive_string[i];
    }

  ConOut->OutputString(ConOut,unicode_alive_string);

  if((err=SystemTable->BootServices->LoadImage(
        TRUE,
        ImageHandle,
        &kernel_path,
        NULL,
        0,
        &kernel_handle))!=0)
  {
    CHAR16 unicode_err_string[128] = {};
    CHAR8 err_string[] =  "error loading image: 0";
    err_string[2]+=err;
    for (UINT8 i=0; i<sizeof(err_string); i++)
    {
      unicode_err_string[2*i] = err_string[i];
    }
    ConOut->OutputString(ConOut,unicode_err_string);
  }

  return EFI_STATUS_MAIN_EFI_SUCCES; 
}
