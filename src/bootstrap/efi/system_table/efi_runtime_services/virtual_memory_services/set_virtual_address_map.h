#pragma once

#include "../../../basic_data_types.h"
#include "../../efi_boot_services/memory_services/memory_types.h"

//INFO:  EFI_MEMORY_DESCRIPTOR defined in EFI_BOOT_SERVICES.GetMemoryMap()

typedef enum
{
 EFI_STATUS_EFI_SET_VIRTUAL_ADDRESS_MAP_EFI_SUCCESS, //INFO: The virtual address map has been applied.
 EFI_STATUS_EFI_SET_VIRTUAL_ADDRESS_MAP_EFI_UNSUPPORTED, //INFO: EFI firmware is not at runtime, or the EFI firmware is already in virtual address mapped mode. | This call is not supported by this platform at the time the call is made. The platform should describe this runtime service as unsupported at runtime via an EFI_RT_PROPERTIES_TABLE configuration table.
 EFI_STATUS_EFI_SET_VIRTUAL_ADDRESS_MAP_EFI_INVALID_PARAMETER, //INFO: DescriptorSize or DescriptorVersion is invalid
 EFI_STATUS_EFI_SET_VIRTUAL_ADDRESS_MAP_EFI_NO_MAPPING, //INFO: A virtual address was not supplied for a range in the memory map that requires a mapping.
 EFI_STATUS_EFI_SET_VIRTUAL_ADDRESS_MAP_EFI_NOT_FOUND, //INFO: A virtual address was supplied for an address that is not found in the memory map.
}EFI_STATUS_EFI_SET_VIRTUAL_ADDRESS_MAP;

typedef EFI_STATUS_EFI_SET_VIRTUAL_ADDRESS_MAP (*EFI_SET_VIRTUAL_ADDRESS_MAP) (
    UINTN jMemoryMapSize,
    UINTN DescriptorSize,
    UINT32 DescriptorVersion,
    EFI_MEMORY_DESCRIPTOR *VirtualMap
    );
