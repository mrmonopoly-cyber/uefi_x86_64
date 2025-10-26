#pragma once

#include "../../../basic_data_types.h"

typedef enum
{
 EFI_STATUS_EFI_GET_NEXT_HIGH_MONOTONIC_COUNT_EFI_SUCCESS, //INFO: The next high monotonic count was returned.
 EFI_STATUS_EFI_GET_NEXT_HIGH_MONOTONIC_COUNT_EFI_DEVICE_ERROR, //INFO: The device is not functioning properly.
 EFI_STATUS_EFI_GET_NEXT_HIGH_MONOTONIC_COUNT_EFI_INVALID_PARAMETER, //INFO: HighCount is NULL.
 EFI_STATUS_EFI_GET_NEXT_HIGH_MONOTONIC_COUNT_EFI_UNSUPPORTED, /* //INFO: 
                    * This call is not supported by this platform at the time the call is made. 
                    * The platform should describe this runtime service as unsupported at runtime via
                    * an EFI_RT_PROPERTIES_TABLE configuration table.
                    */
}EFI_STATUS_EFI_GET_NEXT_HIGH_MONOTONIC_COUNT;

typedef EFI_STATUS_EFI_GET_NEXT_HIGH_MONOTONIC_COUNT (*EFI_GET_NEXT_HIGH_MONO_COUNT)(
    UINT32 *HighCount);
