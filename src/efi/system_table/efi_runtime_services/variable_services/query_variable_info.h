#pragma once

#include "../../../basic_data_types.h"

typedef enum
{
 EFI_STATUS_EFI_QUERY_VARIABLE_INFO_EFI_SUCCESS, //INFO: Valid answer returned.
 EFI_STATUS_EFI_QUERY_VARIABLE_INFO_EFI_INVALID_PARAMETER, //INFO: An invalid combination of attribute bits was supplied
 EFI_STATUS_EFI_QUERY_VARIABLE_INFO_EFI_UNSUPPORTED, /* //INFO:
                                                      * The attribute is not supported on this platform, and the
                                                      * MaximumVariableStorageSize,
                                                      * RemainingVariableStorageSize,
                                                      * MaximumVariableSize are undefined.
                                                      */
}EFI_STATUS_EFI_QUERY_VARIABLE_INFO;
typedef EFI_STATUS (*EFI_QUERY_VARIABLE_INFO) (
    UINT32 Attributes,
    UINT64 *MaximumVariableStorageSize,
    UINT64 *RemainingVariableStorageSize,
    UINT64 *MaximumVariableSize
    );
