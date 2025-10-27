#pragma once

#define EXCLUDE_EFI_GUID
#include "../../../basic_data_types.h"

//******************************************************
//EFI_HANDLE
//******************************************************
typedef VOID *EFI_HANDLE;

//******************************************************
//EFI_INTERFACE_TYPE
//******************************************************
typedef enum {
EFI_NATIVE_INTERFACE
} EFI_INTERFACE_TYPE;

//******************************************************
// EFI_LOCATE_SEARCH_TYPE
//******************************************************
typedef enum {
AllHandles,
ByRegisterNotify,
ByProtocol
} EFI_LOCATE_SEARCH_TYPE;

typedef struct {
  EFI_HANDLE AgentHandle;
  EFI_HANDLE ControllerHandle;
  UINT32 Attributes;
  UINT32 OpenCount;
} EFI_OPEN_PROTOCOL_INFORMATION_ENTRY;
