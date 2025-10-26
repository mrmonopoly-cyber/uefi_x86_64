#pragma once

#include "../../../../basic_data_types.h"
#include "capsule_types.h"

typedef enum
{
  EFI_STATUS_EFI_UPDATE_CAPSULE_EFI_SUCCESS, /* //INFO:
                * Valid capsule was passed. If CAPSULE_FLAGS_PERSIST_ACROSS_RESET is not set, 
                * the capsule has been successfully processed by the firmware.
                */
 EFI_STATUS_EFI_UPDATE_CAPSULE_EFI_INVALID_PARAMETER, //INFO: CapsuleSize, or an incompatible set of flags were set in the capsule header. | CapsuleCount is 0
 EFI_STATUS_EFI_UPDATE_CAPSULE_EFI_DEVICE_ERROR, //INFO: The capsule update was started, but failed due to a device error.
 EFI_STATUS_EFI_UPDATE_CAPSULE_EFI_UNSUPPORTED, //INFO: The capsule type is not supported on this platform.
 EFI_STATUS_EFI_UPDATE_CAPSULE_EFI_OUT_OF_RESOURCES, /* //INFO:
                        *
                        * When ExitBootServices() has been previously called this error indicates the
                        * capsule is compatible with this platform but is not capable of being submit-
                        * ted or processed in runtime. The caller may resubmit the capsule prior to
                        * ExitBootServices().
                        * |
                        * When ExitBootServices() has not been previously called then this error in-
                        * dicates the capsule is compatible with this platform but there are insufficient
                        * resources to process.
                        * |
                        * This call is not supported by this platform at the time the call is made. The
                        * platform should describe this runtime service as unsupported at runtime via
                        * an EFI_RT_PROPERTIES_TABLE configuration table.
                        */
}EFI_STATUS_EFI_UPDATE_CAPSULE;
typedef EFI_STATUS_EFI_UPDATE_CAPSULE (*EFI_UPDATE_CAPSULE) (
    EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    UINTN CapsuleCount,
    EFI_PHYSICAL_ADDRESS ScatterGatherList);
