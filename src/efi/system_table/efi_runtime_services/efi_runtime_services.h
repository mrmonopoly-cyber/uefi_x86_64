#pragma once

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

#include "../../basic_data_types.h"

#include "time_services/time_services.h"
#include "virtual_memory_services/virtual_memory_services.h"
#include "variable_services/variable_services.h"
#include "miscellaneous_services/miscellaneous_services.h"

typedef struct {
EFI_TABLE_HEADER Hdr;

//
// Time Services
//
EFI_GET_TIME GetTime;
EFI_SET_TIME SetTime;
EFI_GET_WAKEUP_TIME GetWakeupTime;
EFI_SET_WAKEUP_TIME SetWakeupTime;

//
// Virtual Memory Services
//
EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
EFI_CONVERT_POINTER ConvertPointer;

//
// Variable Services
//
EFI_GET_VARIABLE GetVariable;
EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
EFI_SET_VARIABLE SetVariable;

//
// Miscellaneous Services
//
EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
EFI_RESET_SYSTEM ResetSystem;

//
// UEFI 2.0 Capsule Services
//
EFI_UPDATE_CAPSULE UpdateCapsule;
EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;

//
// Miscellaneous UEFI 2.0 Service
//
EFI_QUERY_VARIABLE_INFO QueryVariableInfo;

}EFI_RUNTIME_SERVICES;
