#pragma once
//INFO: UEFI specs, Release 2.11
//INFO: EFI Table Header, Section 4.2

#include "basic_data_types.h"

typedef struct {
  UINT64 Signature;
  UINT32 Revision;
  UINT32 HeaderSize;
  UINT32 CRC32;
  UINT32 Reserved;
} EFI_TABLE_HEADER;
