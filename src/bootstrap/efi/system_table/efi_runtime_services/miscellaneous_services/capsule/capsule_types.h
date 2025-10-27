#pragma once

#include "../../../../basic_data_types.h"
#include "../../../efi_boot_services/memory_services/memory_types.h"

typedef struct {
  UINT32 CapsuleArrayNumber;
  VOID* CapsulePtr[1];
} EFI_CAPSULE_TABLE;

//INFO: CapsuleImageSize
#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

typedef struct {
  EFI_GUID CapsuleGuid;
  UINT32 HeaderSize;
  UINT32 Flags;
  UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;


typedef struct {
  UINT64 Length;
  union {
    EFI_PHYSICAL_ADDRESS DataBlock;
    EFI_PHYSICAL_ADDRESS ContinuationPointer;
  }Union;
} EFI_CAPSULE_BLOCK_DESCRIPTOR;
