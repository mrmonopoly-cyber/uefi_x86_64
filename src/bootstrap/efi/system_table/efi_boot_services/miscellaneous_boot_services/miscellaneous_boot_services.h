#pragma once

//INFO: Miscellaneous Boot Services, Section 7.5

#include "../../../basic_data_types.h"

typedef enum
{
  EFI_STATUS_EFI_SET_WATCHDOG_TIMER_EFI_SUCCESS, //INFO: The timeout has been set.
  EFI_STATUS_EFI_SET_WATCHDOG_TIMER_EFI_INVALID_PARAMETER, //INFO: The supplied WatchdogCode is invalid.
  EFI_STATUS_EFI_SET_WATCHDOG_TIMER_EFI_UNSUPPORTED, //INFO: The system does not have a watchdog timer.
  EFI_STATUS_EFI_SET_WATCHDOG_TIMER_EFI_DEVICE_ERROR, //INFO: The watch dog timer could not be programmed due to a hardware error.
}EFI_STATUS_EFI_SET_WATCHDOG_TIMER ;
typedef EFI_STATUS_EFI_SET_WATCHDOG_TIMER(*EFI_SET_WATCHDOG_TIMER) (
    UINTN Timeout,
    UINT64 WatchdogCode,
    UINTN DataSize,
    CHAR16 *WatchdogData);

typedef enum
{
  EFI_STATUS_EFI_STALL_EFI_SUCCESS, //INFO: Execution was stalled at least the requested number of Microseconds.
}EFI_STATUS_EFI_STALL;
typedef EFI_STATUS_EFI_STALL(*EFI_STALL) (UINTN Microseconds);

typedef VOID (*EFI_COPY_MEM) (VOID *Destination, VOID *Source, UINTN Length);

typedef VOID (*EFI_SET_MEM) (VOID *Buffer, UINTN Size, UINT8 Value);

typedef enum
{
  EFI_STATUS_EFI_GET_NEXT_MONOTONIC_COUNT_EFI_SUCCESS, //INFO: The next monotonic count was returned.
  EFI_STATUS_EFI_GET_NEXT_MONOTONIC_COUNT_EFI_DEVICE_ERROR, //INFO: The device is not functioning properly.
  EFI_STATUS_EFI_GET_NEXT_MONOTONIC_COUNT_EFI_INVALID_PARAMETER, //INFO: Count is NULL.
}EFI_STATUS_EFI_GET_NEXT_MONOTONIC_COUNT;
typedef EFI_STATUS_EFI_GET_NEXT_MONOTONIC_COUNT(*EFI_GET_NEXT_MONOTONIC_COUNT) (UINT64 *Count);

typedef enum
{
  EFI_STATUS_EFI_INSTALL_CONFIGURATION_TABLE_EFI_SUCCESS, //INFO: The (Guid, Table) pair was added, updated, or removed.
  EFI_STATUS_EFI_INSTALL_CONFIGURATION_TABLE_EFI_INVALID_PARAMETER, //INFO: Guid is NULL.
  EFI_STATUS_EFI_INSTALL_CONFIGURATION_TABLE_EFI_NOT_FOUND, //INFO: An attempt was made to delete a nonexistent entry.
  EFI_STATUS_EFI_INSTALL_CONFIGURATION_TABLE_EFI_OUT_OF_RESOURCES, //INFO: There is not enough memory available to complete the operation.
}EFI_STATUS_EFI_INSTALL_CONFIGURATION_TABLE;
typedef EFI_STATUS_EFI_INSTALL_CONFIGURATION_TABLE(*EFI_INSTALL_CONFIGURATION_TABLE) (EFI_GUID *Guid, VOID *Table);

typedef enum
{
 EFI_STATUS_EFI_CALCULATE_CRC32_EFI_SUCCESS, //INFO: The 32-bit CRC was computed for the data buffer and returned in Crc32.
 EFI_STATUS_EFI_CALCULATE_CRC32_EFI_INVALID_PARAMETER, //INFO: Data is NULL.| Crc32 is NULL. | DataSize is 0.
}EFI_STATUS_EFI_CALCULATE_CRC32;
typedef EFI_STATUS_EFI_CALCULATE_CRC32(*EFI_CALCULATE_CRC32)(
    VOID *Data,
    UINTN DataSize,
    UINT32 *Crc32);

