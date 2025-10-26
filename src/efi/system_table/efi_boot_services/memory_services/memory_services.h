#pragma once

#include "../../../basic_data_types.h"
#include "memory_types.h"


typedef enum
{
 EFI_STATUS_EFI_ALLOCATE_PAGES_EFI_SUCCESS, //INFO: The requested pages were allocated.
 EFI_STATUS_EFI_ALLOCATE_PAGES_EFI_OUT_OF_RESOURCEST, //INFO: The pages could not be allocated.
 EFI_STATUS_EFI_ALLOCATE_PAGES_EFI_INVALID_PARAMETER,/* //INFO:
                                                      * Type is not AllocateAnyPages or AllocateMaxAddress or AllocateAddress
                                                      * |
                                                      * MemoryType is in the range EfiMaxMemoryType..0x6FFFFFFF.
                                                      * |
                                                      * MemoryType is EfiPersistentMemoryType or EfiUnacceptedMemory.
                                                      * |
                                                      * Memory is NULL.
                                                      */
 EFI_STATUS_EFI_ALLOCATE_PAGES_EFI_NOT_FOUND, //INFO: The requested pages could not be found.
}EFI_STATUS_EFI_ALLOCATE_PAGES;
typedef EFI_STATUS_EFI_ALLOCATE_PAGES(*EFI_ALLOCATE_PAGES) (EFI_ALLOCATE_TYPE Type,
    EFI_MEMORY_TYPE MemoryType,
    UINTN Pages,
    EFI_PHYSICAL_ADDRESS *Memory);

typedef enum
{
 EFI_STATUS_EFI_FREE_PAGES_EFFI_SUCCESS, //INFO: The requested memory pages were freed
 EFI_STATUS_EFI_FREE_PAGES_EFI_NOT_FOUND, //INFO: The requested memory pages were not allocated with AllocatePages().
 EFI_STATUS_EFI_FREE_PAGES_EFI_INVALID_PARAMETER, //INFO: Memory is not a page-aligned address or Pages is invalid.
}EFI_STATUS_EFI_FREE_PAGES;
typedef EFI_STATUS_EFI_FREE_PAGES(*EFI_FREE_PAGES) (EFI_PHYSICAL_ADDRESS Memory, UINTN Pages);

typedef enum
{
  EFI_STATUS_EFI_GET_MEMORY_MAP_EFI_SUCCESS, //INFO: The memory map was returned in the MemoryMap buffer.
  EFI_STATUS_EFI_GET_MEMORY_MAP_EFI_BUFFER_TOO_SMALL, //INFO: The MemoryMap buffer was too small. Thecurrent buffer size needed to hold the memory map is returned in MemoryMapSize.
  EFI_STATUS_EFI_GET_MEMORY_MAP_EFI_INVALID_PARAMETER, //INFO: MemoryMapSize is NULL. | The MemoryMap buffer is not too small and MemoryMap is NULL.
}EFI_STATUS_EFI_GET_MEMORY_MAP;
typedef EFI_STATUS_EFI_GET_MEMORY_MAP (*EFI_GET_MEMORY_MAP) (UINTN *MemoryMapSize,
    EFI_MEMORY_DESCRIPTOR *MemoryMap,
    UINTN *MapKey,
    UINTN *DescriptorSize,
    UINT32 *DescriptorVersion);

typedef enum
{
 EFI_STATUS_EFI_ALLOCATE_POOL_EFI_SUCCESS, //INFO: The requested number of bytes was allocated.
 EFI_STATUS_EFI_ALLOCATE_POOL_EFI_OUT_OF_RESOURCES /* INFO:
                                                    * The pool requested could not be allocated.
                                                    * |
                                                    * PoolType is in the range EfiMaxMemoryType..0x6FFFFFFF.
                                                    * |
                                                    * PoolType is EfiPersistentMemory.
                                                    * |
                                                    * Buffer is NULL.
                                                    */
}EFI_STATUS_EFI_ALLOCATE_POOL;
typedef EFI_STATUS_EFI_ALLOCATE_POOL(*EFI_ALLOCATE_POOL) (EFI_MEMORY_TYPE PoolType,
    UINTN Size,
    VOID **Buffer);


typedef enum
{
 EFI_STATUS_EFI_FREE_POOL_EFI_SUCCESS, //INFO: The memory was returned to the system.
 EFI_STATUS_EFI_FREE_POOL_EFI_INVALID_PARAMETER //INFO: Buffer was invalid.
}EFI_STATUS_EFI_FREE_POOL;
typedef EFI_STATUS_EFI_FREE_POOL(*EFI_FREE_POOL) (VOID *Buffer);
