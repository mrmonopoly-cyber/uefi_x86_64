#pragma once

#include "../../../../basic_data_types.h"
#include "../reset_system.h"
#include "capsule_types.h"

typedef enum
{
 EFI_STATUS_EFI_QUERY_CAPSULE_CAPABILITIES_EFI_SUCCESS, //INFO: Valid answer returned.
 EFI_STATUS_EFI_QUERY_CAPSULE_CAPABILITIES_EFI_INVALID_PARAMETER, //INFO: MaximumCapsuleSize is NULL.
 EFI_STATUS_EFI_QUERY_CAPSULE_CAPABILITIES_EFI_UNSUPPORTED, /* //INFO:
                     * The capsule type is not supported on this platform, and 
                     * MaximumCapsule- Size and ResetType are undefined.
                     * |
                     * This call is not supported by this platform at the time the call is made. The
                     * platform should describe this runtime service as unsupported at runtime via
                     * an EFI_RT_PROPERTIES_TABLE configuration table.
                     */
  EFI_STATUS_EFI_QUERY_CAPSULE_CAPABILITIES_EFI_OUT_OF_RESOURCES, /* //INFO:
                        * When ExitBootServices() has been previously called this error indicates the
                        * capsule is compatible with this platform but is not capable of being submit-
                        * ted or processed in runtime. The caller may resubmit the capsule prior to
                        * ExitBootServices().
                        * |
                        * When ExitBootServices() has not been previously called then this error in-
                        * dicates the capsule is compatible with this platform but there are insufficient
                        * resources to process.
                        */
}EFI_STATUS_EFI_QUERY_CAPSULE_CAPABILITIES;

typedef EFI_STATUS_EFI_QUERY_CAPSULE_CAPABILITIES(*EFI_QUERY_CAPSULE_CAPABILITIES) (
    EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    UINTN CapsuleCount,
    UINT64 *MaximumCapsuleSize,
    EFI_RESET_TYPE *ResetType);
